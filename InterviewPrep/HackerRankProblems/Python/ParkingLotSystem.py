'''
Problem: Design a Parking Lot System
Problem Statement:

Design a parking lot system that can:

Park a vehicle.
Unpark a vehicle.
Get the status of the parking lot.
Assume the parking lot has multiple levels, each with multiple spots. The parking lot should be able to handle different types of vehicles, 
    such as cars, buses, and motorcycles. Each type of vehicle may occupy different numbers of spots:

Motorcycles take up 1 spot.
Cars take up 1 spot.
Buses take up 5 spots.

Classes to Implement:

Vehicle
ParkingSpot
ParkingLot
Level
ParkingSpotType
Functionality:

The system should be able to find a parking spot for a vehicle and park it.
The system should be able to unpark a vehicle from the parking lot.
The system should provide the current status of the parking lot.

Requirements:
Implement the park_vehicle method that finds a suitable spot and parks the vehicle.
Implement the unpark_vehicle method that removes a vehicle from the parking lot.
Implement the get_status method that returns the current status of the parking lot (e.g., available spots, occupied spots, etc.).
'''
from abc import ABC
from enum import Enum

class VehicleType(Enum):
    MOTOCYCLE = 1
    CAR = 2
    BUS = 3

class Vehicle(ABC):
    def __init__(self) -> None:
        self.parked_spot = -1
    
    def get_type(self):
        return "Vehicle"

    def required_spots(self):
        return 1
    
    def is_parked(self):
        return self.parked_spot >= 0
    
class Motorcycle(Vehicle):
    def get_type(self):
        return "Motorcycle"

class Car(Vehicle):
    def get_type(self):
        return "Car"
    
class Bus(Vehicle):
    def get_type(self):
        return "Bus"
    
    def required_spots(self):
        return 5
    
class ParkingLot:
    def __init__(self, spaces, floors) -> None:
        self.spaces = spaces
        self.floors = floors
        self.parking = [[]*floors]

        for i in range()
        for i in range(spaces)
    