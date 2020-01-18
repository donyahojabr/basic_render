//
// Created by Donya Hojabr on 2020-01-18.
//

#ifndef BASIC_RENDER_MATERIAL_H
#define BASIC_RENDER_MATERIAL_H

#include "ray.h"
#include "hitable.h"

class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const =0;
};

vec3 random_in_unit_sphere(){
    vec3 p;
    do{
        p = vec3(drand48(), drand48(), drand48());
    }
    while (p.squared_length() >=1);
    return p;
}

vec3 reflect(const vec3& v, const vec3& n){
    return v-2*dot(v,n)*n;
}

class lambertian : public material {
public:
    lambertian(const vec3& a): albedo(a){}
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        scattered = ray(rec.p, target-rec.p);
        attenuation = albedo;
        return true;
    }
    vec3 albedo;
};

class metal:public material {
public:
    metal(const vec3& a):albedo(a){}
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const{
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p,reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal)>0);
    } vec3 albedo;
};


#endif //BASIC_RENDER_MATERIAL_H
