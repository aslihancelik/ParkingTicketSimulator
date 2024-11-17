// ParkingTicket.cpp
//
// This file is the implementation of parking ticket class which calculates the overparked minutes
// and the fine as well as printing the ticket.

#include "ParkingTicket.h"

// Constructor for ParkingTicket
ParkingTicket::ParkingTicket(const ParkedCar& c, const ParkingMeter& m, const PoliceOfficer& o)
    : car(c), meter(m), officer(o) {
    // Calculate the fine for the violation
    int overparkedMinutes = car.getMinutesParked() - meter.getPurchasedMinutes();
    fine = calculateFine(overparkedMinutes);  // Call the method to compute the fine
}

// Calculate the fine based on how many minutes the car is overparked
int ParkingTicket::calculateFine(int overparkedMinutes) const {
    if (overparkedMinutes <= 60) {
        return 25;  // $25 for the first hour or part of an hour
    }
    else {
        // $10 for each additional hour or part of an hour
        // +59 ensures any partial hour is rounded up when integer division is applied
        return 25 + ((overparkedMinutes - 60 + 59) / 60) * 10;
    }
}

// Print the parking ticket details
void ParkingTicket::printTicket() const {
    cout << "*** Parking Ticket ***\n";
    cout << "Officer " << officer.getName() << " Badge Number " << officer.getBadgeNumber() << "\n";
    cout << "Vehicle License Number: " << car.getLicenseNumber() << "\n";
    cout << "Make: " << car.getMake() << " Model: " << car.getModel() << " Color: " << car.getColor() << "\n";
    cout << "Meter Minutes: " << meter.getPurchasedMinutes() << " Minutes Parked: " << car.getMinutesParked() << "\n";
    cout << "Parking Fee: $" << fine << "\n";
}
