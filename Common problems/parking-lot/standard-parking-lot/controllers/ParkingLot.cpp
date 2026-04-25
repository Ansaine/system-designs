#include "../models/ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int numFloors){
    totalRevenue = 0;

    for (int i = 0; i < numFloors; ++i) {
        int numBikes, numCars, numHandicapped;
        cout << "Enter number of bike spots for floor " << i + 1 << ": ";
        cin >> numBikes;
        cout << "Enter number of car spots for floor " << i + 1 << ": ";
        cin >> numCars;
        cout << "Enter number of handicapped spots for floor " << i + 1 << ": ";
        cin >> numHandicapped;
        floors.emplace_back(i + 1, numBikes, numCars, numHandicapped);
    }
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    for (auto& floor : floors) {
        if (floor.parkVehicle(vehicle)) {
            return true;
        }
    }
    return false;
}

void ParkingLot::removeVehicle(std::string licensePlate) {
    for (auto& floor : floors) {
        floor.removeVehicle(licensePlate);
    }
}

void ParkingLot::displayStatus() {
    for (auto& floor : floors) {
        floor.displayStatus();
    }
}

void ParkingLot::makePayment(double amount) {
    totalRevenue += amount;
    cout << "Payment received: $" << amount << "\n";
    cout << "Total revenue: $" << totalRevenue << "\n";
}
