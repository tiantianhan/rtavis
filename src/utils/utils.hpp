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

/**
 * Returns pseudo random number between 0 and 1.
 * 
 * @return random double in range [0, 1).
 */
inline double random_double(){
    //random number [0, 1)
    return rand() / (RAND_MAX  + 1.0);
}

/**
 * Returns pseudo random number in given range.
 * 
 * @param min lower range of random number, inclusive.
 * @param max upper range of random number, exclusive.
 * @return random double in range [min, max).
 */
inline double random_double(double min, double max){
    return min + random_double() * (max - min);
}

//TODO: create includes folder?
#include "..\ray.hpp"
#include "vec3.hpp"
#include "color.hpp"

#endif