// Image output test
#include <iostream>
#include <fstream>
#include "utils\vec3.hpp"
#include "utils\color.hpp"
#include "tests\test.hpp"

int main(void){
  const int image_width = 256;
  const int image_height = 256;

  std::ofstream out_image;
  out_image.open("out\\test.ppm");

  out_image << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for(int j = image_height-1; j >= 0; --j){
    std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;

    for(int i = 0; i < image_width; ++i){
      Color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);

      write_color(out_image, pixel_color);
    }
    out_image << '\n';
  }
  std::cout << "\nDone.\n";

  // Test
  // std::cout << "\nTesting...\n";
  // test();

  return 0;
}
