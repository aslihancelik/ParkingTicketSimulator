#ifndef PARKINGSIMULATION_H 
#define PARKINGSIMULATION_H
#include <string>
#include <iostream>


using namespace std;

class ParkedCar {
private:
	string make, model, color, licenseNumber;
	int minutesParked;

public:

	ParkedCar(string mk = "MAKE", string ml = "MODEL", string co = "COLOR", string ln = "LICENSE", int mn=0)
		: make(mk), model(ml), color(co), licenseNumber(ln), minutesParked(mn) {}

	int getMinutesParked() const { return minutesParked; }
	string getMake() const { return make; }
	string getModel() const { return model; }
	string getColor() const { return color; }
	string getLicenseNumber() const { return licenseNumber; }

};

class ParkingMeter {

private:
	int purchasedMinutes;

public:
	ParkingMeter(int minutes = 0) : purchasedMinutes(minutes) {}

	int getPurchasedMinutes() const { return purchasedMinutes; }
};


class PoliceOfficer {

private:

    string name;
    string badgeNumber;

public:
    PoliceOfficer(string n = "OFFICER", string bn = "BADGE")
        : name(n), badgeNumber(bn) {
    
    }

    string getName() const { return name; }
    string getBadgeNumber() const { return badgeNumber; }

    
    // Examine if the car has been parked longer than the purchased time
    bool examineViolation(const ParkedCar& car, const ParkingMeter& meter) const {

        return car.getMinutesParked() > meter.getPurchasedMinutes();
    }

   
    

    //ParkingTicket* issueTicket(const ParkedCar& car, const ParkingMeter& meter) {
    //    if (car.getMinutesParked() > meter.getPurchasedMinutes()) {
    //        return new ParkingTicket(car, meter, *this);  // Only issue ticket if violation
    //    }
    //    return nullptr;  // No violation
    //}

};

#endif // PARKINGSIMULATION_H