#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "Floor.h"

class ParkingLot {
private:
    std::vector<Floor> floors;
    double totalRevenue;

public:
    ParkingLot(int numFloors);
    bool parkVehicle(Vehicle* vehicle);
    void removeVehicle(std::string licensePlate);
    void displayStatus();
    void makePayment(double amount);

};

#endif
