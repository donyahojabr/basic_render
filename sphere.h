//
// Created by Donya Hojabr on 2020-01-13.
//

#ifndef BASIC_RENDER_SPHERE_H
#define BASIC_RENDER_SPHERE_H

#include "hitable.h"

class sphere: public hitable{
public:
    sphere(){}
    sphere(vec3 cen, float r) : center(cen), radius(r) {};
    virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
    vec3 center;
    float radius;
};

bool sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction()); //equation on pg 161
    float b = dot(oc, r.direction());
    float c = dot(oc,oc) - radius*radius;
    float discriminant = b*b - a*c;
    if(discriminant > 0) {
        float temp = (-b - sqrt(b*b-a*c))/a;
        //std::cout << temp << " ";
        if(temp < tmax && temp >= -2){ //hardcoded value, seems to work..
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            vec3 temp1(rec.p-center);
            rec.normal = vec3(temp1.x()/radius, temp1.y()/radius, temp1.z()/radius);
            return true;
        }
        temp = (-b+sqrt(b*b-a*c))/a;
        if(temp < tmax && temp > tmin) { //&& temp > tmin
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            vec3 temp1(rec.p-center);
            rec.normal = vec3(temp1.x()/radius, temp1.y()/radius, temp1.z()/radius);
        }
    }
    return false;
}

#endif //BASIC_RENDER_SPHERE_H