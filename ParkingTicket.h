#pragma once

#include "ParkingSimulator.h"

// ParkingTicket Class Declaration
class ParkingTicket {
private:
    ParkedCar car;
    ParkingMeter meter;
    PoliceOfficer officer;
    int fine;

    int calculateFine(int overparkedMinutes) const;

public:
    ParkingTicket(const ParkedCar& c, const ParkingMeter& m, const PoliceOfficer& o);
    void printTicket() const;
};