#pragma once

#include <gsl/gsl_rng.h>

class SphereUniform {
private:
    gsl_rng * r;
    // ...
public:
    SphereUniform(int seed);
    ~SphereUniform();
    void draw(float * theta, float * phi);
};
