#include "camera.hpp"

void Camera::initialize(){
    origin = Point3(0, 0, 0);
    viewport_height = 2.0;
    viewport_width = viewport_height * aspect_ratio;
    focal_length = 1.0;

    horizontal = Vec3(viewport_width, 0, 0);
    vertical = Vec3(0, viewport_height, 0);
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);
}

/**
 * @brief Generate a ray from the camera
 * 
 * @param u horizontal parameter on viewport, [0, 1]
 * @param v vertical parameter on viewport, [0, 1]
 * @return Ray from origin to the specified point on the viewport
 */
Ray Camera::get_ray(double u, double v) const {
    return Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
}
