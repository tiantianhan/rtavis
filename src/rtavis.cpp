/**
 * @file rtavis.cpp
 * @author tina
 * @brief Raytracer practice project based on the "Raytracing in One Weekend" 
 * series by Peter Shirley https://raytracing.github.io/
 * @version 0.2
 * @date 2021-05-30
 * 
 * @copyright https://opensource.org/licenses/MIT
 * 
 * Loads a file of sphere model information and render as ppm file.
 * 
 */
#include <iostream>
#include <fstream>
#include <cstring>

#include "..\tests\test.hpp"
#include "raytracer.hpp"
#include "utils\timer.hpp"
#include "io\load_obj.hpp"

// Inputs
struct main_inputs{
  std::string in_file_path;
  size_t image_width;
  size_t image_height;
  std::string out_file_path;
  double aspect_ratio;
  size_t samples_per_pixel;
  size_t max_ray_recursion_depth;
};

// Defaults
const std::string default_input_file = "";
const std::string default_output_file = "rtavis_out.ppm";
const double default_aspect_ratio = 16.0 / 9.0;
const size_t default_samples_per_pixel = 3;
const size_t default_max_ray_recursion_depth = 10;

// Declarations
std::ostream& operator<<(std::ostream &out, const main_inputs& inputs);
bool parse_args(int argc, char *argv[], main_inputs& inputs);
void print_usage();
void set_default_args();

int main(int argc, char *argv[]){
  
  // Parse inputs
  main_inputs inputs;
  bool is_success = parse_args(argc, argv, inputs);
  if(!is_success){
    print_usage();
    std::cerr << "Error parsing arguments, exiting.\n";
    return 1;
  }
  std::cout << "Got inputs: \n" << inputs << "\n\n";

  // Output file
  std::cout << "Opening output file...\n";
  std::ofstream out_image;
  out_image.open(inputs.out_file_path);
  if(out_image.is_open() == false)
    std::cout << "Failed to open output file " << inputs.out_file_path << "\n";
    

  // Input file
  std::cout << "Opening input file...\n";
  std::ifstream in_file;
  in_file.open(inputs.in_file_path);
  if(in_file.is_open() == false)
    std::cout << "Failed to open input file " << inputs.in_file_path << "\n";

  // Setup raytracer
  Raytracer raytracer(inputs.image_width, inputs.image_height);
  raytracer.samples_per_pixel = inputs.samples_per_pixel;
  raytracer.max_ray_recursion_depth = inputs.max_ray_recursion_depth;

  // Load
  if(in_file.is_open() == false){
    raytracer.load_default_world();
  } else {
    raytracer.load(in_file);
  }

  // Render
  Timer render_timer;

  // raytracer.render(out_image);

  // std::cout << "Render time: " << render_timer << "\n";

  // Test   // TODO: Write more tests?
  std::cout << "\nTesting load obj file...\n";
  tiny_obj_loader_test(inputs.in_file_path);
  // test();

  in_file.close();
  out_image.close();

  std::cout << "All done.\n";

  return 0;
}

// Argument parsing helpers
std::ostream& operator<<(std::ostream &out, const main_inputs& inputs){
  return out << "Input file path: " << inputs.in_file_path << "\n"
             << "Output file path: " << inputs.out_file_path << "\n"
             << "Image size: " << inputs.image_width << " x "
                               << inputs.image_height << " "
             << "Aspect ratio: " << inputs.aspect_ratio << "\n"
             << "Samples per pixel: " << inputs.samples_per_pixel << "\n"
             << "Max recursion depth: " << inputs.max_ray_recursion_depth;
}

void print_usage(){
    std::cerr << "Usage: rtavis image_width "
              << "[-i in_file_path]"
              << "[-o out_file_path]"
              << "[-spp samples_per_pixel] "
              << "[-depth max_ray_recursion_depth]\n";
}

void set_default_args(main_inputs &inputs){
  inputs.in_file_path = default_input_file;
  inputs.out_file_path = default_output_file;

  std::cout << "Using default aspect ratio\n";
  inputs.aspect_ratio = default_aspect_ratio;

  inputs.image_height = round(inputs.image_width / inputs.aspect_ratio);

  inputs.samples_per_pixel = default_samples_per_pixel;

  inputs.max_ray_recursion_depth = default_max_ray_recursion_depth;
}

//Parse arguments. Returns true if successful and false if not successful.
bool parse_args(int argc, char *argv[], main_inputs& inputs){
  const int opt_arg_start = 2;
  const int total_arg = 10;

  // Check number of arguments
  if(argc < opt_arg_start || argc > total_arg){
    return false;
  }

  // Arguments
  int temp_width = atoi(argv[1]);
  if(temp_width <= 0){
    std::cerr << "Width should be an integer > 0\n";
    return false;
  }
  inputs.image_width = temp_width;

  // Defaults
  set_default_args(inputs);

  // Optional arguments
  for(int i = opt_arg_start; i < argc; i+=2){
    if((i + 1) >= argc) break;

    if(strcmp(argv[i], "-i") == 0){
      inputs.in_file_path = std::string(argv[i + 1]);
    
    } else if(strcmp(argv[i], "-o") == 0){
      inputs.out_file_path = std::string(argv[i + 1]);
      
    } else if(strcmp(argv[i], "-spp") == 0){
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
        return false;
    }
  }

  return true;
}