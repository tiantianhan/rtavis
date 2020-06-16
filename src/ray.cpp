#include "ray.hpp"
#include "utils/vec3.hpp"

Point3 Ray::origin() const{
  return orig;
}

Point3 Ray::direction() const{
  return dir;
}

Point3 Ray::at(double t) const{
  return orig + t * dir;
}
