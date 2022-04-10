#ifndef PROJ1_DELIVERYPACKAGE_H
#define PROJ1_DELIVERYPACKAGE_H

#include <iostream>

using namespace std;

class DeliveryPackage {
private:
    int packageWeight;
    int packageVolume;
    int value;
    int deliveryTime;
    bool used;

public:
    DeliveryPackage();
    DeliveryPackage(int packageWeight, int packageVolume, int value, int deliveryTime, bool used = false);

    int getPackageWeight() const;
    void setPackageWeight(const int packageWeight);

    int getPackageVolume() const;
    void setPackageVolume(const int packageVolume);

    int getValue() const;
    void setValue(const int value);

    int getDeliveryTime() const;
    void setDeliveryTime(const int deliveryTime);

    bool operator<(const DeliveryPackage& deliveryPackage) const;
};


#endif