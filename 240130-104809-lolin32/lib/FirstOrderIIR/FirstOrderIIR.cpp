#include "FirstOrderIIR.h"

FirstOrderIIRFilter::FirstOrderIIRFilter(float b0, float b1, float a1, float input_1)
{
    this->b0 = b0;
    this->b1 = b1;
    this->a1 = a1;
    this->input_1 = input_1;
}

FirstOrderIIRFilter::~FirstOrderIIRFilter()
{
}

float FirstOrderIIRFilter::Update(float input)
{
    output = b0 * input + b1 * input_1 + a1 * output;
    input_1 = input;
    return output;
}