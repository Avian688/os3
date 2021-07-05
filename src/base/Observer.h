//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __OS3_Observer_H__
#define __OS3_Observer_H__

#include <omnetpp.h>

#include <iostream>
#include <fstream>
#include <ctime>

class SatSGP4Mobility;
class SatSGP4FisheyeMobility;
class Calculation;

using namespace omnetpp;
//-----------------------------------------------------
// Class: Observer
// Base Station with example function to check when a satellite is in
// view or to calculate the C/N0 (carrier to noise) for GPS satellites
//-----------------------------------------------------
class Observer : public cSimpleModule
{
public:
    Observer();

protected:

    // initializes Observer module and calls setPosition()
    virtual void initialize();

    // checks every update interval if a certain satellite is in view and writes results to an output file
    virtual void handleMessage(cMessage* msg);

    virtual void finish();

    // sets the position on the map
    void setPosition(double latitude, double longitude);

    // calculates SNR for given satellite
    // - satindex index of satellite
    // - bandwidth bandwidth of used channel
    double checksnr(int satindex, double bandwidth);

private:
    SatSGP4Mobility* Sat;                // Reference to observed satellite
    SatSGP4FisheyeMobility* gpsSats[31]; // GPS satellites for C/N0 validation
    Calculation* calculation;
    cMessage* timer;                     // Self message to trigger observation
    double longitude;                    // Longitude of Observer
    double latitude;                     // Latitude of Observer
    double altitude;                     // Altitude of Observer
    double lastelv;                      // Last observed elevation is saved
    double interval;                     // Update interval for timer
    std::ofstream outfile;               // File where results are written/saved
    std::time_t timestamp;               // Time stamp for starting simulation
    int numgps;                          // Number of GPS satellites for C/N0 validation
    bool gps;                            // bool to check whether gps or ISS validation should run
};

#endif
