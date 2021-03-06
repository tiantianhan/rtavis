#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP
#include <iostream>

#include "utils\utils.hpp"
#include "camera.hpp"
#include "hittable\hittable_list.hpp"
#include "ray.hpp"
#include "utils\vec3.hpp"
#include "utils\color.hpp"

class Raytracer{
public:

  Raytracer(size_t image_width = 128, size_t image_height = 72)
  : image_width(image_width)
  , image_height(image_height)
  , aspect_ratio(double(image_width) / image_height)
  , samples_per_pixel(50)
  , camera(aspect_ratio, 80)
  , max_ray_recursion_depth(25)
  {
    std::cout << "Initializing raytracer...\n";
    std::cout << "Output image size: " << image_width << " x " 
              << image_height << " "
              << "Aspect ratio: " << aspect_ratio << "\n";
    initialize();
  }

  int load_default_world();
  int load(std::ifstream &in_file);
  int render(std::ostream &out_image);

  size_t samples_per_pixel;
  size_t max_ray_recursion_depth;

private:
  size_t image_width;
  size_t image_height;
  double aspect_ratio;

  Camera camera;

  HittableList world;

  static const Color shading_error_color;
  static const Color back_face_color;

  int initialize();
  Color ray_color(const Ray &r, HittableList world, int depth);
  Color ray_color_gradient(const Ray &r);

  int get_default_world();
};

#endif
