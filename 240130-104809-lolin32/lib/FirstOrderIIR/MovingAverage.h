#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#define MAX_ORDER 200

class MovingAverage
{
private:
    int n = 1;
    float input_buffer[MAX_ORDER];
    float output;
public:
    MovingAverage(int n);
    ~MovingAverage();
    int getN();
    void setN(int n);
    float Update(float input);
};

#endif // !MOVINGAVERAGE_H