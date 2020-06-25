#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "utils\utils.hpp"
#include "utils\vec3.hpp"
#include "ray.hpp"

class Camera {
    public: 
    Camera(double aspect = 16.0/9.0){
        aspect_ratio = aspect;
        initialize();
    }

    Ray get_ray(double u, double v) const;

    private:
        double aspect_ratio;
        Point3 origin;
        double viewport_height;
        double viewport_width;
        double focal_length;

        Point3 lower_left_corner;
        Vec3 horizontal;
        Vec3 vertical;

        void initialize();
};

#endif