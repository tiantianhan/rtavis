#include "raytracer.hpp"

#include <iostream>

#include "utils\utils.hpp"
#include "hittable\hittable_list.hpp"
#include "hittable\sphere.hpp"

Color ray_color_gradient(const Ray &r)
{
  Vec3 unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0); // Change y range to [0, 1]
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

Color ray_color_sphere(const Ray &r, Sphere sphere)
{
  struct hit_record hit_rec; 
  if (sphere.hit(r, 0, 10000, hit_rec))
  {
    Vec3 n = hit_rec.normal;
    return 0.5 * Color(n.x() + 1, n.y() + 1, n.z() + 1);
  }
  return ray_color_gradient(r);
}

Color ray_color(const Ray &r, HittableList world)
{
  struct hit_record hit_rec; 
  if (world.hit(r, 0, 10000, hit_rec))
  {
    Vec3 n = hit_rec.normal;
    return 0.5 * Color(n.x() + 1, n.y() + 1, n.z() + 1);
  }
  return ray_color_gradient(r);
}

int Raytracer::initialize()
{
  origin = Point3(0, 0, 0);
  viewport_height = 2.0;
  viewport_width = viewport_height * aspect_ratio;
  focal_length = 1.0;

  world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
  world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100)); //Large sphere as ground plane

  return 0;
}

int Raytracer::render(std::ostream &out_image)
{
  std::cout << "Rendering...\n";

  Vec3 horizontal = Vec3(viewport_width, 0, 0);
  Vec3 vertical = Vec3(0, viewport_height, 0);
  Point3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);

  out_image << "P3\n"
            << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height - 1; j >= 0; --j)
  {
    std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;

    for (int i = 0; i < image_width; ++i)
    {
      //TODO: Optimize inside of render nested for-loops
      auto u = double(i) / (image_width - 1);
      auto v = double(j) / (image_height - 1);

      //TODO: Use matrix to transform from viewport to image space?
      Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);

      //Color pixel_color = ray_color_gradient(r);
      //Color pixel_color = ray_color_sphere(r);
      Color pixel_color = ray_color(r, world);

      write_color(out_image, pixel_color);
    }
    out_image << '\n';
  }
  std::cout << "\nDone.\n";
  return 0;
}