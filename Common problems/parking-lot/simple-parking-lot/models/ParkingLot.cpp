#include <bits/stdc++.h>
#include "ParkingSpot.cpp"

using namespace std;

class ParkingLot {
private:
    vector<ParkingSpot> spots; 

public:
    ParkingLot(int totalSpots);  // Constructor
    bool parkVehicle(Vehicle* vehicle);  // Park a vehicle in the lot
    void removeVehicle(string licensePlate);  // Remove a vehicle by license plate
    void displayStatus();  // Display the current status of the parking lot
};

// Constructor 
ParkingLot::ParkingLot(int totalSpots) {
    spots = vector<ParkingSpot>(totalSpots); 
}

// Main Algorithm for Parking
bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    for (int i = 0; i < spots.size(); ++i) {
        if (spots[i].isAvailable()) {
            spots[i].parkVehicle(vehicle);
            cout << "Vehicle with license plate " << vehicle->getLicensePlate() << " has been parked." << endl;
            return true;
        }
    }
    cout << "Parking Lot is full." << endl;
    return false;
}

void ParkingLot::removeVehicle( string licensePlate) {
    for (int i = 0; i < spots.size(); ++i) {
        Vehicle* vehicle = spots[i].getVehicle();
        if (vehicle != nullptr && vehicle->getLicensePlate() == licensePlate) {
            spots[i].removeVehicle();
            cout << "Vehicle with license plate " << licensePlate << " has left." << endl;
            return;
        }
    }
    cout << "Vehicle with license plate " << licensePlate << " not found." << endl;
}

void ParkingLot::displayStatus(){
    for (int i = 0; i < spots.size(); ++i) {
        if (spots[i].isAvailable()) {
            cout << "Spot " << i + 1 << " is available." << endl;
        } else {
            cout << "Spot " << i + 1 << " is occupied by vehicle with license plate: "
                 << spots[i].getVehicle()->getLicensePlate() << "." << endl;
        }
    }
}
