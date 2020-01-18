//
// Created by Donya Hojabr on 2020-01-13.
//

#ifndef BASIC_RENDER_HITABLE_H
#define BASIC_RENDER_HITABLE_H

#include "ray.h"

class material;

struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
    material *mat_ptr;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const =0;
};

#endif //BASIC_RENDER_HITABLE_H
