#ifndef PROJ1_DELIVERYPACKAGE_H
#define PROJ1_DELIVERYPACKAGE_H

#include <iostream>

using namespace std;

class DeliveryPackage {
private:
    string type;
    double packageWeight;
    double packageVolume;
    double value;
    int deliveryTime;

public:
    DeliveryPackage();
    DeliveryPackage(string type, double packageWeight, double packageVolume, double value, int deliveryTime);

    string getType() const;
    void setType(const string type);

    double getPackageWeight() const;
    void setPackageWeight(const double packageWeight);

    double getPackageVolume() const;
    void setPackageVolume(const double packageVolume);

    double getValue() const;
    void setValue(const double value);

    int getDeliveryTime() const;
    void setDeliveryTime(const int deliveryTime);
};


#endif