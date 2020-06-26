#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP

#include "material.hpp"

class Lambertian : public Material{
    public:
        Lambertian(const Color &a)
        : albedo(a) {}

    virtual bool scatter( const Ray& r_in,
                        const hit_record& rec,
                        Color& attenuation,
                        Ray& scattered) const;
    public:
        Color albedo;
};

#endif