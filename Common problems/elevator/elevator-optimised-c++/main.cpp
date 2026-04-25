// The optimisation from simple-elevator is that - 
// 1. We will prioritise requests based on direction and current position
// 2. use priority queue to manage requests
// 3. group requests based on same direction

// New optimisations - 

// Grouping Requests: Requests for the same floor are grouped using a unordered_set to avoid processing the same floor multiple times.
// Dynamic Request Management: Requests can be dynamically added even while the elevator is moving. The priority queue ensures efficient management.
// Request Removal: Requests are removed from the processedRequests set once they are serviced, preventing redundant stops.


#include <bits/stdc++.h>
using namespace std;

enum Direction { UP, DOWN, IDLE };

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
        cout << "Elevator moving up to floor " << currentFloor <<endl;
    }

    void moveDown() {
        currentFloor--;
        direction = DOWN;
        isMoving = true;
        cout << "Elevator moving down to floor " << currentFloor <<endl;
    }

    void stop() {
        direction = IDLE;
        isMoving = false;
        cout << "Elevator stopped at floor " << currentFloor <<endl;
    }

    bool shouldMoveUp(int floor) {
        return currentFloor < floor;
    }

    bool shouldMoveDown(int floor) {
        return currentFloor > floor;
    }
};

class Request {
public:
    int floor;
    Direction direction;
    int requestID;

    Request(int f, Direction d, int id){
        floor = f;
        direction = d;
        requestID = id; 
    }
};

class ElevatorController {
public:
    Elevator elevator;
    priority_queue<int, vector<int>, greater<int>> upRequests; // Min-heap for UP direction
    priority_queue<int> downRequests; // Max-heap for DOWN direction
    unordered_set<int> processedRequests; // Track processed requests
    int requestCounter; // To generate unique request IDs

    ElevatorController(){
        requestCounter = 0;
    }

    void addRequest(int floor, Direction direction) {
        if (processedRequests.find(floor) != processedRequests.end()) return; // Skip if already processed
        processedRequests.insert(floor); // Mark as processed

        if (direction == UP) {
            upRequests.push(floor);
        } else if (direction == DOWN) {
            downRequests.push(floor);
        }
    }

    void processRequests() {
        while (!upRequests.empty() || !downRequests.empty()) {
            if (elevator.direction == IDLE) {
                determineInitialDirection();
            }

            if (elevator.direction == UP) {                             // after elevator finishes up requests, it checks for more up requests
                handleUpRequests();
                if (upRequests.empty() && !downRequests.empty()) {
                    elevator.direction = DOWN;                          // when there are none, it will now go down if down requests are present
                }
            } else if (elevator.direction == DOWN) {                    // vice versa
                handleDownRequests();
                if (downRequests.empty() && !upRequests.empty()) {
                    elevator.direction = UP;
                }
            }
        }
    }

private:
    void determineInitialDirection() {
        if (upRequests.empty() && !downRequests.empty()) {
            elevator.direction = DOWN;
        } else if (!upRequests.empty() && downRequests.empty()) {
            elevator.direction = UP;
        } else if (!upRequests.empty() && !downRequests.empty()) {
            int upRequestFloor = upRequests.top();
            int downRequestFloor = downRequests.top();
            if (abs(elevator.currentFloor - upRequestFloor) <= abs(elevator.currentFloor - downRequestFloor)) {
                elevator.direction = UP;
            } else {
                elevator.direction = DOWN;
            }
        }
    }

    void handleUpRequests() {
        while (!upRequests.empty() && elevator.direction == UP) {
            int nextFloor = upRequests.top();
            upRequests.pop();
            moveToFloor(nextFloor);
        }
    }

    void handleDownRequests() {
        while (!downRequests.empty() && elevator.direction == DOWN) {
            int nextFloor = downRequests.top();
            downRequests.pop();
            moveToFloor(nextFloor);
        }
    }

    void moveToFloor(int floor) {
        while (elevator.currentFloor != floor) {
            if (elevator.shouldMoveUp(floor)) {
                elevator.moveUp();
            } else if (elevator.shouldMoveDown(floor)) {
                elevator.moveDown();
            }
        }
        elevator.stop();
        processedRequests.erase(floor); // Remove from processed set
    }
};

int main() {
    ElevatorController controller;

    // Simulate requests
    controller.addRequest(3, UP);
    controller.addRequest(1, DOWN);
    controller.addRequest(5, UP);
    controller.addRequest(2, DOWN);
    controller.addRequest(4, UP);

    // Process all requests
    controller.processRequests();

    return 0;
}
int main() {

    ElevatorController controller;

    // two steps - first requests are added then it is processed 

    // add requests
    controller.addRequest(3, UP);

    // Process requests
    controller.processRequests();

    controller.addRequest(1, DOWN);
    controller.addRequest(5, UP);
    controller.addRequest(2, DOWN);
    controller.addRequest(6, UP);

    // Process requests
    controller.processRequests();

    // it should processs like - 3,2,1,5,6

    return 0;
}
