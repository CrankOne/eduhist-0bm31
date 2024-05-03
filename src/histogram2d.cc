#include <cstdio>

#include "histogram2d.hh"

// implementation

Histogram2D::Histogram2D( float aX_, float bX_
                        , float aY_, float bY_
                        , int nBinsX_, int nBinsY_) {
    aX = aX_;
    bX = bX_;
    aY = aY_;
    bY = bY_;
    nBinsX = nBinsX_;
    nBinsY = nBinsY_;
    binWidthX = (bX - aX)/nBinsX_;
    binWidthY = (bY - aY)/nBinsY_;
    counters = new int [nBinsX*nBinsY];
}

Histogram2D::~Histogram2D() {
    delete [] counters;
}

int
Histogram2D::_get_offset(int nBinX, int nBinY) {
    return nBinX + nBinY*nBinsX;
}

void
Histogram2D::fill(float x, float y) {
    int nBinX = (x - aX)/binWidthX;
    int nBinY = (y - aY)/binWidthY;

    int offset = _get_offset(nBinX, nBinY);
    //printf("x=%e, y=%e, ix=%d, iy=%d, offset=%d\n"
    //        , x, y, nBinX, nBinY, offset
    //        );

    ++counters[offset];
}

void
Histogram2D::dump(FILE * outFile) {
    for(int nBinX = 0; nBinX < nBinsX; ++nBinX) {
        for(int nBinY = 0; nBinY < nBinsY; ++nBinY) {
            int offset = _get_offset(nBinX, nBinY);
            fprintf(outFile, "%5d", counters[offset]);
        }
        fprintf(outFile, "\n");
    }
}

