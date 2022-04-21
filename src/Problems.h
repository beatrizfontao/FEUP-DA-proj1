#ifndef PROJ1_PROBLEMS_H
#define PROJ1_PROBLEMS_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "DeliveryVan.h"
#include "DeliveryPackage.h"

using namespace std;

void setAuxVans(vector<pair<int, int>> &auxVans, vector<DeliveryVan> &deliveryVans);

//Cenário 2
vector<DeliveryVan> maximizeProfit(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages, int &totalCost, int &reward);

bool placePackage(vector<DeliveryPackage> &searchPackages, vector<DeliveryPackage> &auxPackages, vector<DeliveryVan> &deliveryVans, vector<DeliveryVan> &res,
                  vector<pair<int, int>> &auxVans, int vanNr, int &reward, int &totalCost);

bool sortPackagesByWeight(DeliveryPackage A, DeliveryPackage B);

bool sortPackagesByVolume(DeliveryPackage A, DeliveryPackage B);

bool sortVansByCost(DeliveryVan A, DeliveryVan B);

void drawMaxProfit(const vector<DeliveryVan> &vans, const vector<DeliveryPackage> &packages);

void drawAuxVans(vector<pair<int,int>> auxVans);

//Cenário 3

vector<DeliveryPackage> expressOrder(vector<DeliveryPackage> d);

static bool sortByTime(DeliveryPackage A, DeliveryPackage B);

void drawExpress(vector<DeliveryPackage> d);

#endif //PROJ1_PROBLEMS_H
