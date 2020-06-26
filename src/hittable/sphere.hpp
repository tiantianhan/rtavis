#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "hittable.hpp"
#include "..\utils\vec3.hpp"

class Sphere: public Hittable{
    public:
        Sphere() {};
        Sphere(Point3 cen, double r) : center(cen), radius(r) {};
        Sphere(Point3 cen, double r, shared_ptr<Material> mat_ptr) 
        : center(cen)
        , radius(r) 
        , mat_ptr(mat_ptr)
        {};

        virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;

    public:
        Point3 center;
        double radius;
        shared_ptr<Material> mat_ptr;
};

#endif