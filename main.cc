#include <cstdio>
#include <cstdlib>

#include "histogram1d.hh"
#include "histogram2d.hh"

#include "accept-reject-1d.hh"

// entrypoint

// inteval 0-1
float pdf(float x) {
    return 1 - x; 
}

int main(int argc, char * argv[]) {
    Histogram1D h(0, 1, 40);
    AcceptRejectGenerator gen(0, 1, 1, pdf);

    for(int i = 0; i < 1e4; ++i) {
        float x = gen.draw();
        h.fill(x);
    }

    //Histogram2D h( -50., 50
    //             , -5, 5
    //             , 80, 40);

    //for(int i = 0; i < 10000; ++i) {
    //    float x = 25 - 50.*rand()/RAND_MAX
    //        , y = 2.5 - 5.*rand()/RAND_MAX
    //        ;
    //    h.fill(x, y);
    //}

    FILE * outFile = fopen("points.dat", "w");
    h.dump(outFile);
    fclose(outFile);

    return 0;
}

