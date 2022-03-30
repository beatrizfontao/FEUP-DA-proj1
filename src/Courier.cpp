#include "Courier.h"

Courier::Courier() {

}

Courier::Courier(string licensePlate, double maxVolume, double maxWeight, double deliveryCost) {
    this->licensePlate = licensePlate;
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->deliveryCost = deliveryCost;
}

string Courier::getLicensePlate() const {
    return this->licensePlate;
}

void Courier::setLicensePlate(const string licensePlate) {
    this->licensePlate = licensePlate;
}

double Courier::getMaxVolume() const {
    return this->maxVolume;
}

void Courier::setMaxVolume(const double maxVolume) {
    this->maxVolume = maxVolume;
}

double Courier::getMaxWeight() const {
    return this->maxWeight;
}

void Courier::setMaxWeight(const double maxWeight) {
    this->maxWeight = maxWeight;
}

double Courier::getDeliveryCost() const {
    return this->deliveryCost;
}

void Courier::setDeliveryCost(const double deliveryCost) {
    this->deliveryCost = deliveryCost;
}
