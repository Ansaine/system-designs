#include <bits/stdc++.h>
using namespace std;

class Vehicle {
private:
    string licensePlate;

public:
    Vehicle(string licensePlate);  // Constructor
    string getLicensePlate();  
};

// Constructor definition
Vehicle::Vehicle(string licensePlate) {
    this->licensePlate = licensePlate;
}

string Vehicle::getLicensePlate() {
    return licensePlate;
}
