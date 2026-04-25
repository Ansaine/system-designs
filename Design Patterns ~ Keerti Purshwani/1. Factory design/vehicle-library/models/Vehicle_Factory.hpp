#ifndef Vehicle_Factory_hpp
#define Vehicle_Factory_hpp

#include<iostream>
#include "Vehicle.hpp"

using namespace std;

class VehicleFactory {
public:
    static Vehicle* getVehicle(string type);
};

#endif