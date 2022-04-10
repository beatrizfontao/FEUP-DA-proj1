#include "DeliveryVan.h"

DeliveryVan::DeliveryVan() {

}

DeliveryVan::DeliveryVan(int maxVolume, int maxWeight, int deliveryCost) {
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->deliveryCost = deliveryCost;
}

int DeliveryVan::getMaxVolume() const {
    return this->maxVolume;
}

void DeliveryVan::setMaxVolume(const int maxVolume) {
    this->maxVolume = maxVolume;
}

int DeliveryVan::getMaxWeight() const {
    return this->maxWeight;
}

void DeliveryVan::setMaxWeight(const int maxWeight) {
    this->maxWeight = maxWeight;
}

int DeliveryVan::getDeliveryCost() const {
    return this->deliveryCost;
}

void DeliveryVan::setDeliveryCost(const int deliveryCost) {
    this->deliveryCost = deliveryCost;
}

bool DeliveryVan::operator<(const DeliveryVan& deliveryVan) const{
    if(this->getDeliveryCost() < deliveryVan.getDeliveryCost())
        return true;
    return (this->maxWeight < deliveryVan.getMaxWeight() && this->maxVolume < deliveryVan.getMaxVolume());
}