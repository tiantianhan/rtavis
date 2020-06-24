#include "hittable_list.hpp"        

void HittableList::add(std::shared_ptr<Hittable> object){
    objects.push_back(object);
}

void HittableList::clear(){
    objects.clear();
}

bool HittableList::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const{
    double closest_t = t_max;
    bool is_hit = false;

    hit_record rec_i;
    for(int i = 0; i < objects.size(); i++){
        if(objects[i]->hit(r, t_min, closest_t, rec_i)){
            is_hit = true;
            closest_t = rec_i.t;
            rec = rec_i;
        }
    }

    return is_hit;
}
