// ParkingTicket.cpp

#include "ParkingTicket.h"

// Constructor for ParkingTicket
ParkingTicket::ParkingTicket(const ParkedCar& c, const ParkingMeter& m, const PoliceOfficer& o)
    : car(c), meter(m), officer(o) {
    // Calculate the fine for the violation
    int overparkedMinutes = car.getMinutesParked() - meter.getPurchasedMinutes();
    fine = calculateFine(overparkedMinutes);  // Call the helper method to compute the fine
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
    std::cout << "*** Parking Ticket ***\n";
    std::cout << "Officer " << officer.getName() << " Badge Number " << officer.getBadgeNumber() << "\n";
    std::cout << "Vehicle License Number: " << car.getLicenseNumber() << "\n";
    std::cout << "Make: " << car.getMake() << " Model: " << car.getModel() << " Color: " << car.getColor() << "\n";
    std::cout << "Meter Minutes: " << meter.getPurchasedMinutes() << "\n";
    std::cout << "Minutes Parked: " << car.getMinutesParked() << "\n";
    std::cout << "Parking Fee: $" << fine << "\n";
}
