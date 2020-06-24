#ifndef RTWEEKEND_UTILS_HPP
#define RTWEEKEND_UTILS_HPP

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees){
    return degrees / 180 * pi;
}

//TODO: create includes folder?

#endif