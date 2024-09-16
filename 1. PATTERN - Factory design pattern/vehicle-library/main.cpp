#include<iostream>
using namespace std;

#include "models/Vehicle.hpp"
#include "models/Vehicle_Factory.hpp"

int main(){
    string type;
    cout<<"Enter vehicle type : ";
    cin>>type;

    // abstraction using factory design
    Vehicle* myVehicle = VehicleFactory::getVehicle(type);
    myVehicle->createVehicle();
    return 0;
}