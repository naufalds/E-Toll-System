#include "ETollSystem.h"
#include <iostream>
#include <cmath>

using namespace std;

ETollSystem::ETollSystem() {
    gateDistances["GATE1"] = 0.0;
    gateDistances["GATE2"] = 10.0;
    gateDistances["GATE3"] = 25.0;
    gateDistances["GATE4"] = 40.0;
    gateDistances["GATE5"] = 55.0;
}

void ETollSystem::registerCard(const ETollCard& card) {
    cards.emplace(card.getId(), card);
}

bool ETollSystem::verifyETollCard(const string& cardId) {
    return cards.find(cardId) != cards.end();
}

bool ETollSystem::validateGateID(const string& gateId) {
    return gateDistances.find(gateId) != gateDistances.end();
}

bool ETollSystem::validateUserStatus(const string& cardId) {
    auto it = cards.find(cardId);
    return it != cards.end() && it->second.getSaldo() > 0;
}

double ETollSystem::identifyStartPoint(const string& gateIdStart) {
    auto it = gateDistances.find(gateIdStart);
    return (it != gateDistances.end()) ? it->second : -1.0;
}

double ETollSystem::identifyEndPoint(const string& gateIdEnd) {
    auto it = gateDistances.find(gateIdEnd);
    return (it != gateDistances.end()) ? it->second : -1.0;
}

double ETollSystem::calculateTravelDistance(double startDistance, double endDistance) const {
    return (startDistance >= 0 && endDistance >= 0) ? abs(endDistance - startDistance) : -1.0;
}

bool ETollSystem::authenticateTap(const string& cardId, const string& gateId) {
    return verifyETollCard(cardId) && validateGateID(gateId) && validateUserStatus(cardId);
}

double ETollSystem::calculateDistance(const string& gateIdStart, const string& gateIdEnd) {
    double startDistance = identifyStartPoint(gateIdStart);
    double endDistance = identifyEndPoint(gateIdEnd);
    return calculateTravelDistance(startDistance, endDistance);
}

bool ETollSystem::processPayment(const string& cardId, double distance) {
    auto it = cards.find(cardId);
    if (it != cards.end()) {
        ETollCard& card = it->second;
        double tollFee = distance * 1000; // Tarif per KM
        if (card.getSaldo() >= tollFee) {
            card.deductBalance(tollFee);
            openGate();
            displayStatus(cardId, "GATE_START", "GATE_END", tollFee, true);
            return true;
        }
        displayStatus(cardId, "GATE_START", "GATE_END", tollFee, false);
    }
    return false;
}

void ETollSystem::openGate() {
    cout << "Gate is open. You may proceed." << endl;
}

void ETollSystem::displayStatus(const string& cardId, const string& gateIdStart, const string& gateIdEnd, double tollFee, bool success) {
    auto it = cards.find(cardId);
    if (it == cards.end()) return;
    const ETollCard& card = it->second;

    cout << "\n===== Informasi Transaksi e-Toll =====" << endl;
    cout << "Golongan Kendaraan: " << getGolonganName(static_cast<VehicleType>(card.getGolongan())) << endl;
    cout << "Gerbang Awal      : " << gateIdStart << endl;
    cout << "Gerbang Akhir     : " << gateIdEnd << endl;
    cout << "Tarif             : " << tollFee << " IDR" << endl;

    if (success) {
        cout << "Sisa Saldo        : " << card.getSaldo() << " IDR" << endl;
        cout << "Status            : Pembayaran Berhasil" << endl;
    } else {
        cout << "Sisa Saldo        : " << card.getSaldo() << " IDR" << endl;
        cout << "Status            : Pembayaran Gagal (Saldo Tidak Cukup)" << endl;
    }
    cout << "======================================\n" << endl;
}

string getGolonganName(VehicleType golongan) {
    switch (golongan) {
        case VehicleType::GOLONGAN_1:
            return "Golongan 1 (Mobil)";
        case VehicleType::GOLONGAN_2:
            return "Golongan 2 (Bus)";
        case VehicleType::GOLONGAN_3:
            return "Golongan 3 (Truk)";
        default:
            return "Golongan Tidak Dikenal";
    }
}
