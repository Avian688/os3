
package os3.mobility;

import inet.mobility.static.StationaryMobility;
import inet.mobility.contract.IMobility;

//
// Initializes the initial positions of Base Stations (LUT = Local User Terminal)
//
simple LUTMotionMobility extends StationaryMobility
{
    parameters:
        double latitude;
        double longitude;
        initFromDisplayString = false;
        updateFromDisplayString = false;
        @class(LUTMotionMobility);
}
