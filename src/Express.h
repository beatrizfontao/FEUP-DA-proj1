#ifndef PROJ1_EXPRESS_H
#define PROJ1_EXPRESS_H

#include "DeliveryPackage.h"
#include "Courier.h"
#include <vector>

class Express {
public:
    Express();
    void drawExpress(vector<DeliveryPackage> d);
private:
    vector<DeliveryPackage> expressOrder(vector<DeliveryPackage> d);
    static bool comparison(DeliveryPackage a, DeliveryPackage b);
};


#endif
