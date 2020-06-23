#include "sphere.hpp"
#include "..\ray.hpp"

bool Sphere::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    Vec3 oc = r.origin() - center;
    double a = r.direction().length_squared(); //dot(r.direction(), r.direction())
    double half_b = dot(r.direction(), oc);
    double c = oc.length_squared() - radius * radius; //dot(oc, oc) - radius * radius
    double discriminant = half_b * half_b  - a * c; //Simplified quadradic equation

    if (discriminant > 0){
        double root_discr = sqrt(discriminant);
        double t = (-half_b - root_discr) / a;
        if(t >= t_min && t <= t_max){
            rec.t = t;
            rec.p = r.at(t);
            rec.normal = (rec.p - center) / radius;
            return true;
        } 
        
        t = (-half_b + root_discr) / a;
        if(t >= t_min && t <= t_max){
            rec.t = t;
            rec.p = r.at(t);
            rec.normal = (rec.p - center) / radius;
            return true;
        } 
    }

    return false;
}