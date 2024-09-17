#include<iostream>
#include "../models/Bike.hpp"
#include "../models/Car.hpp"
#include "../models/Vehicle_Factory.hpp"


using namespace std;

Vehicle* VehicleFactory::getVehicle(string type){
    Vehicle* vehicle;

    if(type=="Car" or type=="car"){
        vehicle = new Car();
    }else if(type=="Bike" or type=="bike"){
        vehicle = new Bike;
    }

    return vehicle;
}

