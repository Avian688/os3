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

#include "LUTMotionMobility.h"
#include <cmath>

using namespace inet;
Define_Module(LUTMotionMobility);

void LUTMotionMobility::initialize(int stage)
{
    StationaryMobility::initialize(stage);
    EV << "initializing LUTMotionMobility stage " << stage << endl;
    if (stage == 0) {
        mapx = std::atoi(getParentModule()->getParentModule()->getDisplayString().getTagArg("bgb", 0));
        mapy = std::atoi(getParentModule()->getParentModule()->getDisplayString().getTagArg("bgb", 1));
        latitude = par("latitude");
        longitude = par("longitude");
    }
}

double LUTMotionMobility::getLUTPositionX() const
{
    return longitude;
}
double LUTMotionMobility::getLUTPositionY() const
{
    return latitude;
}

const Coord& LUTMotionMobility::getCurrentPosition()
{
    //return Coord(longitude, latitude);
    return lastPosition;
}


void LUTMotionMobility::setInitialPosition()
{
   lastPosition.x = ((mapx * longitude) / 360) + (mapx / 2);
   //lastPosition.x = (2160 + (longitude+180))/360;
   lastPosition.x = static_cast<int>(lastPosition.x) % static_cast<int>(mapx);

   lastPosition.y = ((-mapy * latitude) / 180) + (mapy / 2);
   lastPosition = Coord((((mapx * longitude) / 360) + (mapx / 2)), (((-mapy * latitude) / 180) + (mapy / 2)), 0);
   //lastPosition.y = (1080 + (latitude+90))/180;
}
