#ifndef FIRSTORDERIIR_H
#define FIRSTORDERIIR_H

class FirstOrderIIRFilter
{
private:
    /* data */
    float b0, b1, a1;
    float input_1;
public:
    FirstOrderIIRFilter(float b0, float b1, float a1, float input_1 = 0);
    ~FirstOrderIIRFilter();
    float output;
    float Update(float input);
};

#endif // !FIRSTORDERIIR_H