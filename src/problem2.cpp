#include "problem2.h"

void preparation(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages) {
    vector<DeliveryVan> deliveryVans = vans;
    vector<DeliveryPackage> deliveryPackages = packages;
    sort(deliveryVans.begin(), deliveryVans.end()); // sorting the vans (decrease)

    cout << "Organized vans : " << endl;
    for(auto v : deliveryVans){
        cout << "VOLMAX : " << v.getMaxVolume() << endl;
        cout << "PESOMAX : " << v.getMaxWeight() << endl;
        cout << "COST: " << v.getDeliveryCost() << "\n\n";
    }
    cout << endl;

    sort(deliveryPackages.begin(), deliveryPackages.end());

    cout << '\n' << "ENCOMENDAS" << endl;
    for(auto d : deliveryPackages){
        cout << "VOLUME : " << d.getPackageVolume() << endl;
        cout << "PESO : " << d.getPackageWeight() << endl;
        cout << "RECOMPENSA : " << d.getValue() << "\n\n";
        cout << endl;
    }
}

vector<DeliveryVan> fill(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages){
    vector<DeliveryVan> deliveryVans = vans;
    vector<DeliveryPackage> deliveryPackages = packages;
    sort(deliveryVans.begin(), deliveryVans.end());
    sort(deliveryPackages.begin(), deliveryPackages.end());




};

void printInfo(){}