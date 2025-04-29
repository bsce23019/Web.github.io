#include <iostream>
// include your custom library here
#include <string>
#include "functions.h"
using namespace std;

int main() {
    cout<<""<<endl;
    cout<<"     !!!!!   WELCOME TO KING BASEMENT   !!!!!     "<<endl;
    cout<<""<<endl;
    int vehicleCount = 0;
    int choice;

    Vehicle* parkingLot = new Vehicle[100];

    do {
        cout << "Enter 0 to exit." << endl;
        cout << "To book tour parking slot, enter 1." << endl;
        cout << "To display your vehicles and parking slot number, enter 2." << endl;
        cout << "To search for a vehicle, enter 3." << endl;
        cout << "To park a vehicle, enter 4." << endl;
        cout << "To leave the parking lot, enter 5." << endl;
        cout << "To save your car in the parking lot to a file, enter 6." << endl;
        cout << "To save the parking lot file, enter 7." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"..........\n..........\n.........."<<endl;
        if(choice==1){
            addVehicle(parkingLot, vehicleCount);
            cout<<"..........\n..........\n.........."<<endl;
        }
        if(choice==2){
            displayVehicles(parkingLot, vehicleCount);
            cout<<"..........\n..........\n.........."<<endl;
        }
        if(choice==3){
            cout<<"Enter License Plate for searching : ";
            string name;
            cin.ignore();
            getline(cin,name);
            searchVehicle(parkingLot, vehicleCount, name);
            cout<<"..........\n..........\n.........."<<endl;
        }
        if(choice==4){
            cout<<"Enter License Plate for get Car : ";
            string name;
            cin.ignore();
            getline(cin,name);
            parkVehicle(parkingLot, 10, name);
            cout<<"..........\n..........\n.........."<<endl;
        }
        if(choice==5){
            cout<<"EnterLicense Plate for get Car : ";
            string name;
            cin.ignore();
            getline(cin,name);
            leaveParkingLot(parkingLot, 10, name);
            cout<<"..........\n..........\n.........."<<endl;
        }
        if(choice==6){
            saveParkingLotToFile(parkingLot, vehicleCount, "parking_lot");
            cout<<"..........\n..........\n.........."<<endl;
        }
        if(choice==7){
            displayparkinglot_info("parking_lot");
            cout<<"..........\n..........\n.........."<<endl;
        }

    } while (choice != 0);

    delete[] parkingLot;

    return 0;
}