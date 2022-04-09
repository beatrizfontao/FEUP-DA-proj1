#include <iostream>
#include <vector>
#include <fstream>
#include "src\DeliveryVan.h"
#include "src\DeliveryPackage.h"
#include "src\problem1.h"

using namespace std;

vector<DeliveryVan> readDeliveryVan(string filename){
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
    int volume, peso, recompensa, duracao;
    if(ifile.is_open()){
        ifile >> aux >> aux >> aux >> aux;
        while(!ifile.eof()){
            ifile >> volume >> peso >> recompensa >> duracao;
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
    vector<DeliveryVan> deliveryVans = readDeliveryVan("carrinhas.txt");
    vector<DeliveryPackage> deliveryPackages = readDeliveryPackage("encomendas.txt");
    /*
    cout << "CARRINHAS" << endl;
    for(int i = 0; i < deliveryVans.size(); i++){
        cout << "VOLMAX : " << deliveryVans[i].getMaxVolume() << endl;
        cout << "PESOMAX : " << deliveryVans[i].getMaxWeight() << endl;
        cout << "CUSTO : " << deliveryVans[i].getDeliveryCost() << endl;
        cout << "\n----------------------------------\n" ;
    }
    cout << '\n' << "ENCOMENDAS" << endl;
    for(int i = 0; i < deliveryPackages.size(); i++){
        cout << "VOLUME : " << deliveryPackages[i].getPackageVolume() << endl;
        cout << "PESO : " << deliveryPackages[i].getPackageWeight() << endl;
        cout << "RECOMPENSA : " << deliveryPackages[i].getValue() << endl;
        cout << "DURAÇÃO : " << deliveryPackages[i].getDeliveryTime() << endl;
        cout << "\n----------------------------------\n" ;
    }
     */
    /**-----------------------------PROBLEM 1-----------------------------**/

    vector<DeliveryVan> deliveryVanMinimized = deliveryVanMinimization(deliveryVans, deliveryPackages);
    /*
    cout << "-----------------------------PROBLEM 1-----------------------------" << endl << endl;
    cout << "MINIMIZATION OF VANS:" << endl;

    for(auto van : deliveryVanMinimized){
        cout << "Weight : " << van.getMaxWeight() << endl;
        cout << "Volume : " << van.getMaxVolume() << endl;
        cout << "Cost : " << van.getDeliveryCost() << endl;
        cout << "-----------------------------------------" << endl;
    }
*/
    return 0;
}
