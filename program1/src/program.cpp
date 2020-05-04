//
//  program.cpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Car.hpp"
#include "Reservation.hpp"
#include "program.hpp"
#include "UnorderedArrayListCar.hpp"
#include "UnorderedArrayListReservation.hpp"

using namespace std;

void Program::begin() {
    
    UnorderedArrayListCar* carList = new UnorderedArrayListCar();
    UnorderedArrayListReservation* reservationList = new UnorderedArrayListReservation();
    
    bool run = true;
    
    while(run) {
        string input;
        cout << "-------------------------------------------\nXYZ Car Rental\n-------------------------------------------\n1. List all cars\n2. Add car to inventory\n3. Remove car from inventory\n4. List all reservations\n5. Add a reservations\n6. Cancel reservation\n7. Exit\n";
        
        cin >> input;
        
        if(input == "1") {
            cout << *carList << endl;
        } else if(input == "2") {
            cout << "\n\nEnter Plate Number: ";
            string plateNumber;
            cin >> plateNumber;
            
            cout << "Enter Make: ";
            string make;
            cin >> make;
            
            cout << "Enter Model: ";
            string model;
            cin >> model;
            
            cout << "Enter Vehicle Type (0 for sedan, 1 for suv, or 2 for exotic): ";
            int type;
            cin >> type;
            
            cout << "Enter Price Per Day: ";
            double pricePerDay;
            cin >> pricePerDay;
            
            carList->PutItem(Car(plateNumber, make, model, (vehicleType)type, pricePerDay, true));
            
        } else if(input == "3") {
            string plateNumber;
            cout << "Please enter the plate number of the car to remove: ";
            cin >> plateNumber;
            carList->DeleteItem(carList->GetItem(plateNumber));
        } else if(input == "4") {
            cout << *reservationList << endl;
        } else if(input == "5") {
            string name;
            cout << "Please enter the name for the reservation: ";
            cin >> name;
            
            int index;
            carList->OutputAvailable();
            cin >> index;
            if(index-1 != carList->GetLength()) {
                reservationList->PutItem(Reservation(name, carList->GetItemAtIndex(index-1).getPlateNumber()));
                carList->GetItemAtIndex(index-1).setAvailable(false);
            }
            
        } else if(input == "6") {
            string name;
            cout << "Please enter the name of the reservation to remove: ";
            cin >> name;
            carList->GetItem(reservationList->GetItem(name).getVehicleRented()).setAvailable(true);
            reservationList->DeleteItem(reservationList->GetItem(name));
            
        } else if(input == "7") {
            run = false;
        }
    }
    
    
    cout << endl;
}

