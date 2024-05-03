// declaration

class Histogram1D {
private:
    float a;  // left axis range
    float b;  // right axis range
    int * counters;  // array of counters
    int nBins;  // number of counters (bins)
    float binWidth;  // (cache) width of a single bin (sub-range)
public:
    Histogram1D(float a_, float b_, int nBins_);
    ~Histogram1D();
    void fill(float x);
    void dump(FILE *);
};


