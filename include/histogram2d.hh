#pragma once

#include "histogram1d.hh"

class Histogram2D {
private:
    float aX;  // left axis range X
    float bX;  // right axis range X
    float aY;
    float bY;
    int * counters;  // array of counters
    int nBinsX;  // number of counters (bins), X
    int nBinsY;  // ..., Y
    float binWidthX;  // (cache) width of a single bin (sub-range)
    float binWidthY;  // ...

    int _get_offset(int nBinx, int nBinY);
public:
    Histogram2D( float aX, float bX
               , float aY, float bY
               , int nBinsX, int nBinsY );
    ~Histogram2D();
    void fill(float x, float y);
    void dump(FILE *);
};

