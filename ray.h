//
// Created by Donya Hojabr on 2020-01-11.
//

#ifndef BASIC_RENDER_RAY_H
#define BASIC_RENDER_RAY_H

#include "vec3.h"

class ray{
public:
    ray() {}
    ray(const vec3& a, const vec3& b) {A = a; B = b; }
    vec3 origin() const {return A;}
    vec3 direction() const {return B;}
    vec3 t(float t) const {return A + t*B; }

    vec3 A;
    vec3 B;
};

#endif //BASIC_RENDER_RAY_H
