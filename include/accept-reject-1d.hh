
typedef float (*PDFCallback_t)(float);

class AcceptRejectGenerator {
private:
    float a, b;
    float maxValue;
    PDFCallback_t pdf;
public:
    AcceptRejectGenerator(float a, float b, float maxValue, PDFCallback_t pdf);
    float draw();
};

