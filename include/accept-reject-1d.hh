#pragma once

typedef float (*Callback_t)(float);

class Generator {
protected:
    float a;
    float b;
public:
    Generator(float a_, float b_);
    virtual float draw() = 0;

    float get_a() const { return a; }
    float get_b() const { return b; }
};

class AcceptRejectGenerator : public Generator {
private:
    float maxValue;
    Callback_t pdf;
public:
    AcceptRejectGenerator(float a_, float b_
            , float maxValue_, Callback_t pdf_);
    float draw() override;
};

class InvertedFunctionGenerator : public Generator {
private:
    Callback_t invF;
public:
    InvertedFunctionGenerator(float a_, float b_
            , Callback_t invF_);
    float draw() override;
};

class MajoredGenerator : public AcceptRejectGenerator {
    // ...
public:
    float draw() override;
    // ...
};

