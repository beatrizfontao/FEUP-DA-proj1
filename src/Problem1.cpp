#include "Problems.h"

bool deliveryVanSort(const DeliveryVan &a, const DeliveryVan &b) {
    return (a.getMaxVolume() > b.getMaxVolume()) && (a.getMaxWeight() > b.getMaxWeight());
}

bool deliveryPackageSort(const DeliveryPackage &a, const DeliveryPackage &b) {
    return (a.getPackageVolume() < b.getPackageVolume()) && (a.getPackageWeight() < b.getPackageWeight());
}

vector<DeliveryVan> deliveryVanMinimization(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    vector<DeliveryVan> deliveryVans = vans;
    vector<DeliveryPackage> deliveryPackages = packages;
    sort(deliveryVans.begin(), deliveryVans.end(), deliveryVanSort); // sorting the vans (decrease)
    sort(deliveryPackages.begin(), deliveryPackages.end(), deliveryPackageSort);
    return distributePackages(deliveryVans, deliveryPackages);
}

vector<DeliveryVan> distributePackages(vector<DeliveryVan> &vans, vector<DeliveryPackage> &deliveryPackages) {
    vector<DeliveryPackage> packages = deliveryPackages;
    vector<pair<int, int>> auxVans; // vector with the weight and volume of each van, the values will decrease according to the packages
    vector<DeliveryVan> res;
    auxVans.reserve(vans.size());
    for (auto van: vans) {
        auxVans.emplace_back(van.getMaxWeight(), van.getMaxVolume());
    }
    for (auto package: packages) {
        for (size_t i = 0; i < auxVans.size(); i++) {
            if (auxVans[i].first >= package.getPackageWeight() && auxVans[i].second >=
                                                                  package.getPackageVolume()) {// if the package can fit inside the van then we decrease the respective values by the weight and volume of the package
                if (find(res.begin(), res.end(), vans[i]) == res.end()) {
                    res.insert(res.begin(),
                               vans[i]); // if the DeliveryVan is not found then we add it to the res vector
                }
                auxVans[i].first -= package.getPackageWeight();
                auxVans[i].second -= package.getPackageVolume();
                break;
            }
        }
    }

    return res;
}

void drawMinimizationOfVans(vector<DeliveryVan> deliveryVans, vector<DeliveryPackage> deliveryPackages) {
    vector<DeliveryVan> deliveryVanMinimized = deliveryVanMinimization(deliveryVans, deliveryPackages);

    cout << "-----------------------------PROBLEM 1-----------------------------\n";
    cout << "                  MINIMIZATION OF VANS - 1st option:                \n" << endl;

    cout << "Numero de carrinhas necessarias 1: " << deliveryVanMinimized.size() << endl << endl;
}

//=======================================================================================================================================

vector<DeliveryVan> minimizeVans(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    vector<DeliveryVan> deliveryVans = vans, res;
    vector<DeliveryPackage> deliveryPackages = packages;

    //Sorting the vans by delivery cost
    sort(deliveryVans.begin(), deliveryVans.end(), deliveryVanSort);
    sort(deliveryPackages.begin(), deliveryPackages.end(), sortPackagesByVolume);

    //Fill each van one by one
    vector<pair<int, int>> auxVans; // vector with the weight and volume of each van, the values will decrease according to the packages
    setAuxVans(auxVans, deliveryVans);

    bool sortedByWeight = false, full;
    for (int vanNr = 0; vanNr < deliveryVans.size(); vanNr++) {
        if (deliveryPackages.empty())
            break;
        full = false;
        while (!full) {
            if (auxVans[vanNr].first == 0 || auxVans[vanNr].second == 0 || deliveryPackages.empty())
                break;
            else if (auxVans[vanNr].first < auxVans[vanNr].second && !sortedByWeight) {
                sort(deliveryPackages.begin(), deliveryPackages.end(), sortPackagesByWeight);
                sortedByWeight = true;
            } else if (auxVans[vanNr].first >= auxVans[vanNr].second && sortedByWeight) {
                sort(deliveryPackages.begin(), deliveryPackages.end(), sortPackagesByVolume);
                sortedByWeight = false;
            }
            full = place_Package(deliveryPackages, deliveryVans, res, auxVans, vanNr);
        }
    }
    return res;
}

bool sort_PackagesByWeight(DeliveryPackage A, DeliveryPackage B) {
    if (A.getPackageWeight() == B.getPackageWeight())
        return A.getPackageVolume() < B.getPackageVolume();
    return A.getPackageWeight() < B.getPackageWeight();
}

bool sort_PackagesByVolume(DeliveryPackage A, DeliveryPackage B) {
    if (A.getPackageVolume() == B.getPackageVolume())
        return A.getPackageWeight() < B.getPackageWeight();
    return A.getPackageVolume() < B.getPackageVolume();
}

bool
place_Package(vector<DeliveryPackage> &deliveryPackages, vector<DeliveryVan> &deliveryVans, vector<DeliveryVan> &res,
              vector<pair<int, int>> &auxVans, int vanNr) {
    bool full = true;
    auto it = deliveryPackages.begin();
    while (it != deliveryPackages.end()) {
        if (it->getPackageWeight() <= auxVans[vanNr].first && it->getPackageVolume() <= auxVans[vanNr].second) {
            if (find(res.begin(), res.end(), deliveryVans[vanNr]) == res.end()) {
                res.emplace_back(deliveryVans[vanNr]); // if the van is not found then we add it to the res vector
            }
            auxVans[vanNr].first -= it->getPackageWeight();
            auxVans[vanNr].second -= it->getPackageVolume();
            full = false;
            deliveryPackages.erase(it);
            break;
        } else it++;
    }
    return full;
}

void drawMinimizationOfVans_2nd(vector<DeliveryVan> deliveryVans, vector<DeliveryPackage> deliveryPackages) {

    cout << "--------------------------------------------------------------------\n";
    cout << "                  MINIMIZATION OF VANS - 2nd option:                \n" << endl;

    vector<DeliveryVan> minVans = minimizeVans(deliveryVans, deliveryPackages);

    cout << "Numero de carrinhas necessarias: " << minVans.size() << "\n";

}
