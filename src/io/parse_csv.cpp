#include <string>
#include <iostream>
#include <sstream>
#include "parse_csv.hpp"


#include "../hittable/sphere.hpp"
#include "../material/dielectric.hpp"
#include "../material/metal.hpp"
#include "../material/lambertian.hpp"
#include "../hittable/sphere.hpp"

const int col_shape = 0;
const int col_pos_x = 1;
const int col_pos_y = 2;
const int col_pos_z = 3;
const int col_radius = 4;
const int col_material = 5;
const int col_r = 6;
const int col_g = 7;
const int col_b = 8;
const int col_material_param = 9;

shared_ptr<Sphere> parse_sphere(std::vector<std::string> row);

HittableList get_default_world(){

  HittableList world;
  Point3 translation(0, 0, -0.6);

  // Red lambert
  world.add(make_shared<Sphere>(Point3(0, 0, -1) + translation, 0.5,
                                make_shared<Lambertian>(Color(172/255.0, 55/255.0, 77/255.0))));

  // Yellow lambert
  world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100, 
                                make_shared<Lambertian>(Color(243/255.0, 208/255.0, 176/255.0)))); //Large sphere as ground plane
  // Metal spheres
  world.add(make_shared<Sphere>(Point3(0.6,-0.3,-0.8) + translation, 0.2, 
                                make_shared<Metal>(Color(37/255.0, 29/255.0, 50/255.0), 1.0)));
  // world.add(make_shared<Sphere>(Point3(-1,0,-1), 0.5, 
  //                               make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.3)));

  // Glass spheres
  world.add(make_shared<Sphere>(Point3(0.3,-0.4,-0.4) + translation, 0.1, 
                              make_shared<Dielectric>(1.3)));
 

  return world;
}

HittableList parse_csv_for_hittable_list(std::ifstream &input_file){
    std::cout << "Parsing csv ...\n";

    std::string row;
    HittableList world;

    //std::getline(input_file, row);

    while(std::getline(input_file, row)){
      std::stringstream row_stream;
      row_stream.str(row);
      std::vector<std::string> split_row;
      std::string cell;
      while(row_stream.good()){
        std::getline(row_stream, cell, ',');
        split_row.push_back(cell);
        std::cout << "Got cell " << cell << "\n";
      }
      std::cout << "Got row.\n";
      if(split_row[col_shape].compare("Sphere") == 0){
        std::cout << "Adding row.\n";
        world.add(parse_sphere(split_row));
      }
    }

    return world;
}

shared_ptr<Sphere> parse_sphere(std::vector<std::string> row){
  Sphere sphere;
  std::cout << "Adding row col pos x: " + row[col_pos_x] + "\n";
  double pos_x = std::stod(row[col_pos_x]);
  double pos_y = std::stod(row[col_pos_y]);
  double pos_z = std::stod(row[col_pos_z]);
  double rad = std::stod(row[col_radius]);

  
  double r = std::stod(row[col_r]);
  double g = std::stod(row[col_g]);
  double b = std::stod(row[col_b]);
  double param = std::stod(row[col_material_param]);
  std::string material = row[col_material];

  if(material.compare("Lambertian") == 0){
    return make_shared<Sphere>(Point3(pos_x, pos_y, pos_z), rad,
                                make_shared<Lambertian>(Color(r, g, b)));

  } else if (material.compare("Metal") == 0) {
    return make_shared<Sphere>(Point3(pos_x, pos_y, pos_z), rad,
                                make_shared<Metal>(Color(r, g, b), param));

  } else if (material.compare("Dielectric")== 0) {
    return make_shared<Sphere>(Point3(pos_x, pos_y, pos_z), rad,
                                make_shared<Dielectric>(param));
  }
  return make_shared<Sphere>(Point3(pos_x, pos_y, pos_z), rad,
                                make_shared<Lambertian>(Color(255, 0, 0)));;
}