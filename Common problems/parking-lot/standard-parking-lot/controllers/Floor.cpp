#include "../models/Floor.h"
#include <iostream>

Floor::Floor(int floorNumber, int numBikes, int numCars, int numHandicapped){

    this->floorNumber = floorNumber;

    for (int i = 0; i < numHandicapped; ++i) {
        spots.emplace_back(VehicleType::Handicapped);      // initialising spots, not parking
    }
    for (int i = 0; i < numCars; ++i) {
        spots.emplace_back(VehicleType::Car);
    }
    for (int i = 0; i < numBikes; ++i) {
        spots.emplace_back(VehicleType::Bike);
    }
}


bool Floor::parkVehicle(Vehicle* vehicle) {
    for (auto& spot : spots) {
        if (spot.isAvailable() && spot.getType()==vehicle->getType()) {
            spot.parkVehicle(vehicle);
            return true;
        }
    }
    return false;
}

void Floor::removeVehicle(std::string licensePlate) {
    for (auto& spot : spots) {
        Vehicle* vehicle = spot.getVehicle();
        if (vehicle != nullptr && vehicle->getLicensePlate() == licensePlate) {
            spot.removeVehicle();
            return;
        }
    }
}

void Floor::displayStatus() {
    for (size_t i = 0; i < spots.size(); ++i) {
        if (spots[i].isAvailable()) {
            std::cout << "Floor " << floorNumber << ": Spot " << i + 1 << " is available.\n";
        } else {
            std::cout << "Floor " << floorNumber << ": Spot " << i + 1 << " is occupied by vehicle with license plate: "
                      << spots[i].getVehicle()->getLicensePlate() << ".\n";
        }
    }
}
