#include "../src/material/dielectric.hpp"
#include "../src/material/metal.hpp"
#include "../src/material/lambertian.hpp"
#include "../src/hittable/sphere.hpp"
#include "../src/hittable/hittable_list.hpp"
#include "../src/hittable/hittable.hpp"
#include "render_test.hpp"

int render_test(){
    return 0;
}

/*HittableList get_default_world(){

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
}*/