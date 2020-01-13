//
// Created by Donya Hojabr on 2020-01-13.
//

#ifndef BASIC_RENDER_HITABLE_LIST_H
#define BASIC_RENDER_HITABLE_LIST_H

#include "hitable.h"

class hitable_list: public hitable {
    hitable_list() {}

    virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
    hitable **list;
    int list_size;
public:
    hitable_list(hitable **l, int n) {list = l; list_size = n;}
};

bool hitable_list::hit(const ray& r, float tmin, float tmax, hit_record& rec) const{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = tmax;
    for(int i = 0; i<list_size; i++){
        if(list[i]->hit(r,tmin,closest_so_far,temp_rec)){
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

#endif //BASIC_RENDER_HITABLE_LIST_H
