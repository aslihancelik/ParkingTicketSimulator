// ParkingTicket.h
//
// This file consists of the declaration of ParkingTicket instance variables and member functions.
//

#pragma once

#include "ParkingSimulator.h"

// ParkingTicket Class Declaration
class ParkingTicket {
private:
    ParkedCar car;
    ParkingMeter meter;
    PoliceOfficer officer;
    int fine;
public:
    ParkingTicket(const ParkedCar& c, const ParkingMeter& m, const PoliceOfficer& o);
    int calculateFine(int overparkedMinutes) const;
    void printTicket() const;
};