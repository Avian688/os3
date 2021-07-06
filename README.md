# OS3 Satellite mobility models for OMNeT++/INET-Framework

This project provides mobility modules that can be used during satellite communication modeling. It is a ported version of the orginal OS3 framework, which was originally developed at the Communication Networks Institute, TU Dortmund, Germany.

Read the Installation Guide to configure extra dependencies and web service access for live weather data. The Installation Guide outlines outdated dependencies, therefore make sure that the latest requirements are installed.

Once the installation guide has been followed for your currrent system, follow the steps below through the command line to build the OS3 framework. The following example is done on a Linux system, but the setup should be almost identical for macOS.

\# we assume that os3 is cloned under $HOME/omnetpp-5.6.2/samples  
cd samples/os3/src/  
  
\# note that depending on how inet is installed, it may appear as _inet_ or _inet4_ (we use _inet_ here)  
\# this command generates the makefile. Make sure that the paths are correct for curl and INET (the INET4_PROJ variable).  
opp_makemake --make-so -f --deep -KINET4_PROJ=$HOME/omnetpp-5.6.2/samples/inet -I/usr/local/opt/curl/include/curl '-I$(INET4_PROJ)/src' '-L$(INET4_PROJ)/src' '-lINET$(D)' -lcurl  

\# compile for both release and debug modes (assumes that INET is also compiled and the respective shared libraries are under $(INET4_PROJ)/src  
\# this command builds the shared library for OS3  
make MODE=release && make MODE=debug  

To make running simulation through the command line easier. it is advised to export the NEDPATH variable with all relevant paths that contain .ned files. If not, all these paths must be included when running a simulation (using the -n flag supported by _opp_run_ and _opp_run_dbg_).  


export NEDPATH=$HOME/omnetpp-5.6.2/samples/inet/src:$HOME/omnetpp-5.6.2/samples/inet/examples:$HOME/omnetpp-5.6.2/samples/inet/tutorials:$HOME/omnetpp-5.6.2/samples/inet/showcases  
export NEDPATH=$NEDPATH:$HOME/os3/src:$HOME/os3/simulations  

\# OMNETPP_IMAGE_PATH is where images used by Qtenv are stored - helpful to have it here, instead of including with _opp_run_  
export OMNETPP_IMAGE_PATH=$HOME/omnetpp-5.6.2/images:$HOME/omnetpp-5.6.2/samples/inet/images:$HOME/os3/images  

Simulations can now be run, by first changing to the directory of the respective simulation. For example:  

cd $HOME/omnetpp-5.6.2/samples/os3/simulations/SatSGP4  

\# to run in debug mode  
opp_run_dbg -m -l ../../src/os3 omnetpp.ini  

\# to run in release mode  
opp_run -m -l ../../src/os3 omnetpp.ini  
