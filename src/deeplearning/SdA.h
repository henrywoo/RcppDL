#ifndef SDA_H_
#define SDA_H_

#include <iostream>
#include <cstdlib>

#include "utils.h"
#include "HiddenLayer.h"
#include "dA.h"
#include "LogisticRegression.h"

class SdA {

  public:
    int N;
    int n_ins;
    int *hidden_layer_sizes;
    int n_outs;
    int n_layers;
    HiddenLayer **sigmoid_layers;
    dA **dA_layers;
    LogisticRegression *log_layer;
    SdA(int, int, int*, int, int);
    ~SdA();
    void pretrain(int**, double, double, int);
    void finetune(int**, int**, double, int);
    void predict(int*, double*);
};


#endif
