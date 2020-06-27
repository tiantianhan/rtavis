#include "dielectric.hpp"
#include <cmath>

inline double schlick(double cosine, double index_i_over_r){
    double r0 = ( 1 - index_i_over_r) / (1 + index_i_over_r);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

inline bool is_reflect_schlick(double cosine, double index_i_over_r){
    return random_double() < schlick(cosine, index_i_over_r);
}

inline Vec3 refract_with_schlick(Vec3 v_i, double index_i_over_r, Vec3 normal){
    v_i = unit_vector(v_i);
    normal = unit_vector(normal);

    double cos_theta = dot(-v_i, normal); //v_i, normal are unit vectors
    double sin_theta = sqrt(1 - cos_theta * cos_theta);

    if(index_i_over_r * sin_theta  > 1.0){ //total internal reflection
        return reflect(v_i, normal);

    // Reflection with probability, schlick approximation
    } else if(is_reflect_schlick(cos_theta, index_i_over_r)) { 
        return reflect(v_i, normal);
        
    } else { // refraction

        Vec3 v_r_l = index_i_over_r * (v_i + cos_theta * normal);
        Vec3 v_r_p = -sqrt(1.0 - v_r_l.length_squared()) * normal;
        return v_r_l + v_r_p;
    }
}

bool Dielectric::scatter( const Ray& r_in,
                const hit_record& hit_rec,
                Color& attenuation,
                Ray& scattered) const{
    
    double index_i_over_r = hit_rec.front_face ? (1 / refraction) : refraction;
    
    scattered.dir = refract_with_schlick(r_in.dir, index_i_over_r, hit_rec.normal);
    scattered.orig = hit_rec.p;

    attenuation = Color(1.0, 1.0, 1.0);

    return true;
}