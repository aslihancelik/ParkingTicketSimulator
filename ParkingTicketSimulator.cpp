// ParkingTicketSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ParkingSimulator.h"
#include "ParkingTicket.h"
#include <iostream>
#include <vector>

int main()
{

    // Test cases data
    vector<int> meterMinutes = { 60 }; // All test cases use the same meter minutes
    vector<int> parkedMinutes = { 45, 65, 120, 150, 180, 200, 240, 300, 350 };

    // Edge case test data
    std::vector<std::pair<int, int>> edgeCases = {
        {60, 60},   // Exactly the purchased time
        {60, 0},    // Car parked for zero minutes
        {0, 10},    // Purchased time is zero
        {60, 61},   // Just over an hour
        {60, -10}   // Invalid parked time
    };

    // Officer and vehicle data
    PoliceOfficer officer("Mark Smith", "B123456");
    ParkedCar car("Hyundai", "Sonata", "Silver", "A12345");


    // Iterate over test cases
    for (int minutesParked : parkedMinutes) {
        // Set up test case
        ParkingMeter meter(meterMinutes[0]);
        ParkedCar testCar(car.getMake(), car.getModel(), car.getColor(), car.getLicenseNumber(), minutesParked);

        std::cout << "Testing case: Meter minutes = " << meter.getPurchasedMinutes()
            << ", Car parked = " << testCar.getMinutesParked() << "\n";

        // Check for violation
        if (officer.examineViolation(testCar, meter)) {
            // Generate and display ticket
            ParkingTicket ticket(testCar, meter, officer);
            ticket.printTicket();
        }
        else {
            std::cout << "No parking violation.\n";
        }

        std::cout << "------------------------------\n";
    }

    cout << "Edge Cases:\n";
    for (const pair<int, int>& edgeCase : edgeCases) {
        int purchasedTime = edgeCase.first;
        int minutesParked = edgeCase.second;

        ParkingMeter meter(purchasedTime);
        ParkedCar testCar(car.getMake(), car.getModel(), car.getColor(), car.getLicenseNumber(), minutesParked);

        std::cout << "Testing case: Meter minutes = " << meter.getPurchasedMinutes()
            << ", Car parked = " << testCar.getMinutesParked() << "\n";

        if (minutesParked < 0) {
            std::cout << "Invalid parked time. No action taken.\n";
        }
        else if (officer.examineViolation(testCar, meter)) {
            ParkingTicket ticket(testCar, meter, officer);
            ticket.printTicket();
        }
        else {
            std::cout << "No parking violation.\n";
        }
        std::cout << "------------------------------\n";
    }



   /* int isThereViolation;

    ParkedCar car("NISSAN", "ROUGE", "WHITE", "XXX-0000", 90);
    ParkingMeter meter(30);
    PoliceOfficer officer("POLICE RICH", "THEBADGE");

    isThereViolation = officer.examineViolation(car, meter);

    if (isThereViolation) {
        cout << "There is a Parking violation. Here is your parking ticket." << endl;
        ParkingTicket ticket(car, meter, officer);
        ticket.printTicket();
    }
    else {
        cout << "There is no parking violation." << endl;
    }*/

    return 0;
}

