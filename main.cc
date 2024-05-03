#include <cstdio>
#include <cstdlib>

#include "histogram1d.hh"
#include "histogram2d.hh"

// entrypoint

int main(int argc, char * argv[]) {
    //Histogram1D h(-10., 10, 10);

    //for(int i = 0; i < 10; ++i) {
    //    float x = 20.*rand()/RAND_MAX - 10;
    //    h.fill(x);
    //}

    //h.dump();

    Histogram2D h( -50., 50
                 , -5, 5
                 , 80, 40);

    for(int i = 0; i < 10000; ++i) {
        float x = 25 - 50.*rand()/RAND_MAX
            , y = 2.5 - 5.*rand()/RAND_MAX
            ;
        h.fill(x, y);
    }

    FILE * outFile = fopen("points.dat", "w");
    h.dump(outFile);
    fclose(outFile);

    return 0;
}

