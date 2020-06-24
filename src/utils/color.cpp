#include "color.hpp"

#include <iostream>
#include "vec3.hpp"
#include "utils.hpp"

void write_color(std::ostream &out, Color pixel_color){
  out << static_cast<int>(256 * clamp(pixel_color.x(), 0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(pixel_color.y(), 0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(pixel_color.z(), 0, 0.999)) << '\n';
}
