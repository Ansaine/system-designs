#include <iostream>
#include "models/ParkingLot.h"
#include "models/Vechicle.h"

int main() {
    int numFloors;
    cout << "Enter the number of floors in the parking lot: ";
    cin >> numFloors;
    ParkingLot lot(numFloors);

    Vehicle v1("ABC123", VehicleType::Car);
    Vehicle v2("XYZ789", VehicleType::Bike);
    Vehicle v3("LMN456", VehicleType::Handicapped);

    // Park vehicles
    if (lot.parkVehicle(&v1)) {
        cout << "Vehicle ABC123 parked.\n";
    } else {
        cout << "Parking failed for vehicle ABC123.\n";
    }

    if (lot.parkVehicle(&v2)) {
        cout << "Vehicle XYZ789 parked.\n";
    } else {
        cout << "Parking failed for vehicle XYZ789.\n";
    }

    if (lot.parkVehicle(&v3)) {
        cout << "Vehicle LMN456 parked.\n";
    } else {
        cout << "Parking failed for vehicle LMN456.\n";
    }


    lot.displayStatus(); 
    lot.makePayment(10.00);
    lot.removeVehicle("XYZ789");
    lot.displayStatus();

    return 0;
}
