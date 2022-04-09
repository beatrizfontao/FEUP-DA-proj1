#include "problem1.h"


void swap(DeliveryPackage *a, DeliveryPackage *b)
{
    DeliveryPackage temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort function
void bubbleSort(vector<DeliveryPackage>& vect)
{
    int i, j;
    for (i = 0; i < vect.size()-1; i++) {
        for (j = 0; j < vect.size() - i - 1; j++) {
            if (!(vect[j] < vect[j + 1]))
                swap(&vect[j], &vect[j + 1]);
        }
    }
}


vector<DeliveryVan> deliveryVanMinimization(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    vector<DeliveryVan> deliveryVans = vans;
    vector<DeliveryPackage> deliveryPackages = packages;
    sort(deliveryVans.begin(), deliveryVans.end(), greater<>()); // sorting the vans (decrease)
    /*
    cout << "organized vans : " << endl;
    for(auto v : deliveryVans){
        cout << "VOLMAX : " << v.getMaxVolume() << endl;
        cout << "PESOMAX : " << v.getMaxWeight() << endl << endl;
    }
    cout << endl;
     */
    vector<DeliveryVan> firstFitDecreasingVans = distributePackages(deliveryVans, packages);
    return firstFitDecreasingVans;
}

vector<DeliveryVan> distributePackages(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &deliveryPackages) {
    vector<DeliveryPackage> packages = deliveryPackages;
    //sort(packages.begin(), packages.end()); // sorting the packages (increase)
    bubbleSort(packages);
    /*
    cout << "organized packages : " << endl;

    for(auto p : packages){
        cout << "VOLUME : " << p.getPackageVolume() << endl;
        cout << "PESO : " << p.getPackageWeight() << endl << endl;
    }
    cout << endl;
*/
    vector<pair<int, int>> auxVans; // vector with the weight and volume of each van, the values will decrease according to the packages
    vector<DeliveryVan> res;

    for (auto van: vans) {
        auxVans.emplace_back(van.getMaxWeight(), van.getMaxVolume());
    }

    for (auto package: packages) {
        for (size_t i = 0; i < auxVans.size(); i++) {
            if (auxVans[i].first > package.getPackageWeight() && auxVans[i].second > package.getPackageVolume()) {
                // if the package can fit inside the van then we decrease the respective values by the weight and volume of the package
                if (find(res.begin(), res.end(), vans[i]) == res.end()) {
                    res.push_back(vans[i]); // if the DeliveryVan is not found then we add it to the res vector
                    cout << "VOLMAX : " << vans[i].getMaxVolume() << endl;
                    cout << "PESOMAX : " << vans[i].getMaxWeight() << endl;
                    cout << endl;
                }
                auxVans[i].first -= package.getPackageWeight();
                auxVans[i].second -= package.getPackageVolume();
                cout << "encomenda : " << endl;
                cout << "VOLUME : " << deliveryPackages[i].getPackageVolume() << endl;
                cout << "PESO : " << deliveryPackages[i].getPackageWeight() << endl << endl;
                break;
            }
        }
    }

    return res;
}

/*
int lowerBound(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    int maxWeight = 0, maxVolume = 0;
    int weightNeeded = 0, volumeNeeded = 0;
    for (auto van: vans) {
        maxWeight += van.getMaxWeight();
        maxVolume += van.getMaxVolume();
    }
    for (auto package: packages) {
        weightNeeded += package.getPackageWeight();
        volumeNeeded += package.getPackageVolume();
    }
    if (maxWeight < weightNeeded || maxVolume < volumeNeeded)
        return (int) vans.size();
    else {
        return min(maxWeight / weightNeeded, maxVolume / volumeNeeded);
    }
}

vector<DeliveryVan> firstFit(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    vector<pair<int, int>> auxVans;
    vector<DeliveryVan> res;
    for (auto van: vans) {
        auxVans.emplace_back(van.getMaxWeight(), van.getMaxVolume());
    }
    for (auto package: packages) {
        for (size_t i = 0; i < auxVans.size(); i++) {
            if (auxVans[i].first > package.getPackageWeight() && auxVans[i].second > package.getPackageVolume()) {
                auxVans[i].first -= package.getPackageWeight();
                auxVans[i].second -= package.getPackageVolume();
                if (find(res.begin(), res.end(), vans[i]) == res.end())
                    res.push_back(vans[i]);
            }
        }
    }
    return res;
}


    int aux = lowerBound(deliveryVans, packages);
    vector<DeliveryVan> firstFitVans = firstFit(deliveryVans, packages);
    if(firstFitVans.size() == aux)
        return firstFitVans;
        */
