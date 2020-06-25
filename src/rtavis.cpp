/**
 * @file rtavis.cpp
 * @author tina
 * @brief Raytracer practice project based on the "Raytracing in One Weekend" 
 * series by Peter Shirley https://raytracing.github.io/
 * @version 0.1
 * @date 2020-06-25
 * 
 * @copyright https://opensource.org/licenses/MIT
 * 
 * This thing can currently render a sphere.
 * 
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>

#include "..\tests\test.hpp"
#include "raytracer.hpp"

struct main_inputs{
  char * out_file_path;
  size_t image_width;
  size_t image_height;
  double aspect_ratio;
  size_t samples_per_pixel;
  size_t max_ray_recursion_depth;
};

const double default_aspect_ratio = 16.0 / 9.0;
const size_t default_samples_per_pixel = 3;
const size_t default_max_ray_recursion_depth = 10;

std::ostream& operator<<(std::ostream &out, const main_inputs& inputs);
bool parse_args(int argc, char *argv[], main_inputs& inputs);

int main(int argc, char *argv[]){
  
  // Parse inputs
  main_inputs inputs;
  bool is_success = parse_args(argc, argv, inputs);
  if(!is_success){
    std::cerr << "Error parsing arguments, exiting.\n";
    return 1;
  }
  std::cout << "Got inputs: " << inputs << "\n";

  // Output file
  std::cout << "Opening output file...\n";
  std::ofstream out_image;
  out_image.open(inputs.out_file_path);

  // Setup raytracer
  Raytracer raytracer(inputs.image_width, inputs.image_height);
  raytracer.samples_per_pixel = inputs.samples_per_pixel;
  raytracer.max_ray_recursion_depth = inputs.max_ray_recursion_depth;

  // Render
  std::clock_t start_render = std::clock();

  raytracer.render(out_image);

  double duration = ((double) (std::clock() - start_render)) / CLOCKS_PER_SEC;
  std::cout << "Render time: " << duration << " s \n";

  // Test   // TODO: Write more tests?
  // std::cout << "\nTesting...\n";
  // test();

  std::cout << "All done.\n";

  return 0;
}

// Argument parsing helpers

std::ostream& operator<<(std::ostream &out, const main_inputs& inputs){
  return out << "Output file path: " << inputs.out_file_path << "\n"
             << "Image size: " << inputs.image_width << " x "
                               << inputs.image_height << " "
             << "Aspect ratio: " << inputs.aspect_ratio << "\n"
             << "Samples per pixel: " << inputs.samples_per_pixel << "\n"
             << "Max recursion depth: " << inputs.max_ray_recursion_depth;
}

void print_usage(){
    std::cerr << "Usage: rtavis out_file_path image_width "
              << "[-spp samples_per_pixel] "
              << "[-depth max_ray_recursion_depth]\n";
}

bool parse_args(int argc, char *argv[], main_inputs& inputs){
  if(argc < 3 || argc > 7){
    print_usage();
    return false;
  }

  // Arguments
  inputs.out_file_path = argv[1];

  int temp_width = atoi(argv[2]);
  if(temp_width <= 0){
    std::cerr << "Width should be an integer > 0\n";
    return false;
  }
  inputs.image_width = temp_width;

  // Defaults
  std::cout << "Using default aspect ratio\n";
  inputs.aspect_ratio = default_aspect_ratio;

  inputs.image_height = round(inputs.image_width / inputs.aspect_ratio);

  inputs.samples_per_pixel = default_samples_per_pixel;

  inputs.max_ray_recursion_depth = default_max_ray_recursion_depth;

  // Optional arguments
  for(int i = 3; i < argc; i+=2){
    if((i + 1) >= argc) break;

    if(strcmp(argv[i], "-spp") == 0){
      int temp_smp = atoi(argv[i + 1]);
      if(temp_smp <= 0){
        std::cerr << "Samples per pixel should be an integer >= 1, using default.\n";
      } else {
        inputs.samples_per_pixel = temp_smp;
      }
    } else if(strcmp(argv[i], "-depth") == 0){
      int temp_maxr = atoi(argv[i + 1]);
      if(temp_maxr <= 0){
        std::cerr << "Max recursion depth should be an integer >= 1, using default.\n";
      } else {
        inputs.max_ray_recursion_depth = temp_maxr;
      }
    } else {
        std::cerr << argv[i] << " is not recognized flag\n";
        print_usage();
        return false;
    }
  }

  return true;
}