#ifndef PROJ1_COURIER_H
#define PROJ1_COURIER_H

#include <iostream>

using namespace std;

class Courier {
private:
    int maxVolume;
    int maxWeight;
    int deliveryCost;

public:
    Courier();
    Courier(int maxVolume, int maxWeight, int deliveryCost);

    int getMaxVolume() const;
    void setMaxVolume(const int maxVolume);

    int getMaxWeight() const;
    void setMaxWeight(const int maxWeight);

    int getDeliveryCost() const;
    void setDeliveryCost(const int deliveryCost);
};


#endif
