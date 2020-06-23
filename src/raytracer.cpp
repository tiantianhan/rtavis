#include "raytracer.hpp"
#include <iostream>
#include <cmath>
#include "utils\vec3.hpp"
#include "utils\color.hpp"
#include "ray.hpp"

Color ray_color_gradient(const Ray& r){
  Vec3 unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0); // Change y range to [0, 1]
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

bool hit_sphere(const Point3& center, double radius, const Ray& r){
  Vec3 oc = r.origin() - center;
  double a = dot(r.direction(), r.direction());
  double b = 2 * dot(r.direction(), oc);
  double c = dot(oc, oc) - radius * radius;
  double discriminant = b * b  - 4 * a * c;
  return (discriminant > 0);
}

Color ray_color_sphere(const Ray& r){
  if(hit_sphere(Point3(0, 0, -1), 0.5, r)){
    return Color(1, 0, 0); //Red
  }
  Vec3 unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0); // Change y range to [0, 1]
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int Raytracer::initialize(){
  origin = Point3(0, 0, 0);
  viewport_height = 2.0;
  viewport_width = viewport_height * aspect_ratio;
  focal_length = 1.0;
  return 0;
}

int Raytracer::render(std::ostream &out_image){
  std::cout << "Rendering...\n";

  
  Vec3 horizontal = Vec3(viewport_width, 0, 0);
  Vec3 vertical = Vec3(0, viewport_height, 0);
  Point3 lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);

  out_image << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for(int j = image_height-1; j >= 0; --j){
    std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;

    for(int i = 0; i < image_width; ++i){
      //TODO: Optimize inside of render nested for-loops
      auto u = double(i) / (image_width - 1);
      auto v = double(j) / (image_height - 1);

      //TODO: Use matrix to transform from viewport to image space?
      Ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);

      //Color pixel_color = ray_color_gradient(r);
      Color pixel_color = ray_color_sphere(r);

      write_color(out_image, pixel_color);
    }
    out_image << '\n';
  }
  std::cout << "\nDone.\n";
  return 0;
}