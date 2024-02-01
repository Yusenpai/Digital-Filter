#include "MovingAverage.h"

MovingAverage::MovingAverage(int n)
{
    if(n > MAX_ORDER)
        this->n = MAX_ORDER;
    else if (n < 0)
        this->n = 0;
    else
        this->n = n;
    for (int i = 0; i < MAX_ORDER; i++)
    {
        input_buffer[i] = 0.0f;
    }
    output = 0.0f;
}

MovingAverage::~MovingAverage()
{

}

int MovingAverage::getN(){
    return this->n;
}

void MovingAverage::setN(int n){
    if(n > MAX_ORDER)
        this->n = MAX_ORDER;
    else if (n < 0)
        this->n = 0;
    else
        this->n = n;
}

float MovingAverage::Update(float input){
    float sum = 0.0f;
    for (int i = 0; i < n - 1; i++)
    {
        input_buffer[i] = input_buffer[i + 1];
        sum += input_buffer[i];
    }
    input_buffer[n - 1] = input;
    sum += input;
    output = sum / (float)n;
    return output;
}