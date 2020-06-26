#ifndef MATERIAL_H
#define MATERIAL_H

#include "..\hittable\hittable.hpp"
#include "..\ray.hpp"

class Material {
    public:
        virtual bool scatter( const Ray& r_in,
                              const hit_record& rec,
                              Color& attenuation,
                              Ray& scattered) const = 0;

};

#endif