#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "ParkingSpot.h"

class Floor {
private:
    int floorNumber;
    vector<ParkingSpot> spots;
    
public:
    Floor(int floorNumber, int numBikes, int numCars, int numHandicapped);
    bool parkVehicle(Vehicle* vehicle);
    void removeVehicle(std::string licensePlate);
    void displayStatus();

};

#endif
