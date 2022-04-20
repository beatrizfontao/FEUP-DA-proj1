//
// Created by Alexandre on 4/14/2022.
//

#include <algorithm>
#include "Express.h"

Express::Express() = default;

vector<DeliveryPackage> Express::expressOrder(vector<DeliveryPackage> d) {
    sort(d.begin(), d.end(), comparison);

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

bool Express::comparison(DeliveryPackage a, DeliveryPackage b) {
    return a.getDeliveryTime() > b.getDeliveryTime();
}

void Express::drawExpress(vector<DeliveryPackage> d) {
    vector<DeliveryPackage> expressDelivery = expressOrder(d);
    double sumTime = 0;
    for(auto x: expressDelivery){
        sumTime += x.getDeliveryTime();
    }
    cout << "Media do tempo por encomenda(em segundos):" << sumTime/expressDelivery.size() << endl << endl;
}
