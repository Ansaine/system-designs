#include <bits/stdc++.h>
#include "Vehicle.cpp"

using namespace std;

class ParkingSpot {
private:
    Vehicle* vehicle;  // Pointer to the vehicle parked in this spot

public:
    ParkingSpot();  
    bool isAvailable();
    void parkVehicle(Vehicle* vehicle);  // Park a vehicle in the spot
    void removeVehicle();  // Remove the vehicle from the spot
    Vehicle* getVehicle();  // Get the parked vehicle
};


ParkingSpot::ParkingSpot() {
    vehicle = nullptr;
}

bool ParkingSpot::isAvailable(){
    return vehicle == nullptr;
}

void ParkingSpot::parkVehicle(Vehicle* vehicle) {
    this->vehicle = vehicle;
}

void ParkingSpot::removeVehicle() {
    vehicle = nullptr;
}

Vehicle* ParkingSpot::getVehicle(){
    return vehicle;
}
