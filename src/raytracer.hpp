#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP
#include <iostream>
#include <cmath>
#include "utils\vec3.hpp"

class Raytracer{
public:
  Raytracer(size_t image_width = 128, size_t image_height = 72){
    std::cout << "Initializing raytracer...\n";
    this->image_width = image_width;
    this->image_height = image_height;
    aspect_ratio = double(image_width) / image_height;
    std::cout << "Output image size: \n" << image_width << ' ' << image_height << "\n";
    std::cout << "Aspect ratio: \n" << aspect_ratio << "\n";

    initialize();
  }

  int render(std::ostream &out_image);

private:
  size_t image_width;
  size_t image_height;
  double aspect_ratio;

  Point3 origin;
  double viewport_height;
  double viewport_width;
  double focal_length;

  int initialize();
};

#endif
