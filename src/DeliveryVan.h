#ifndef PROJ1_DELIVERYVAN_H
#define PROJ1_DELIVERYVAN_H

#include <iostream>

using namespace std;

class DeliveryVan {
private:
    int maxVolume;
    int maxWeight;
    int deliveryCost;

public:
    DeliveryVan();
    DeliveryVan(int maxVolume, int maxWeight, int deliveryCost);

    int getMaxVolume() const;
    void setMaxVolume(const int maxVolume);

    int getMaxWeight() const;
    void setMaxWeight(const int maxWeight);

    int getDeliveryCost() const;
    void setDeliveryCost(const int deliveryCost);

    bool operator==(const DeliveryVan& deliveryVan) const;
};


#endif
