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
    while(true) {
        cout << "TRABALHO DE DA" << endl << endl;
        cout << "1) Problema 1" << endl << "2) Problema 2" << endl << "3) Problema 3" << endl << "0) Sair" <<endl << "Opcao:" << endl;
        int option;
        cin >> option;
        Express express;
        switch (option) {
            case 1:
                //Problema 1
                break;
            case 2:
                //Problema 2
                break;
            case 3:
                express.drawExpress(d);
                break;
            case 0:
                return 0;
            default:
                cout << "Opção não existe" << endl << endl;
                break;
        }
    }
}
