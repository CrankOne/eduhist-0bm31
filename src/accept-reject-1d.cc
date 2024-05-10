#include "accept-reject-1d.hh"

#include <cstdlib>

Generator::Generator(float a_, float b_) : a(a_), b(b_) {
}


AcceptRejectGenerator::AcceptRejectGenerator(
            float a_, float b_, float maxValue_, Callback_t pdf_)
        : Generator(a_, b_) {
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


InvertedFunctionGenerator::InvertedFunctionGenerator(float a_, float b_
            , Callback_t invF_)
    : Generator(a_, b_)
{
    invF = invF_;
}

float
InvertedFunctionGenerator::draw() {
    // TODO: account for a and b (definition range)
    float u = rand()*1./RAND_MAX;
    return invF(u);
}

