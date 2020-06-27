#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "utils\utils.hpp"
#include "utils\vec3.hpp"
#include "ray.hpp"

class Camera {
    public: 
    /**
     * @brief Construct a new Camera object
     * 
     * @param aspect Aspect ratio as decimal
     * @param vertical_fov Vertical field of view in degrees
     */
    Camera(double aspect = 16.0/9.0, double vertical_fov = 90)
    : aspect_ratio(aspect)
    , vfov(degrees_to_radians(vertical_fov))
    {
        initialize();
    }

    Ray get_ray(double u, double v) const;

    private:
        double aspect_ratio;

        /**
         * @brief Vertical field of view in radians
         * 
         */
        double vfov;
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