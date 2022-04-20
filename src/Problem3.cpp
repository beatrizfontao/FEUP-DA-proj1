#include "Problems.h"

vector<DeliveryPackage> expressOrder(vector<DeliveryPackage> d) {
    sort(d.begin(), d.end(), sortByTime);

    vector<DeliveryPackage> res;
    int totalTime = 0;
    int deliveryInd = 0;
    while(totalTime < 28800){
        totalTime += d[deliveryInd].getDeliveryTime();
        deliveryInd++;
        res.push_back(d[deliveryInd]);
    }
    return res;
}

bool sortByTime(DeliveryPackage A, DeliveryPackage B) {
    return A.getDeliveryTime() > B.getDeliveryTime();
}

void drawExpress(vector<DeliveryPackage> d) {
    vector<DeliveryPackage> expressDelivery = expressOrder(d);
    double sumTime = 0;
    for(auto x: expressDelivery){
        sumTime += x.getDeliveryTime();
    }
    cout << "Media de tempo por encomenda(em segundos):" << sumTime/expressDelivery.size() << endl << endl;
}