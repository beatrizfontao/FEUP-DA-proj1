#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include "src\Courier.h"
#include "src\DeliveryPackage.h"
#include "src/Express.h"

using namespace std;

vector<Courier> readCourier(string filename){
    vector<Courier> res = {};
    ifstream ifile(filename);
    Courier c;
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
            cout << "Value = " << recompensa << endl;
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
    vector<Courier> c = readCourier("carrinhas.txt");
    vector<DeliveryPackage> d = readDeliveryPackage("encomendas.txt");
    cout << "CARRINHAS" << endl;
    for(int i = 0; i < c.size(); i++){
        cout << "VOLMAX : " << c[i].getMaxVolume() << endl;
        cout << "PESOMAX : " << c[i].getMaxWeight() << endl;
        cout << "CUSTO : " << c[i].getDeliveryCost() << endl;
        cout << "\n----------------------------------\n" ;
    }
    cout << '\n' << "ENCOMENDAS" << endl;
    for(int i = 0; i < d.size(); i++){
        cout << "VOLUME : " << d[i].getPackageVolume() << endl;
        cout << "PESO : " << d[i].getPackageWeight() << endl;
        cout << "RECOMPENSA : " << d[i].getValue() << endl;
        cout << "DURAÇÃO : " << d[i].getDeliveryTime() << endl;
        cout << "\n----------------------------------\n" ;
    }

    Express express;
    vector<DeliveryPackage> expressDelivery = express.expressOrder(d);
    double sumTime;
    for(auto x: expressDelivery){
        sumTime += x.getDeliveryTime();
    }
    cout << sumTime/expressDelivery.size() << endl;
    return 0;
}
