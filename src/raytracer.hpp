#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP
#include <iostream>

#include "utils\utils.hpp"
#include "camera.hpp"
#include "hittable\hittable_list.hpp"

class Raytracer{
public:

  Raytracer(size_t image_width = 128, size_t image_height = 72)
  : image_width(image_width)
  , image_height(image_height)
  , aspect_ratio(double(image_width) / image_height)
  , camera(aspect_ratio)
  {
    std::cout << "Initializing raytracer...\n";
    std::cout << "Output image size: " << image_width << " x " 
              << image_height << " "
              << "Aspect ratio: " << aspect_ratio << "\n";
    initialize();
  }

  int render(std::ostream &out_image);

private:
  size_t image_width;
  size_t image_height;
  double aspect_ratio;

  Camera camera;

  HittableList world;

  int initialize();
};

#endif
