#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include "hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public Hittable{
    public:
        HittableList() {}
        HittableList(shared_ptr<Hittable> object) {
            add(object);
        }

        void clear();
        void add(shared_ptr<Hittable> object);

        virtual bool hit(const Ray& r, double tmin, double tmax, hit_record& rec) const;

    public:
        std::vector<shared_ptr<Hittable>> objects;
};

#endif