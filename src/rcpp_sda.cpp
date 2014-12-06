#include "RcppDL.h"

#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
NumericMatrix rcpp_sda(SEXP x, SEXP y, double pretrain_lr, double corruption_level, int pretraining_epochs,
                       double finetune_lr, int finetune_epochs, SEXP hidden, SEXP test) {

    pretrain_lr = 0.1;
    corruption_level = 0.3;
    pretraining_epochs = 1000;
    finetune_lr = 0.1;
    finetune_epochs = 500;
    NumericMatrix xx(x);
    NumericMatrix yy(y);

    int train_N = xx.nrow();
    int n_ins = xx.ncol();
    int n_outs = yy.ncol();

    std::vector<int> hidden_layer_sizes = Rcpp::as<std::vector<int> >(hidden);

    int n_layers = 	hidden_layer_sizes.size();

    int ** train_X = as<int**>(x);
    int ** train_Y = as<int**>(y);

    SdA sda(train_N, n_ins, &hidden_layer_sizes[0], n_outs, n_layers);

    sda.pretrain(train_X, pretrain_lr, corruption_level, pretraining_epochs);

    sda.finetune(train_X, train_Y, finetune_lr, finetune_epochs);

    int ** test_X = as<int**>(test);
    NumericMatrix t(test);
    double ** test_Y;
    int test_N = t.nrow();
    test_Y = new double*[test_N];

    for(int i=0; i< test_N; i++) {
        test_Y[i] = new double[n_outs];
        sda.predict(test_X[i], test_Y[i]);
    }

    return wrap(test_Y, test_N, n_outs);
}
