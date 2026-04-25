#include "../models/ParkingSpot.h"

ParkingSpot::ParkingSpot(VehicleType type){
    vehicle = nullptr;
    this->type = type;
}

bool ParkingSpot::isAvailable() {
    return vehicle == nullptr;
}

void ParkingSpot::parkVehicle(Vehicle* vehicle) {
    this->vehicle = vehicle;
}

void ParkingSpot::removeVehicle() {
    vehicle = nullptr;
}

Vehicle* ParkingSpot::getVehicle() {
    return vehicle;
}

VehicleType ParkingSpot::getType() {
    return type;
}
