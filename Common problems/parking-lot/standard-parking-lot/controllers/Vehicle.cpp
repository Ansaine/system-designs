#include "../models/Vechicle.h"

Vehicle::Vehicle(string licensePlate, VehicleType type){
    this->licensePlate = licensePlate;
    this->type = type;
}

string Vehicle::getLicensePlate() {
    return licensePlate;
}

VehicleType Vehicle::getType() {
    return type;
}
