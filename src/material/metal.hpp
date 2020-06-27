#ifndef METAL_HPP
#define METAL_HPP

#include "material.hpp"

class Metal : public Material{

    public:
    Metal(Color albedo) : albedo(albedo) {}
    virtual bool scatter( const Ray& r_in,
                        const hit_record& rec,
                        Color& attenuation,
                        Ray& scattered) const;

    public:
    Color albedo;
};

#endif