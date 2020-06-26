#include "lambertian.hpp"

bool Lambertian::scatter( const Ray& r_in,
                          const hit_record& hit_rec,
                          Color& attenuation,
                          Ray& scattered) const{

    Point3 scatter_target = hit_rec.p + hit_rec.normal + Vec3::random_unit_vector();
    scattered.orig = hit_rec.p;
    scattered.dir = scatter_target - hit_rec.p;
    attenuation = albedo;

    return true;
}