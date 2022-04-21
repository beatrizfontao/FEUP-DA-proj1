#include "Problems.h"

/**
 * Chooses the express deliveries in a way that reduces the average time of each delivery
 * Time Complexity: O(nlog(n))
 * @param d vector with every delivery
 * @return ordered vector with express deliveries with the smallest delivery times
 */
vector<DeliveryPackage> expressOrder(vector<DeliveryPackage> d) {
    sort(d.begin(), d.end(), sortByTime);

    vector<DeliveryPackage> res;
    int totalTime = 0;
    int deliveryInd = 0;
    while(totalTime + d[deliveryInd].getDeliveryTime() <= 28800){
        totalTime += d[deliveryInd].getDeliveryTime();
        res.push_back(d[deliveryInd]);
        deliveryInd++;
    }
    return res;
}

/**
 * Compares the delivery times of two Deliveries
 * @param A First package
 * @param B Second package
 * @return bool that tells which delivery time is bigger
 */
bool sortByTime(DeliveryPackage A, DeliveryPackage B) {
    return A.getDeliveryTime() < B.getDeliveryTime();
}

/**
 * Calculates and displays the average time of the deliveries
 * Time Complexity: O(nlog(n))
 * @param d vector with every delivery
 */
void drawExpress(vector<DeliveryPackage> d) {
    vector<DeliveryPackage> expressDelivery = expressOrder(d);

    double sumTime = 0, temp = 0;
    for(int i = 0; i < expressDelivery.size(); i++){
        sumTime = expressDelivery[i].getDeliveryTime() + temp;
        temp = sumTime;
    }
    cout << "Media de tempo por encomenda(em segundos):" << sumTime/expressDelivery.size() << endl << endl;
}