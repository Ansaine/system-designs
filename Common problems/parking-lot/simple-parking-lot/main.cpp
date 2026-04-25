#include "models/ParkingLot.cpp"

int main() {

    ParkingLot lot(10);  // Create a parking lot with 5 spots

    lot.displayStatus();
    cout<<endl;

    Vehicle v1("car1");
    Vehicle v2("car2");
    Vehicle v3("bike1");

    // Park vehicles
    lot.parkVehicle(&v1);
    lot.parkVehicle(&v2);
    lot.parkVehicle(&v3);

    // Display parking lot status
    lot.displayStatus();
    cout<<endl;

    // Remove a vehicle
    lot.removeVehicle("XYZ789");

    // Display parking lot status again
    lot.displayStatus();
    cout<<endl;
    
    return 0;
}
