
package os3.simulations.Validation;

import os3.base.Satellite;
import inet.physicallayer.wireless.common.contract.packetlevel.IRadioMedium;
import os3.base.CNI_OS3;
import os3.base.Observer;

//
// Network Validate used to show Observer functionalities
//
network Validate
{
    parameters:
        int numOfSats;

        @display("bgi=background_earth;bgb=2160,1080");

    submodules:
        satellite[numOfSats]: Satellite {
            parameters:
                @display("p=80,200;r=10,,#707070;i=device/satellite_l");
        }
        radioMedium: <default("UnitDiskRadioMedium")> like IRadioMedium {
            parameters:
                //numChannels = 2;
                @display("p=220,70;i=misc/sun");
        }
        cni_os3: CNI_OS3 {
            @display("p=80,70,i;i=old/bluebox");
        }
        observer: Observer {
            numgps = 0;
            @display("p=220,200");
        }
    connections allowunconnected:
}
