
package os3.simulations.Validation;

import os3.base.Satellite;
import inet.physicallayer.contract.packetlevel.IRadioMedium;
import os3.base.CNI_OS3;
import os3.base.Observer;

network GPS
{
    parameters:
        int numOfSats;

        @display("bgi=binocular,c;bgb=980,980");

    submodules:
        satellite[numOfSats]: Satellite {
            parameters:
                @display("p=70,180;r=10,,#707070;i=device/satellite_l");
        }
        radioMedium: <default("UnitDiskRadioMedium")> like IRadioMedium {
            parameters:
                //numChannels = 2;
                @display("p=180,70;i=misc/sun");
        }
        cni_os3: CNI_OS3 {
            @display("p=50,70,i;i=old/bluebox");
        }
        observer: Observer {
            @display("p=490,490");
            numgps = numOfSats;
        }
    connections allowunconnected:
}

