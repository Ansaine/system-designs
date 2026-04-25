#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Vechicle.h"

class ParkingSpot {
private:
    Vehicle* vehicle;
    VehicleType type;

public:
    ParkingSpot(VehicleType type);
    bool isAvailable();
    void parkVehicle(Vehicle* vehicle);
    void removeVehicle();
    Vehicle* getVehicle();
    VehicleType getType();
};

#endif
