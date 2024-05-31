#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "histogram1d.hh"
#include "histogram2d.hh"

#include "accept-reject-1d.hh"

#include <cmath>

// inteval 0-1
float pdf(float x) {
    return cos(x)/1.89797;
}

float cdf(float x) {
    return 0.526879 * (0.948985 + sin(x));
}

// inverted \int_{0}^{x} sin(pi x)                                                  
float inv_cdf(float u) {                                                            
    return - asin(0.9489846193555862 - 1.8979692387111724*u);
}

void fill_histogram_with_generator(Histogram1D * h, Generator * G, int nEvents) {
    for(int i = 0; i < nEvents; ++i) {
        float x = G->draw();
        h->fill(x);
    }
}

int main(int argc, char * argv[]) {
    Histogram1D h(-5, 5, 40);

    //AcceptRejectGenerator gen(0, 1, 1, pdf);
    InvertedFunctionGenerator gen(-1.25, 1.25, cdf, inv_cdf);

    fill_histogram_with_generator(&h, &gen, 1e5);

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
    assert(outFile);
    h.dump(outFile);
    fclose(outFile);

    return 0;
}

