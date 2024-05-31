#include <cstdio>
#include <cassert>

#include "histogram1d.hh"

// implementation

Histogram1D::Histogram1D(float a_, float b_, int nBins_) {
    a = a_;
    b = b_;
    nBins = nBins_;
    binWidth = (b - a)/(nBins);
    counters = new int [nBins_];
    for(int i = 0; i < nBins_; ++i) {
        counters[i] = 0;
    }
}

Histogram1D::~Histogram1D() {
    delete [] counters;
}

void
Histogram1D::fill(float x) {
    if(x < a)  return;
    if(x >= b) return;
    int nBin = (x - a)/binWidth;
    assert(nBin < nBins);
    ++counters[nBin];
}

void
Histogram1D::dump(FILE * outFile) {
    for(int i = 0; i < nBins; ++i) {
        fprintf(outFile, "%3d %f %f %d\n", i
                , i*binWidth
                , (i+1)*binWidth
                , counters[i]);
    }
}

