
package os3.base;
import os3.mobility.LUTMotionMobility;

// Bundles the analyzation and notification modules for the OS³ missions.
//
module MissionControlCenter
{
    parameters:
        string cityName = default("");
        string mobilityType = default("LUTMotionMobility"); // Define mobility module
        @display("t=$cityName");
        @node;

//    gates:
//        input radioIn; // Input gate
//        output radioOut; // Output gate

    submodules:
        mobility : LUTMotionMobility {
                    parameters:
                    @display("p=194,103");
                }
    connections allowunconnected: // Connections between compound gates and submodules

}
