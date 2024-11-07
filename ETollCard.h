#ifndef ETOLLCARD_H
#define ETOLLCARD_H

#include <string>
#include "VehicleType.h"

using namespace std;

class ETollCard {
private:
    string id;
    double saldo;
    VehicleType golongan;

public:
    ETollCard(const string& id, double saldo, VehicleType golongan);

    string getId() const;
    double getSaldo() const;
    int getGolongan() const;

    void deductBalance(double amount);
};

#endif
