//-----------------------------------------------------
// globals
//-----------------------------------------------------
#ifndef __LIBNORAD_Globals_H__
#define __LIBNORAD_Globals_H__

#include <cmath>

#ifndef PI
#define PI  3.1415926535
#endif //PI

//const double PI           = 3.141592653589793;
const double TWOPI        = 2.0 * PI;
const double RADS_PER_DEG = PI / 180.0;

const double GM           = 398601.2;   // Earth gravitational constant, km^3/sec^2
const double GEOSYNC_ALT  = 42241.892;  // km
const double EARTH_DIA    = 12800.0;    // km
const double DAY_SIDERAL  = (23 * 3600) + (56 * 60) + 4.09;  // sec
const double DAY_24HR     = (24 * 3600);   // sec

const double AE           = 1.0;
const double AU           = 149597870.0;  // Astronomical unit (km) (IAU 76)
const double SR           = 696000.0;     // Solar radius (km)      (IAU 76)
const double TWOTHRD      = 2.0 / 3.0;
const double XKMPER_WGS72 = 6378.135;     // Earth equatorial radius - km (WGS '72)
const double F            = 1.0 / 298.26; // Earth flattening (WGS '72)
const double GE           = 398600.8;     // Earth gravitational constant (WGS '72)
const double J2           = 1.0826158E-3; // J2 harmonic (WGS '72)
const double J3           = -2.53881E-6;  // J3 harmonic (WGS '72)
const double J4           = -1.65597E-6;  // J4 harmonic (WGS '72)
const double CK2          = J2 / 2.0;
const double CK4          = -3.0 * J4 / 8.0;
const double XJ3          = J3;
const double E6A          = 1.0e-06;
const double QO           = AE + 120.0 / XKMPER_WGS72;
const double SV            = AE + 78.0  / XKMPER_WGS72; //Changed - Aiden Valentine
const double HR_PER_DAY   = 24.0;          // Hours per day   (solar)
const double MIN_PER_DAY  = 1440.0;        // Minutes per day (solar)
const double SEC_PER_DAY  = 86400.0;       // Seconds per day (solar)
const double OMEGA_E      = 1.00273790934; // earth rotation per sideral day
const double XKE          = std::sqrt(3600.0 * GE /           //sqrt(ge) ER^3/min^2
                                (XKMPER_WGS72 * XKMPER_WGS72 * XKMPER_WGS72));
const double QOMS2T       = std::pow((QO - SV), 4);            //(QO - S)^4 ER^4


//New constants required for ECEF coordinate generation - Aiden Valentine
const double SEMI_MAJOR_AXIS = 6378137.0;  //Semi-Major Axis (m)
const double SEMI_MINOR_AXIS = 6356752.314245;
// Utility functions
double sqr   (const double x);
double Fmod2p(const double arg);
double AcTan (const double sinx, double cosx);

double rad2deg(const double);
double deg2rad(const double);

#endif
