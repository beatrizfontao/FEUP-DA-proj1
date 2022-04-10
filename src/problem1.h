#ifndef PROJ1_PROBLEM1_H
#define PROJ1_PROBLEM1_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "DeliveryVan.h"
#include "DeliveryPackage.h"

using namespace std;

vector<DeliveryVan> deliveryVanMinimization(const vector<DeliveryVan>& vans, const vector<DeliveryPackage>& packages);

//vector<DeliveryVan> distributePackages(vector<DeliveryVan> &vans, vector<DeliveryPackage> &deliveryPackages, vector<DeliveryVan> &result);
vector<DeliveryVan> distributePackages(vector<DeliveryVan>& vans, vector<DeliveryPackage>& packages);

#endif
