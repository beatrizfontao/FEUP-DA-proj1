#include "problem2.h"

void sortPackagesByVolume(vector<DeliveryPackage> &deliveryPackages);

void sortPackagesByWeight(vector<DeliveryPackage> &deliveryPackages);

pair<vector<DeliveryVan>, int> fill(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    vector<DeliveryVan> deliveryVans = vans;
    vector<DeliveryPackage> deliveryPackages = packages;

    //Sorting the vans by delivery cost
    sort(deliveryVans.begin(), deliveryVans.end(), [](DeliveryVan A, DeliveryVan B) {
        if(A.getDeliveryCost() == B.getDeliveryCost())
            return (A.getMaxWeight() > B.getMaxWeight() && A.getMaxVolume() > B.getMaxVolume());
        return A.getDeliveryCost() < B.getDeliveryCost();
        return (A.getMaxWeight() > B.getMaxWeight() && A.getMaxVolume() > B.getMaxVolume());
    });

    sortPackagesByVolume(deliveryPackages);

    //Fill each van one by one

    vector<pair<int, int>> auxVans; // vector with the weight and volume of each van, the values will decrease according to the packages
    vector<DeliveryVan> res;

    auxVans.reserve(deliveryVans.size());
    for (auto van: deliveryVans) {
        auxVans.emplace_back(van.getMaxWeight(), van.getMaxVolume());
    }

    bool sortedByWeight = false, full;
    int cost = 0, reward = 0;
    for (int vanNr = 0; vanNr < deliveryVans.size(); vanNr++) {
        if(deliveryPackages.empty())
            break;
        full = false;
        while (!full) {
            if (auxVans[vanNr].first == 0 || auxVans[vanNr].second == 0 || deliveryPackages.empty())
                break;
            else if (auxVans[vanNr].first < auxVans[vanNr].second) {
                if (!sortedByWeight) {
                    sortPackagesByWeight(deliveryPackages);
                    sortedByWeight = true;
                }
                full = placePackage(deliveryPackages, deliveryVans, res, auxVans, vanNr, reward);
            }
            else if (auxVans[vanNr].first >= auxVans[vanNr].second) {
                if (sortedByWeight) {
                    sortPackagesByVolume(deliveryPackages);
                    sortedByWeight = false;
                }
                full = placePackage(deliveryPackages, deliveryVans, res, auxVans, vanNr, reward);
            }
        }
    }

    return make_pair(res, reward);
}

void sortPackagesByWeight(vector<DeliveryPackage> &deliveryPackages) {
    sort(deliveryPackages.begin(), deliveryPackages.end(), [](DeliveryPackage A, DeliveryPackage B) {
        if( A.getPackageWeight() == B.getPackageWeight())
            return A.getPackageVolume() < B.getPackageVolume();
        return A.getPackageWeight() < B.getPackageWeight();
    });
}

void sortPackagesByVolume(vector<DeliveryPackage> &deliveryPackages) {
    sort(deliveryPackages.begin(), deliveryPackages.end(), [](DeliveryPackage A, DeliveryPackage B) {
        if(A.getPackageVolume() == B.getPackageVolume())
            return A.getPackageWeight() < B.getPackageWeight();
        return A.getPackageVolume() < B.getPackageVolume();
    });
}

bool placePackage(vector<DeliveryPackage> &deliveryPackages, vector<DeliveryVan> &deliveryVans, vector<DeliveryVan> &res,
             vector<pair<int, int>> &auxVans, int vanNr, int &reward) {
    bool full = true;
    vector<DeliveryPackage>::iterator it;
    for (it = deliveryPackages.begin(); it != deliveryPackages.end(); it++) {
        if(it->getValue() < 654) {
            it = deliveryPackages.erase(it);
            it--; //isto está super scketchy
        }
        if (it->getPackageWeight() <= auxVans[vanNr].first && it->getPackageVolume() <= auxVans[vanNr].second) {
            if (find(res.begin(), res.end(), deliveryVans[vanNr]) == res.end()) {
                res.emplace_back(deliveryVans[vanNr]); // if the DeliveryVan is not found then we add it to the res vector
            }
            auxVans[vanNr].first -= it->getPackageWeight();
            auxVans[vanNr].second -= it->getPackageVolume();
            reward += it->getValue();
            full = false;
            deliveryPackages.erase(it);
            break;
        }
    }

    return full;
}
