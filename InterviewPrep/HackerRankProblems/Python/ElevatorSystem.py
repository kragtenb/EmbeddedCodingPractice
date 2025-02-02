"""
Problem: Design an Elevator System
Problem Statement:

Design a system to simulate an elevator in a building. The elevator system should handle multiple elevators and service requests from different floors.

Your system should be able to:
Add service requests from different floors.
Move the elevator up or down to service the requests.
Show the current status of all elevators (current floor, direction, and requests being serviced).

Functionality:
The system should allow adding requests (e.g., a request from floor 5 to go up).
The elevator should move in the direction of the requests, stopping at floors where requests have been made.
The system should handle multiple elevators, assigning requests to the nearest or most appropriate elevator.
The system should provide the current status of all elevators.

Requirements:
Implement the add_request method to handle incoming requests.
Implement the move_elevators method to simulate the movement of elevators to service the requests.
Implement the get_status method to return the current status of all elevators.
"""

from enum import Enum


class Direction(Enum):
    UP = 0
    STATIONARY = 1
    DOWN = 2


class Elevator:
    def __init__(self) -> None:
        self.current_floor = 0
        self.destination_floor = 0
        self.direction = Direction.STATIONARY

    def is_available(self):
        return self.current_floor == self.destination_floor

    def move_elevator(self):
        if self.direction == Direction.UP:
            self.current_floor += 1
        elif self.direction == Direction.DOWN:
            self.current_floor -= 1
        if self.current_floor == self.destination_floor:
            self.direction = Direction.STATIONARY

    def request_elevator(self, floor):
        self.destination_floor = floor
        if self.destination_floor < self.current_floor:
            self.direction = Direction.DOWN
        elif self.destination_floor > self.current_floor:
            self.direction = Direction.UP
        else:
            self.direction = Direction.STATIONARY


class ElevatorSystem:
    def __init__(self, num_floors, num_elevators) -> None:
        self.num_floors = num_floors
        self.num_elevators = num_elevators
        self.elevators = []
        self.requests = []
        self.floors_requested = {}

        for _ in range(num_elevators):
            self.elevators.append(Elevator())

    def elevator_request(self, floor):
        if floor in self.floors_requested:
            return
        self.requests.append(floor)
        self.floors_requested[floor] = 1

    def move_elevators_one_floor(self):
        # Check if any elevators need to be set for the request
        for idx, e in enumerate(self.elevators):
            if e.is_available() and len(self.requests) > 0:
                print(f'Elevator({idx}) is available and getting latest request')
                floor_requested = self.requests[0]
                e.request_elevator(floor_requested)
                self.requests.pop(0)
                self.floors_requested.pop(floor_requested)
            e.move_elevator()

    def status(self):
        print(f"There are {len(self.elevators)} elevators")
        print(f"There are {len(self.requests)} active floor requests")
        for idx, e in enumerate(self.elevators):
            print(
                f"Elevator({idx}) is at floor {e.current_floor} its direction is {e.direction} "
                f"and its destination is {e.destination_floor}"
            )
        for idx, r in enumerate(self.requests):
            print(f"Request({idx}) is for floor {r}")


if __name__ == "__main__":
    es = ElevatorSystem(5, 3)
    es.elevator_request(4)
    es.elevator_request(2)
    es.elevator_request(3)
    es.elevator_request(1)
    
    es.status()

    es.move_elevators_one_floor()
    es.status()

    es.move_elevators_one_floor()
    es.status()

    es.move_elevators_one_floor()
    es.status()

    es.move_elevators_one_floor()
    es.status()

    es.move_elevators_one_floor()
    es.status()

    es.move_elevators_one_floor()
    es.status()

    es.move_elevators_one_floor()
    es.status()
