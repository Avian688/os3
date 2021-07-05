# OS3 Satellite mobility models for OMNeT++/INET-Framework
This project provides mobility modules that can be used during satellite communication modeling. It is a ported version of the orginal OS3 framework, which was originally developed at the Communication Networks Institute, TU Dortmund, Germany.

Read the Installation Guide to configure extra dependencies and web service access for live weather data. The Installation Guide outlines outdated dependancies, therefore make sure that the latest requirements are installed.

Once the installation guide has been followed for your currrent system. Do this following steps within the command line to build the OS3 framework:
The following example is done on a Linux system, therefore it is important that the directories are correct for your system.

cd $HOME/omnetpp-5.6.2
. setenv
cd samples/os3/src/

**This must be the src directory of the OS3 framework**

opp_makemake --make-so -f --deep -KINET4_PROJ=$HOME/omnetpp-5.6.2/samples/inet4 -I/usr/local/opt/curl/include/curl '-I$(INET4_PROJ)/src' '-L$(INET4_PROJ)/src' '-lINET$(D)' -lcurl

**This command generates the make file. Make sure that the paths are correct for curl and INET. Depending on how INET was installed, it could appear as INET4 or simply INET. The above command line command must be changed accordingly depending on this. For example, INET4_PROJ would become INET_PROJ etc.**

make MODE=release && make MODE=debug

**This command builds the shared libary for OS3.**

**It is then important to set the environment variables within the command line. To do this the following commands must be entered into the command line (Unix):**

.vi bashrc

press ENTER

shift G to get to the end of the file
shift A to get the end of the current line
enter, to get to the next line

**And then write the following variables (making sure they are correct directories to your system):**

export NEDPATH=$HOME/omnetpp-5.6.2/samples/inet/src:$HOME/omnetpp-5.6.2/samples/inet/examples:$HOME/omnetpp-5.6.2/samples/inet/tutorials:$HOME/omnetpp-5.6.2/samples/inet/showcases
export NEDPATH=$NEDPATH:$HOME/os3/src:$HOME/os3/simulations
export LD_LIBRARY_PATH=$HOME/omnetpp-5.6.2/lib:$HOME/os3/src:$HOME/omnetpp-5.6.2/samples/inet/src
export OMNETPP_IMAGE_PATH=$HOME/omnetpp-5.6.2/images:$HOME/omnetpp-5.6.2/samples/inet/images:$HOME/os3/images

**Now simulations can be ran. To test a simulation, you must change to the directory of the simulation to test. For example: **

cd $HOME/omnetpp-5.6.2/samples/os3/simulations/SatSGP4

**Then the following command must be used to run this simulation:**

opp_run_dbg -m -l ../../src/os3 omnetpp.ini

**This command is for debug mode, for release mode opp_run is instead used**




