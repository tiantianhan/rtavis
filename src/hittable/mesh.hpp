#ifndef MESH_HPP
#define MESH_HPP

#include "hittable.hpp"
#include "..\utils\vec3.hpp"
#include <vector>

class Mesh: public Hittable{
    public:
    Mesh(){};

    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;

    public:
    std::vector<Vec3> vertices;
    std::vector<Vec3> normals;
};

#endif