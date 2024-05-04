#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "sphere-uniform.hh"

int main(int argc, char * argv[]) {



    for(int i = 0; i < 5; ++i) {
        float phi       = M_PI - 2*M_PI*rand()/RAND_MAX
            //, theta     = M_PI*rand()/RAND_MAX
            , cosTheta   = 1 - 2.*rand()/RAND_MAX
            , theta     = acos(cosTheta)
            ;

        //float x = sin(theta)*cos(phi) 
        //    , y = sin(theta)*sin(phi)
        //    , z = cos(theta)
        //    ;
        printf("%e %e %e\n", x, y, z);
    }
    return 0;
}

