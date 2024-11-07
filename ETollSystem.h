#ifndef ETOLLSYSTEM_H
#define ETOLLSYSTEM_H

#include <string>
#include <unordered_map>
#include "ETollCard.h"

using namespace std;

class ETollSystem {
private:
    unordered_map<string, ETollCard> cards;
    unordered_map<string, double> gateDistances;

public:
    ETollSystem();

    void registerCard(const ETollCard& card);
    bool verifyETollCard(const string& cardId);
    bool validateGateID(const string& gateId);
    bool validateUserStatus(const string& cardId);

    double identifyStartPoint(const string& gateIdStart);
    double identifyEndPoint(const string& gateIdEnd);
    double calculateTravelDistance(double startDistance, double endDistance) const;

    bool authenticateTap(const string& cardId, const string& gateId);
    double calculateDistance(const string& gateIdStart, const string& gateIdEnd);
    bool processPayment(const string& cardId, double distance);

    void openGate();
    void displayStatus(const string& cardId, const string& gateIdStart, const string& gateIdEnd, double tollFee, bool success);
};

string getGolonganName(VehicleType golongan);

#endif
