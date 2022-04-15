#include "problem2.h"

void sortPackagesByVolume(vector<DeliveryPackage> &deliveryPackages);

void sortPackagesByWeight(vector<DeliveryPackage> &deliveryPackages);

void cap(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    int max = 0, cap = 0;
    for (int j = 0; j <= 2000; j += 10) {
        vector<pair<int, int>> auxVans;
        vector<DeliveryVan> res;
        int good = 0, cost = 0;
        for (auto van: vans) {
            auxVans.emplace_back(van.getMaxWeight(), van.getMaxVolume());
        }
        for (auto package: packages) {
            if (package.getValue() < j) continue;
            for (size_t i = 0; i < auxVans.size(); i++) {
                if (auxVans[i].first >= package.getPackageWeight() && auxVans[i].second >= package.getPackageVolume()) {
                    // if the package can fit inside the van then we decrease the respective values by the weight and volume of the package
                    if (find(res.begin(), res.end(), vans[i]) == res.end()) {
                        res.emplace_back(vans[i]); // if the DeliveryVan is not found then we add it to the res vector
                        cost += vans[i].getDeliveryCost();
                    }
                    auxVans[i].first -= package.getPackageWeight();
                    auxVans[i].second -= package.getPackageVolume();
                    good += package.getValue();
                    break;
                }
            }
        }
        if (max < (good - cost)) {
            max = (good - cost);
            cap = j;
        }
    }
}


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

    bool sortedByWeight = false, empty;
    int vanNr = 0, cost = 0, reward = 0;
    for (auto van: deliveryVans) {
        if(deliveryPackages.empty())
            break;
        empty = false;
        while (!empty) {
            if (auxVans[vanNr].first == 0 || auxVans[vanNr].second == 0 || deliveryPackages.empty())
                break;
            else if (auxVans[vanNr].first < auxVans[vanNr].second) {
                if (!sortedByWeight) {
                    sortPackagesByWeight(deliveryPackages);
                    sortedByWeight = true;
                }
                empty = placePackage(deliveryPackages, deliveryVans, res, auxVans, vanNr, cost, reward);
            }
            else if (auxVans[vanNr].first >= auxVans[vanNr].second) {
                if (sortedByWeight) {
                    sortPackagesByVolume(deliveryPackages);
                    sortedByWeight = false;
                }
                empty = placePackage(deliveryPackages, deliveryVans, res, auxVans, vanNr, cost, reward);
            }
        }
        vanNr++;
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
             vector<pair<int, int>> &auxVans, int vanNr, int &cost, int &reward) {
    bool empty = true;
    vector<DeliveryPackage>::iterator it;
    for (it = deliveryPackages.begin(); it != deliveryPackages.end(); it++) {
        if(it->getValue() < 654) {
            it = deliveryPackages.erase(it);
            it--; //isto está super scketchy
        }
        if (it->getPackageWeight() <= auxVans[vanNr].first && it->getPackageVolume() <= auxVans[vanNr].second) {
            if (find(res.begin(), res.end(), deliveryVans[vanNr]) == res.end()) {
                res.emplace_back(
                        deliveryVans[vanNr]); // if the DeliveryVan is not found then we add it to the res vector
            }
            auxVans[vanNr].first -= it->getPackageWeight();
            auxVans[vanNr].second -= it->getPackageVolume();
            reward += it->getValue();
            empty = false;
            deliveryPackages.erase(it);
            break;
        }
    }

    return empty;
}
