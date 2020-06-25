// Image output test
#include <iostream>
#include <fstream>
#include <cmath>

#include "..\tests\test.hpp"
#include "raytracer.hpp"

int main(void){
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 768;
  const int image_height = round(image_width / aspect_ratio);

  std::cout << "Opening output file...\n";
  std::ofstream out_image;
  out_image.open("out\\test.ppm");

  Raytracer raytracer(image_width, image_height);
  raytracer.samples_per_pixel = 100;
  raytracer.max_ray_recursion_depth = 50;

  raytracer.render(out_image);
  

  // TODO: Write more tests?
  // Test
  // std::cout << "\nTesting...\n";
  // test();

  std::cout << "All done.\n";

  return 0;
}
