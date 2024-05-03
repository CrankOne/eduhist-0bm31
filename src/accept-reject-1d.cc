#include "accept-reject-1d.hh"

#include <cstdlib>

AcceptRejectGenerator::AcceptRejectGenerator(
        float a_, float b_, float maxValue_, PDFCallback_t pdf_) {
    a = a_;
    b = b_;
    maxValue = maxValue_;
    pdf = pdf_;
}

float
AcceptRejectGenerator::draw() {
    for(;;) {
        float x = a + (b - a)*rand()*1./RAND_MAX
            , y = maxValue*rand()*1./RAND_MAX;
        if(y < pdf(x)) return x;
    }
}

