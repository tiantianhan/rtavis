// Image output test
#include <iostream>
#include <fstream>
#include <cmath>

#include "utils\vec3.hpp"
#include "utils\color.hpp"
#include "..\tests\test.hpp"
#include "ray.hpp"

Color ray_color_gradient(const Ray& r){
  Vec3 unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0); // Change y range to [0, 1]
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main(void){
  //TODO: Put main code in a class
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 384;
  const int image_height = round(image_width / aspect_ratio);
  std::cout << "Output image size: \n" << image_width << ' ' << image_height << "\n";

  //QUESTION: Viewport using homogenous coordinates?
  double viewport_height = 2.0;
  double viewport_width = aspect_ratio * viewport_height;
  double focal_length = 1.0;

  auto origin = Point3(0, 0, 0);
  auto horizontal = Vec3(viewport_width, 0, 0);
  auto vertical = Vec3(0, viewport_height, 0);
  Point3 lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);
  // focus plane is in -z space

  std::cout << "Opening output file...\n";
  std::ofstream out_image;
  out_image.open("out\\test.ppm");

  out_image << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for(int j = image_height-1; j >= 0; --j){
    std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;

    for(int i = 0; i < image_width; ++i){
      //TODO: Optimize inside of render nested for-loops
      auto u = double(i) / (image_width - 1);
      auto v = double(j) / (image_height - 1);

      //TODO: Use matrix to transform from viewport to image space?
      Ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);

      Color pixel_color = ray_color_gradient(r);

      write_color(out_image, pixel_color);
    }
    out_image << '\n';
  }
  std::cout << "\nDone.\n";

  // TODO: Write more tests?
  // Test
  // std::cout << "\nTesting...\n";
  // test();

  return 0;
}
