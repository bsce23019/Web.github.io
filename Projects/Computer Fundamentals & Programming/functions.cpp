#include "functions.h"
#include <iostream>
#include <fstream>
using namespace std;
#include<string>
int startTime1[10];
int endTime1[10];
int startTime2[10];
int endTime2[10];
int result1[10];
int result2[10];
void addVehicle(Vehicle parkingLot[], int& vehicleCount) {
    cout << "Press enter to input data for the vehicle:" << endl;
    cin.ignore();
    cout << "Enter the license plate of the vehicle: ";
    getline(cin, parkingLot[vehicleCount].licensePlate);
    cout << "Enter the model of the vehicle: ";
    getline(cin, parkingLot[vehicleCount].model);
    cout << "Enter the year of the vehicle: ";
    cin >> parkingLot[vehicleCount].year;
    parkingLot[vehicleCount].isParked = true;
    vehicleCount++;
}

void displayVehicles(const Vehicle parkingLot[], int vehicleCount) {
    if (vehicleCount==0)
    {
        return;
    }
    else
    {
        cout << "License Plate: " << parkingLot[vehicleCount-1].licensePlate << endl;
        cout << "Model: " << parkingLot[vehicleCount-1].model << endl;
        cout << "Year: " << parkingLot[vehicleCount-1].year << endl;
        cout << "Is Parking lot available  : " << (parkingLot[vehicleCount-1].isParked ? "Yes" : "No") << endl;
        displayVehicles(parkingLot,vehicleCount-1);
    }

}

const Vehicle* searchVehicle(const Vehicle parkingLot[], int vehicleCount, const string& licensePlate) {
    for (int i = 0; i < vehicleCount; ++i) {
        if (licensePlate == parkingLot[i].licensePlate) {
            cout << "The vehicle has been assigned the parking slot number = " << i+1 << endl;
            return &parkingLot[i];
        }
    }
    cout << "The vehicle has not been assigned the parking slot." << endl;
    return nullptr;
}

void parkVehicle(Vehicle parkingLot[], int vehicleCount, const string& licensePlate) {
    for (int i = 0; i <= vehicleCount; ++i) {
        if (licensePlate == parkingLot[i].licensePlate) {
            cout<<"Enter starting time of car in hour : ";
            cin>>startTime1[i];
            cout<<"Enter start time in minutes: ";
            cin>>startTime2[i];
            cout << "You have parked the vehicle with license plate " << parkingLot[i].licensePlate << endl;
            parkingLot[i].isParked = true;
        }
    }
}

void leaveParkingLot(Vehicle parkingLot[], int vehicleCount, const string& licensePlate) {
    for (int i = 0; i <= vehicleCount; ++i) {
        if (licensePlate == parkingLot[i].licensePlate) {
            cout<<"Enter ending time of car in in hour : ";
            cin>>endTime1[i];
            cout<<"Enter ending time of car in in minutes : ";
            cin>>endTime2[i];
            // timeCalculation();
            result1[i] = endTime1[i] - startTime1[i];
            if(result1[i]<=0){
                result1[i] = result1[i] + 12;
            }
            result2[i] = endTime2[i]-startTime2[i];
            if(result2[i]<0){
                result2[i] = result2[i]+ 60;
                result1[i] = result1[i]-1;
            }
            cout<<"Your time duration is : "<<result1[i]<<":"<<result2[i]<<endl;
            float bill;
            int min;
            int total_min;
            min=60*result1[i];
            total_min=min+result2[i];
            bill=0.06*total_min;
            cout<<"Your total bill is = > $"<<bill<<endl;
            cout << "You have left the parking slot with vehicle license plate " << parkingLot[i].licensePlate << endl;
            parkingLot[i].isParked = false;
        }
    }
}

void saveParkingLotToFile(const Vehicle parkingLot[], int vehicleCount, const std::string& filename) {
    ofstream file(filename + ".txt");
    if (file.is_open()) {
        for (int i = vehicleCount - 1; i >= 0; --i) {
            file << "License Plate: " << parkingLot[i].licensePlate << endl;
            file << "Model: " << parkingLot[i].model << endl;
            file << "Year: " << parkingLot[i].year << endl;
            file << "Is Parked: " << (parkingLot[i].isParked ? "Yes" : "No") << endl;
        }
        cout << "Data is written into the file successfully." << endl;
    }
    else {
        cout << "Data is not written into the file." << endl;
    }
    file.close();
}

void displayparkinglot_info( const string& filename){
    ifstream file(filename + ".txt");
    if (file.is_open())
    {
        cout<<"Record of the parking lot has been loaded."<<endl;
        cout<<"DO YOU WANT TO DISPLAY THE RECORD ? =>";
        string y;
        cin>>y;
        if (y=="yes")
        {
            string line;
            while (getline(file, line))
            {
                cout<<line<< endl;
            }
        }
    }
    else
    {
        cout<<"could not load information."<<endl;
    }
}