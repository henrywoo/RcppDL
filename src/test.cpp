#include "RcppDL.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix rcpp_sda(SEXP x){

    double pretrain_lr = 0.1;
    double corruption_level = 0.3;
    int pretraining_epochs = 1000;
    double finetune_lr = 0.1;
    int finetune_epochs = 500;

    int train_N = 10;
    int test_N = 4;
    int n_ins = 28;
    int n_outs = 3;
    int hidden_layer_sizes[] = { 15, 15 };
    int n_layers = sizeof(hidden_layer_sizes) / sizeof(hidden_layer_sizes[0]);

    // training data
    int ** train_X = Rcpp::as<int **>(x);
    
    int train_Y[10][3] =
    {
        { 1, 0, 0 }, { 1, 0, 0 }, { 1, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, {
            0, 1,
            0
        }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }
    };

    // construct SdA
    SdA sda(train_N, n_ins, hidden_layer_sizes, n_outs, n_layers);

    // pretrain
    sda.pretrain(train_X, pretrain_lr, corruption_level, pretraining_epochs);

    // finetune
    sda.finetune(train_X, *train_Y, finetune_lr, finetune_epochs);

    // test data
    int test_X[4][28] = { {
            1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        }, {
            1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        }, {
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1
        },
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
            1, 1, 1, 1
        }
    };

    vector<vector<double> >test_Y(4);//[28];
    test_Y[0].resize(n_outs);
    test_Y[1].resize(n_outs);
    test_Y[2].resize(n_outs);
    test_Y[3].resize(n_outs);

    // test
    for (int i = 0; i < test_N; i++)
    {
        sda.predict(test_X[i], test_Y[i]);
    }

	return wrap(test_Y);
}
