#ifndef METAL_HPP
#define METAL_HPP

#include "material.hpp"

class Metal : public Material{

    public:
    Metal(Color albedo, double roughness = 0) 
    : albedo(albedo) 
    , roughness(roughness)
    {}
    virtual bool scatter( const Ray& r_in,
                        const hit_record& rec,
                        Color& attenuation,
                        Ray& scattered) const;

    public:
    Color albedo;

    /**
     * @brief Value between [0, 1]
     * 
     */
    double roughness;
};

#endif