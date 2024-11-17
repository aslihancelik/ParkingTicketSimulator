// ParkingSimulator.h
// This file consist of decalrations and inline implementations of the ParkedCar, ParkingMeter and PoliceOfficer classes.

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

    //Constructor
	ParkedCar(string mk = "MAKE", string ml = "MODEL", string co = "COLOR", string ln = "LICENSE", int mn=0)
		: make(mk), model(ml), color(co), licenseNumber(ln) {
    
        setMinutesParked(mn);
    
    
    }
    //setting the parked minutes with input validation
    void setMinutesParked(int minutes){
        if (minutes >= 0) {
            minutesParked = minutes;
        }
        else {
            throw invalid_argument("Invalid entry for minutes parked. Minutes parked has to be a nonnegative number.");
        }
    }
    //Getters
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
    //constructor
	ParkingMeter(int minutes = 0) {
        setPurchasedMinutes(minutes);
    }


    //setter
    void setPurchasedMinutes(int mins) {
        if (mins < 0) {
            throw invalid_argument("Invalid entry for purchased minutes.Purchased minutes has to be a nonnegative ineteger.");
        }
        else {
            purchasedMinutes = mins;
        }
    
    
    }
    //getter
	int getPurchasedMinutes() const { return purchasedMinutes; }
};


class PoliceOfficer {

private:

    string name;
    string badgeNumber;

public:

    //constructor
    PoliceOfficer(string n = "OFFICER", string bn = "BADGE")
        : name(n), badgeNumber(bn) {
    
    }

    //getters
    string getName() const { return name; }
    string getBadgeNumber() const { return badgeNumber; }

    
    // Examine if the car has been parked longer than the purchased time
    bool examineViolation(const ParkedCar& car, const ParkingMeter& meter) const {

        return car.getMinutesParked() > meter.getPurchasedMinutes();
    }

};

#endif // PARKINGSIMULATION_H