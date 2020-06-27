#include "raytracer.hpp"

#include <iostream>

#include "utils\utils.hpp"
#include "utils\vec3.hpp"
#include "utils\color.hpp"
#include "hittable\hittable_list.hpp"
#include "hittable\sphere.hpp"
#include "material\lambertian.hpp"
#include "material\metal.hpp"
#include "ray.hpp"

const Color Raytracer::shading_error_color = Color(1.0, 0.0, 1.0);
const Color Raytracer::back_face_color = Color(0.0, 0.0, 0.0);

Color Raytracer::ray_color_gradient(const Ray &r)
{
  Vec3 unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0); // Change y range to [0, 1]
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

Color Raytracer::ray_color(const Ray &r, HittableList world, int depth)
{
  if(depth <= 0){
    return Color(0, 0, 0); //Rays blocked are shadows
  }

  struct hit_record hit_rec; 
  if (world.hit(r, 0.001, infinity, hit_rec))
  {
    Ray scattered;
    Color attenuation;

    if(hit_rec.mat_ptr.use_count() == 0){
      return shading_error_color;
    }

    if(hit_rec.mat_ptr->scatter(r, hit_rec, attenuation, scattered)){
      return attenuation * ray_color(scattered, world, depth - 1); //The more bounces the darker
    } else {
      return back_face_color;
    }
  }
  return ray_color_gradient(r);
}

int Raytracer::initialize()
{
  // Red lambert
  world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5,
                                make_shared<Lambertian>(Color(0.7, 0.3, 0.3))));

  // Yellow lambert
  world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100, 
                                make_shared<Lambertian>(Color(0.8, 0.8, 0.0)))); //Large sphere as ground plane
  // Metal spheres
  world.add(make_shared<Sphere>(Point3(1,0,-1), 0.5, 
                                make_shared<Metal>(Color(0.8, 0.6, 0.2), 1.0)));
  world.add(make_shared<Sphere>(Point3(-1,0,-1), 0.5, 
                                make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.3)));
  return 0;
}

int Raytracer::render(std::ostream &out_image)
{
  std::cout << "Rendering...\n";

  out_image << "P3\n"
            << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height - 1; j >= 0; --j)
  {
    std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;

    double w_increment = 1.0 / (image_width - 1);
    double h_increment = 1.0 / (image_height - 1);

    for (int i = 0; i < image_width; ++i)
    {
      //TODO: Optimize inside of render nested for-loops
      auto u = double(i) * w_increment;
      auto v = double(j) * h_increment;

      Color pixel_color(0, 0, 0);
      for(int s = 0; s < samples_per_pixel; s++){
        Ray r = camera.get_ray(random_double(u, u + w_increment), 
                               random_double(v, v + h_increment));

        //Color pixel_color = ray_color_gradient(r);
        //Color pixel_color = ray_color_sphere(r);
        pixel_color += ray_color(r, world, max_ray_recursion_depth);
      }

      pixel_color /= samples_per_pixel;
      gamma2_correct(pixel_color);
      write_color(out_image, pixel_color);
    }
    out_image << '\n';
  }
  std::cout << "\nDone.\n";
  return 0;
}