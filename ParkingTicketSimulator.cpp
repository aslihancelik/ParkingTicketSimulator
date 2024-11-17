// ParkingTicketSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program is a simulator of parking ticket issued to a violator by involving a parked car, parking meter,
// police officer.
//
//Programmer: Aslihan Aria Celik
//

#include "ParkingSimulator.h"
#include "ParkingTicket.h"
#include <iostream>
#include <vector>

int main()
{

    // Test cases data
    vector<int> meterMinutes = { 60 , 120, 180}; 
    vector<int> parkedMinutes = { 45, 65, 120, 150, 180, 200, 240, 300, 350 };

    // Officer and vehicle data
    PoliceOfficer officer("Mark Smith", "B123456");
    ParkedCar car("Hyundai", "Sonata", "Silver", "A12345");


    // Iterate over test cases

    for (int minutesMeter : meterMinutes) {
        for (int minutesParked : parkedMinutes) {

            // Set up test case
            ParkingMeter meter(minutesMeter);
            ParkedCar testCar(car.getMake(), car.getModel(), car.getColor(), car.getLicenseNumber(), minutesParked);

            cout << "Testing case: Meter minutes = " << meter.getPurchasedMinutes()
                << ", Car parked = " << testCar.getMinutesParked() << "\n";

            // Check for violation
            if (officer.examineViolation(testCar, meter)) {
                // Generate and display ticket
                ParkingTicket ticket(testCar, meter, officer);
                ticket.printTicket();
            }
            else {
                cout << "No parking violation.\n";
            }

            cout << "------------------------------\n";
        }
    }


    // Edge case test data
    //{purchasedTime, minutesParked}
    std::vector<std::pair<int, int>> edgeCases = {
        {60, 60},   // Exactly the purchased time
        {60, 0},    // Car parked for zero minutes
        {0, 10},    // Purchased time is zero
        {60, 61},   // Just over an hour
        {60, -10},  // Invalid parked time
        {-30, 10},  // Invalid purchased time
    };


    cout << "Edge Cases:\n";
    for (const pair<int, int>& edgeCase : edgeCases) {

        int purchasedTime = edgeCase.first;
        int minutesParked = edgeCase.second;

        try {
            ParkingMeter meter(purchasedTime);
            ParkedCar testCar(car.getMake(), car.getModel(), car.getColor(), car.getLicenseNumber(), minutesParked);
            cout << "Testing case: Meter minutes = " << meter.getPurchasedMinutes()
                << ", Car parked = " << testCar.getMinutesParked() << "\n";

            if (officer.examineViolation(testCar, meter)) {
                ParkingTicket ticket(testCar, meter, officer);
                ticket.printTicket();
            }
            else {
                cout << "No parking violation.\n";
            }
            cout << "------------------------------\n";
        }
        catch(const invalid_argument& e){
            //Handle the exception
            cout << "Error: " << e.what() << endl;
        }
        
    }

    return 0;
}

