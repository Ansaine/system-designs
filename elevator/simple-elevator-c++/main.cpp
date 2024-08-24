// The elevator logic is made overly simplified.
// the elevator executes each request 1 by 1 from a queue.
// there is no optimisation for handling multiple requests, or movement optimisaiton or floor prioirtisation.


#include <bits/stdc++.h>
using namespace std;

enum Direction { UP, DOWN, IDLE };

// There are 3 classes
// 1. The elevator itself   
// 2. The request class
// 3. The controller class that processes the requests in a queue and then controlls the elevator 


class Elevator {
public:
    int currentFloor;
    Direction direction;
    bool isMoving;

    Elevator(){
        currentFloor = 0;
        direction = IDLE;
        isMoving = false;
    } 

    void moveUp() {
        currentFloor++;
        direction = UP;
        isMoving = true;
        std::cout << "Elevator moving up to floor " << currentFloor << std::endl;
    }

    void moveDown() {
        currentFloor--;
        direction = DOWN;
        isMoving = true;
        std::cout << "Elevator moving down to floor " << currentFloor << std::endl;
    }

    void stop() {
        direction = IDLE;
        isMoving = false;
        std::cout << "Elevator stopped at floor " << currentFloor << std::endl;
    }
};

class Request {
public:
    int floor;
    Direction direction;

    Request(int f, Direction d){
        floor = f;
        direction = d;
    }
};

#include <queue>
#include <vector>

// ElevatorController logic
// 1. Requests are added to the queue
// 2. The controller checks the elevator floor and if it is less than req floor then it moves up and vice versa.


class ElevatorController {
public:
    Elevator elevator;
    queue<Request> requests;

    void addRequest(int floor, Direction direction) {
        requests.push(Request(floor, direction));
    }

    void processRequests() {
        while (!requests.empty()) {
            Request req = requests.front();
            requests.pop();
            handleRequest(req);
        }
    }

    void handleRequest(Request req) {
        while (elevator.currentFloor != req.floor) {
            if (elevator.currentFloor < req.floor) {
                elevator.moveUp();
            } else if (elevator.currentFloor > req.floor) {
                elevator.moveDown();
            }
        }
        elevator.stop();
    }
};


int main() {
    ElevatorController controller;

    // Simulate requests
    controller.addRequest(3, DOWN);
    controller.addRequest(1, UP);
    controller.addRequest(5, UP);

    // Process all requests
    controller.processRequests();

    return 0;
}