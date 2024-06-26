#include "sphere-uniform.hh"

#include <cstdlib>
#include <cmath>

SphereUniform::SphereUniform(int seed) {
    const gsl_rng_type * T;

    gsl_rng_env_setup();

    T = gsl_rng_default;
    r = gsl_rng_alloc(T);
    gsl_rng_set(r, seed);
}

SphereUniform::~SphereUniform() {
    gsl_rng_free(r);
}

void
SphereUniform::draw(float * theta, float * phi) {
    *phi            = M_PI - 2*M_PI*rand()/RAND_MAX;
    float cosTheta  = 1 - 2.*rand()/RAND_MAX;
    *theta          = acos(cosTheta);
}
