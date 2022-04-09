#include "DeliveryPackage.h"

DeliveryPackage::DeliveryPackage() {

}

DeliveryPackage::DeliveryPackage(int packageWeight, int packageVolume, int value,
                                 int deliveryTime) {
    this->packageWeight = packageWeight;
    this->packageVolume = packageVolume;
    this->value = value;
    this->deliveryTime = deliveryTime;
}

int DeliveryPackage::getPackageWeight() const {
    return this->packageWeight;
}

void DeliveryPackage::setPackageWeight(const int packageWeight) {
    this->packageWeight = packageWeight;
}

int DeliveryPackage::getPackageVolume() const {
    return this->packageVolume;
}

void DeliveryPackage::setPackageVolume(const int packageVolume) {
    this->packageVolume = packageVolume;
}

int DeliveryPackage::getValue() const {
    return this->value;
}

void DeliveryPackage::setValue(const int value) {
    this->value = value;
}

int DeliveryPackage::getDeliveryTime() const {
    return this->deliveryTime;
}

void DeliveryPackage::setDeliveryTime(const int deliveryTime) {
    this->deliveryTime = deliveryTime;
}

bool DeliveryPackage::operator<(const DeliveryPackage& deliveryPackage) const{
    return (this->packageVolume <= deliveryPackage.getPackageVolume() && this->packageWeight <= deliveryPackage.getPackageWeight());
}

bool DeliveryPackage::operator==(const DeliveryPackage& deliveryPackage) const{
    return (this->packageWeight == deliveryPackage.getPackageWeight() && this->packageVolume == deliveryPackage.getPackageVolume()
            && this->deliveryTime == deliveryPackage.getDeliveryTime() && this->value == deliveryPackage.getValue());
}

