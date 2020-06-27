#include "dielectric.hpp"
#include <cmath>

inline Vec3 refract_unit_vector(Vec3 v_i, double index_i_over_r, Vec3 normal){
    double cos_theta = dot(-v_i, normal); //v_i, normal are unit vectors
    Vec3 v_r_l = index_i_over_r * (v_i + cos_theta * normal);
    Vec3 v_r_p = -sqrt(1.0 - v_r_l.length_squared()) * normal;

    return v_r_l + v_r_p;
}

bool Dielectric::scatter( const Ray& r_in,
                const hit_record& hit_rec,
                Color& attenuation,
                Ray& scattered) const{
    
    double index_i_over_r = hit_rec.front_face ? (1 / refraction) : refraction;
    
    scattered.dir = refract_unit_vector(unit_vector(r_in.dir),
                                        index_i_over_r,
                                        unit_vector(hit_rec.normal));
    scattered.orig = hit_rec.p;

    attenuation = Color(1.0, 1.0, 1.0);

    return true;
}