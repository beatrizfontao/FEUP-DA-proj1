#include "DeliveryPackage.h"

DeliveryPackage::DeliveryPackage() {

}

DeliveryPackage::DeliveryPackage(string type, double packageWeight, double packageVolume, double value,
                                 int deliveryTime) {
    this->type = type;
    this->packageWeight = packageWeight;
    this->packageVolume = packageVolume;
    this->value = value;
    this->deliveryTime = deliveryTime;
}

string DeliveryPackage::getType() const {
    return this->type;
}

void DeliveryPackage::setType(const string type) {
    this->type = type;
}

double DeliveryPackage::getPackageWeight() const {
    return this->packageWeight;
}

void DeliveryPackage::setPackageWeight(const double packageWeight) {
    this->packageWeight = packageWeight;
}

double DeliveryPackage::getPackageVolume() const {
    return this->packageVolume;
}

void DeliveryPackage::setPackageVolume(const double packageVolume) {
    this->packageVolume = packageVolume;
}

double DeliveryPackage::getValue() const {
    return this->value;
}

void DeliveryPackage::setValue(const double packageValue) {
    this->value = value;
}

int DeliveryPackage::getDeliveryTime() const {
    return this->deliveryTime;
}

void DeliveryPackage::setDeliveryTime(const int deliveryTime) {
    this->deliveryTime = deliveryTime;
}
