#include "metal.hpp"

inline Vec3 reflect(const Vec3 v, const Vec3 n){
    return v + dot(n, v) * -2 * n;
}

bool Metal::scatter(const Ray& r_in,
                    const hit_record& hit_rec,
                    Color& attenuation,
                    Ray& scattered) const{
    
    scattered.orig = hit_rec.p;
    Vec3 reflected = unit_vector(reflect(r_in.dir, hit_rec.normal));

    scattered.dir = reflected + roughness * Vec3::random_in_unit_sphere();

    attenuation = albedo;
    return (dot(scattered.direction(), hit_rec.normal) > 0); //reflection from front face only
}