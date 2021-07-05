
package os3.mobility;

import inet.mobility.base.MovingMobilityBase;

//
// Manages the SatSGP4 Mobility
//
simple SatSGP4Mobility extends MovingMobilityBase
{
    parameters:
        @class(SatSGP4Mobility);
        @display("i=block/cogwheel_s");
        //double updateInterval @unit(s); // Time interval to update the hosts position
}
