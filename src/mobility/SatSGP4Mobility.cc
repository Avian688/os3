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

#include "SatSGP4Mobility.h"
#include "../libnorad/cJulian.h";

#include <ctime>
#include <cmath>

#include "Norad.h"

Define_Module(SatSGP4Mobility);

SatSGP4Mobility::SatSGP4Mobility()
{
   noradModule = nullptr;
   mapX = 0;
   mapY = 0;
   transmitPower = 0.0;
}

void SatSGP4Mobility::initialize(int stage)
{
    // noradModule must be initialized before LineSegmentsMobilityBase calling setTargetPosition() in its initialization at stage 1
    if (stage == 1) {
        noradModule->initializeMobility(nextChange);
    }
    LineSegmentsMobilityBase::initialize(stage);

    noradModule = check_and_cast< Norad* >(getParentModule()->getSubmodule("NoradModule"));
    if (noradModule == nullptr) {
        error("Error in SatSGP4Mobility::initializeMobility(): Cannot find module Norad.");
    }

    //std::time_t timestamp = std::time(nullptr);       // get current time as an integral value holding the num of secs
    std::time_t timestamp =  1619119189;  //8:20PM 22/04/2021                                             // since 00:00, Jan 1 1970 UTC
    std::tm* currentTime = std::gmtime(&timestamp);   // convert timestamp into structure holding a calendar date and time
    noradModule->setJulian(currentTime);

    mapX = std::atoi(getParentModule()->getParentModule()->getDisplayString().getTagArg("bgb", 0));
    mapY = std::atoi(getParentModule()->getParentModule()->getDisplayString().getTagArg("bgb", 1));

    transmitPower = getParentModule()->par("transmitPower");

    EV << "initializing SatSGP4Mobility stage " << stage << endl;
    WATCH(lastPosition);

    move(); //updateVisualRepresentation();
}

bool SatSGP4Mobility::isOnSameOrbitalPlane(double raan2, double inclination2)
{
    bool samePlane = false;
    double raan = getRaan();
    double inclination = getInclination();
    if((inclination >= inclination2-1 && inclination <= inclination2+1))
    {
        return true;
    }
}

double SatSGP4Mobility::getAltitude() const
{
    return noradModule->getAltitude();
}

double SatSGP4Mobility::getElevation(const double& refLatitude, const double& refLongitude,
                                     const double& refAltitude) const
{
    return noradModule->getElevation(refLatitude, refLongitude, refAltitude);
}

double SatSGP4Mobility::getAzimuth(const double& refLatitude, const double& refLongitude,
                                   const double& refAltitude) const
{
    return noradModule->getAzimuth(refLatitude, refLongitude, refAltitude);
}

double SatSGP4Mobility::getDistance(const double& refLatitude, const double& refLongitude,
                                    const double& refAltitude) const
{
    return noradModule->getDistance(refLatitude, refLongitude, refAltitude);
}

double SatSGP4Mobility::getLongitude() const
{
    return noradModule->getLongitude();
}

double SatSGP4Mobility::getLatitude() const
{
    return noradModule->getLatitude();
}

double SatSGP4Mobility::getRaan() const
{
    return noradModule->getRaan();
}

double SatSGP4Mobility::getInclination() const
{
    return noradModule->getInclination();
}

void SatSGP4Mobility::setTargetPosition()
{
    nextChange += updateInterval.dbl();
    noradModule->updateTime(nextChange);
    //noradModule->getParentModule()->getSubmodule("coordinateSystem")->
    //EV << "SATELLITE MAPX" << mapX << "MAPY " << mapY << "LONG " << noradModule->getLongitude() << "LAT " << noradModule->getLatitude();
    lastPosition.x = mapX * noradModule->getLongitude() / 360 + (mapX / 2);
    lastPosition.x = static_cast<int>(lastPosition.x) % static_cast<int>(mapX);
    lastPosition.y = ((-mapY * noradModule->getLatitude()) / 180) + (mapY / 2);
    targetPosition.x = lastPosition.x;
    targetPosition.y = lastPosition.y;
}

void SatSGP4Mobility::move()
{
    LineSegmentsMobilityBase::move();
    raiseErrorIfOutside();
}

void SatSGP4Mobility::fixIfHostGetsOutside()
{
    raiseErrorIfOutside();
}
