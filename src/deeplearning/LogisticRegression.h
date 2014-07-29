#ifndef LOGISTIC_H_
#define LOGISTIC_H_

#include <iostream>
#include <string>
#include <cmath>
#include "utils.h"

class LogisticRegression
{

public:
    int N;
    int n_in;
    int n_out;
    vector<vector<double> > W;
    vector<double> b;
    LogisticRegression(int, int, int);
    void train(int*, int*, double);
    void softmax(vector<double>&);
    void predict(int*, vector<double>&);
};

#endif
