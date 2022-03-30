#ifndef PROJ1_COURIER_H
#define PROJ1_COURIER_H

#include <iostream>

using namespace std;

class Courier {
private:
    string licensePlate;
    double maxVolume;
    double maxWeight;
    double deliveryCost;

public:
    Courier();
    Courier(string licensePlate, double maxVolume, double maxWeight, double deliveryCost);

    string getLicensePlate() const;
    void setLicensePlate(const string licensePlate);

    double getMaxVolume() const;
    void setMaxVolume(const double maxVolume);

    double getMaxWeight() const;
    void setMaxWeight(const double maxWeight);

    double getDeliveryCost() const;
    void setDeliveryCost(const double deliveryCost);
};


#endif
