#ifndef PROJ1_PROBLEM2_H
#define PROJ1_PROBLEM2_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "DeliveryVan.h"
#include "DeliveryPackage.h"

using namespace std;


pair<vector<DeliveryVan>, int> fill(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages);

bool placePackage(vector<DeliveryPackage> &deliveryPackages, vector<DeliveryVan> &deliveryVans, vector<DeliveryVan> &res,
             vector<pair<int, int>> &auxVans, int vanNr, int &reward);

void sortPackagesByWeight(vector<DeliveryPackage> &deliveryPackages);

void sortPackagesByVolume(vector<DeliveryPackage> &deliveryPackages);

#endif //PROJ1_PROBLEM2_H
