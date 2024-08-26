#ifndef VEHICLE_H
#define VEHICLE_H

#include <bits/stdc++.h>
using namespace std;

enum class VehicleType { Bike, Car, Handicapped };

class Vehicle {
public:
    Vehicle(string licensePlate, VehicleType type);
    string getLicensePlate();
    VehicleType getType();

private:
    string licensePlate;
    VehicleType type;
};

#endif
