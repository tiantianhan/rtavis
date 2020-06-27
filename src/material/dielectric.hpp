#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP

#include "material.hpp"

class Dielectric : public Material{
    
    public:
    Dielectric (double refraction) 
    : refraction(refraction)
    {}
    virtual bool scatter( const Ray& r_in,
                    const hit_record& rec,
                    Color& attenuation,
                    Ray& scattered) const;

    public:
    /**
     * @brief Index of refraction, [0, 1]
     * 
     */
    double refraction;
};

#endif