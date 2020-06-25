#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include "vec3.hpp"


inline void gamma2_correct(Color& color){
  color.e[0] = sqrt(color.e[0]);
  color.e[1] = sqrt(color.e[1]);
  color.e[2] = sqrt(color.e[2]);
}

void write_color(std::ostream &out, Color pixel_color);

#endif
