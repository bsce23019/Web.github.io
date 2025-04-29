#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include<iostream>
#include <fstream>
using namespace std;
#include<string>

struct Vehicle {
    string licensePlate;
    string model;
    int year;
    bool isParked;
};

void addVehicle(Vehicle parkingLot[], int& vehicleCount);
void displayVehicles(const Vehicle parkingLot[], int vehicleCount);
const Vehicle* searchVehicle(const Vehicle parkingLot[], int vehicleCount, const string& licensePlate);
void parkVehicle(Vehicle parkingLot[], int vehicleCount, const string& licensePlate);
void leaveParkingLot(Vehicle parkingLot[], int vehicleCount, const string& licensePlate);
void saveParkingLotToFile(const Vehicle parkingLot[], int vehicleCount, const string& filename);
void displayparkinglot_info( const string& filename);
#endif