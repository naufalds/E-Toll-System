#include "ETollCard.h"

ETollCard::ETollCard(const string& id, double saldo, VehicleType golongan) : id(id), saldo(saldo), golongan(golongan) {}

string ETollCard::getId() const {
    return id;
}

double ETollCard::getSaldo() const {
    return saldo;
}

int ETollCard::getGolongan() const {
    return static_cast<int>(golongan);
}

void ETollCard::deductBalance(double amount) {
    if (saldo >= amount) {
        saldo -= amount;
    }
}
