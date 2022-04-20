#include <iostream>
#include <vector>
#include <fstream>
#include "src\DeliveryVan.h"
#include "src\DeliveryPackage.h"
#include "src/Express.h"
#include "src\problem2.h"

#include <numeric>


using namespace std;

vector<DeliveryVan> readCourier(string filename){
    vector<DeliveryVan> res = {};
    ifstream ifile(filename);
    DeliveryVan c;
    string aux;
    int volMax, pesoMax, custo;
    if(ifile.is_open()){
        ifile >> aux >> aux >> aux;
        while(!ifile.eof()){
            ifile >> volMax >> pesoMax >> custo;
            c.setMaxVolume(volMax);
            c.setMaxWeight(pesoMax);
            c.setDeliveryCost(custo);
            res.push_back(c);
        }
    }
    else {
        return res;
    }
    ifile.close();
    return res;
}

vector<DeliveryPackage> readDeliveryPackage(string filename){
    vector<DeliveryPackage> res = {};
    ifstream ifile(filename);
    DeliveryPackage d;
    string aux;
    int cnt = 1;
    int volume, peso, recompensa, duracao;
    if(ifile.is_open()){
        ifile >> aux >> aux >> aux >> aux;
        while(!ifile.eof()){
            ifile >> volume >> peso >> recompensa >> duracao;
            //cout << "Value = " << recompensa << endl;
            d.setPackageVolume(volume);
            d.setPackageWeight(peso);
            d.setValue(recompensa);
            d.setDeliveryTime(duracao);
            res.push_back(d);
        }
    }
    else {
        return res;
    }
    ifile.close();
    return res;
}


int main() {
    vector<DeliveryVan> c = readCourier("carrinhas.txt");
    vector<DeliveryPackage> d = readDeliveryPackage("encomendas.txt");
    pair<vector<DeliveryVan>, int> maxProfit = fill(c, d);

    int totalCost = 0;

    cout << "-----------------------------PROBLEM 2-----------------------------\n";
    cout << "                            MAX PROFIT\n";

    for(auto van : maxProfit.first){
        cout << "Weight: " << van.getMaxWeight() << "\n";
        cout << "Volume: " << van.getMaxVolume() << "\n";
        cout << "Cost: " << van.getDeliveryCost() << "\n";
        cout << "-----------------------------------------\n" << endl;
        totalCost += van.getDeliveryCost();
    }

    cout << "Number of delivery vans needed : " << maxProfit.first.size() << "\n";
    cout << "Total cost : " << totalCost << "\n";
    cout << "Reward: " << maxProfit.second << "\n";
    cout << "Profit: " << maxProfit.second - totalCost << "\n\n";

    return 0;
}
