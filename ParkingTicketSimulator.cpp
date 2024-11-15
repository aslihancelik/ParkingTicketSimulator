// ParkingTicketSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ParkingSimulator.h"
#include "ParkingTicket.h"
#include <iostream>

int main()
{
    int isThereViolation;

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
    }
}

