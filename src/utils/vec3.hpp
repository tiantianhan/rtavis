#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include "utils.hpp"

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

    inline static Vec3 random() {
      return Vec3(random_double(), random_double(), random_double());
    }

    inline static Vec3 random(double min, double max){
      return Vec3(random_double(min, max), random_double(min, max), random_double(min, max));
    }

    inline static Vec3 random_in_unit_sphere(){
      int tries = 0;
      Vec3 p(0, 0, 0);

      while(++tries < 1000){
        Vec3 p = Vec3::random(-1, 1);
        if(p.length_squared() < 1)
          return p;
      }

      return p;
    }

    inline static Vec3 random_unit_vector(){
      auto a = random_double(0, 2*pi); //random angle on slice
      auto z = random_double(-1, 1); //random slice
      auto r = sqrt(1 - z*z); //find radius of slice
      return Vec3(r*cos(a), r*sin(a), z); //derive x, y from angle and radius of slice
    }

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
