#include <iostream>
#include "ETollSystem.h"

using namespace std;

int main() {
    ETollSystem tollSystem;

    ETollCard card1("ABC123", 50000, VehicleType::GOLONGAN_2);
    ETollCard card2("XYZ789", 20000, VehicleType::GOLONGAN_1);
    tollSystem.registerCard(card1);
    tollSystem.registerCard(card2);

    string cardId, gateIdStart, gateIdEnd;

    cout << "===== Simulasi Tap In dan Tap Out e-Toll =====" << endl;

    cout << "Masukkan ID Kartu e-Toll: ";
    cin >> cardId;

    cout << "Masukkan Gerbang Awal (contoh: GATE1): ";
    cin >> gateIdStart;

    if (!tollSystem.authenticateTap(cardId, gateIdStart)) {
        cout << "Autentikasi Tap In gagal. Pastikan ID Kartu dan saldo mencukupi." << endl;
        return 0;
    }

    cout << "Tap In berhasil di " << gateIdStart << endl;

    cout << "Masukkan Gerbang Akhir (contoh: GATE3): ";
    cin >> gateIdEnd;

    double distance = tollSystem.calculateDistance(gateIdStart, gateIdEnd);
    if (distance < 0) {
        cout << "Gagal menghitung jarak. Pastikan gerbang awal dan akhir valid." << endl;
        return 0;
    }

    bool paymentSuccess = tollSystem.processPayment(cardId, distance);

    return 0;
}
