#include "RcppDL.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix rcpp_sda(SEXP x, SEXP y, double pretrain_lr, double corruption_level, int pretraining_epochs,
                       double finetune_lr, int finetune_epochs, SEXP hidden, SEXP test)
{

    NumericMatrix xx(x);
    NumericMatrix yy(y);
    int train_N = xx.nrow();
    int test_N = 4;
    int n_ins = xx.ncol();
    int n_outs = yy.ncol();
    std::vector<int> hidden_layer_sizes = Rcpp::as<std::vector<int> >(hidden);

    int n_layers = 	hidden_layer_sizes.size();

    // training data
    int ** train_X = Rcpp::as<int **>(x);

    int ** train_Y = Rcpp::as<int **>(y);

    // construct SdA
    SdA sda(train_N, n_ins, hidden_layer_sizes, n_outs, n_layers);

    // pretrain
    sda.pretrain(train_X, pretrain_lr, corruption_level, pretraining_epochs);

    // finetune
    sda.finetune(train_X, train_Y, finetune_lr, finetune_epochs);

    // test data
    int ** test_X = Rcpp::as<int **>(test);

    vector<vector<double> >test_Y(test_N);
    for(int i = 0; i < test_Y.size(); i++)
    {
        test_Y[i].resize(n_outs);
    }

    for (int i = 0; i < test_N; i++)
    {
        sda.predict(test_X[i], test_Y[i]);
    }

    return wrap(test_Y);
}
