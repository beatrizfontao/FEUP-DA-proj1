#ifndef PROJ1_PROBLEM1_H
#define PROJ1_PROBLEM1_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "DeliveryVan.h"
#include "DeliveryPackage.h"

using namespace std;

vector<DeliveryVan> deliveryVanMinimization(const vector<DeliveryVan>& vans, const vector<DeliveryPackage>& packages);
/*
int lowerBound(const vector<DeliveryVan>& vans, const vector<DeliveryPackage>& packages);

vector<DeliveryVan> firstFit (const vector<DeliveryVan>& vans, const vector<DeliveryPackage>& packages);
*/
vector<DeliveryVan> distributePackages(const vector<DeliveryVan>& vans, const vector<DeliveryPackage>& packages);
/*
vector<DeliveryVan> fulBinPacking(const vector<DeliveryVan>& vans, const vector<DeliveryPackage>& packages);
*/
#endif
