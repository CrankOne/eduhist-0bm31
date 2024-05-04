#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "sphere-uniform.hh"

int main(int argc, char * argv[]) {
    SphereUniform sg(); // TODO

    for(int i = 0; i < 5; ++i) {
        float phi, theta;
        sg.draw(&theta, &phi);
        float x = sin(theta)*cos(phi) 
            , y = sin(theta)*sin(phi)
            , z = cos(theta)
            ;
        printf("%e %e %e\n", x, y, z);
    }
    return 0;
}

