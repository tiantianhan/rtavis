#ifndef VEC3_HPP
#define VEC3_HPP

#include <ostream>

class Vec3{
  public:
    Vec3(): e{0, 0, 0} {}
    Vec3(double e0, double e1, double e2): e{e0, e1, e2} {}

    double x() const;
    double y() const;
    double z() const;

    Vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);
    Vec3& operator+=(const Vec3 &v);
    Vec3& operator*=(const double t);
    Vec3& operator/=(const double t);

    double length() const;

    double length_squared() const;

  public:
    double e[3];
};

using Point3 = Vec3;
using Color = Vec3;

//Vec3 inline utility functions
inline std::ostream& operator<<(std::ostream &out, const Vec3&v){
  return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v){
  return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v){
  return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v){
  return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vec3 operator*(const Vec3 &v, double t){
  return Vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline Vec3 operator*(double t, const Vec3 &v){
  return v * t; //per element multiplication is commutative
}

inline Vec3 operator/(const Vec3 &v, double t){
  return (1 / t) * v;
}

inline double dot(const Vec3 &u, const Vec3 &v){
  return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v){
  return Vec3((u.e[1] * v.e[2] - u.e[2] * v.e[1]),
              (u.e[2] * v.e[0] - u.e[0] * v.e[2]),
              (u.e[0] * v.e[1] - u.e[1] * v.e[0]));
}

inline Vec3 unit_vector(const Vec3 &v){
  return v/v.length();
}

#endif
