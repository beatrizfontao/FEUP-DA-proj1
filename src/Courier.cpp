#include "Courier.h"

Courier::Courier() {

}

Courier::Courier(int maxVolume, int maxWeight, int deliveryCost) {
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->deliveryCost = deliveryCost;
}

int Courier::getMaxVolume() const {
    return this->maxVolume;
}

void Courier::setMaxVolume(const int maxVolume) {
    this->maxVolume = maxVolume;
}

int Courier::getMaxWeight() const {
    return this->maxWeight;
}

void Courier::setMaxWeight(const int maxWeight) {
    this->maxWeight = maxWeight;
}

int Courier::getDeliveryCost() const {
    return this->deliveryCost;
}

void Courier::setDeliveryCost(const int deliveryCost) {
    this->deliveryCost = deliveryCost;
}
