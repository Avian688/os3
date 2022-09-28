
package os3.simulations.SatSGP4;

import os3.base.Satellite;
import os3.base.MissionControlCenter;
import os3.base.CNI_OS3;
import inet.visualizer.contract.IIntegratedVisualizer;


network SatSGP4
{
    parameters:
        int numOfSats; // Number of satellites
        int numOfMCCs; // Number of Mission Control Centers
        @display("bgi=background_earth,s;bgb=2160,1080");
    submodules:
        visualizer: <default(firstAvailableOrEmpty("IntegratedCanvasVisualizer"))> like IIntegratedVisualizer if typename != "" {
            parameters:
                @display("p=100,400;is=s");
        }
        satellite[numOfSats]: Satellite { 
            parameters:
                @display("p=238.04,327.305;i=satellit_blue");
        }
        MCC[numOfMCCs]: MissionControlCenter {
            parameters:
                @display("p=238.04,343.535;r=10;i=device/receiverdish");
        }
        cni_os3: CNI_OS3 {
            @display("p=80,70,i;i=old/bluebox");
        }
    connections allowunconnected:
}

