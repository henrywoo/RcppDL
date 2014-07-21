#include "RcppDL.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix rcpp_dbn(IntegerMatrix X, IntegerMatrix Y, double pretrain_lr, int pretraining_epochs, 
              int k, double finetune_lr, int finetune_epochs, IntegerVector hidden_layer, IntegerMatrix test) {

    //double pretrain_lr = 0.1;
    //int pretraining_epochs = 1000;
    //int k = 1;
    //double finetune_lr = 0.1;
    //int finetune_epochs = 500;
    int train_N = X.nrow();
    int n_ins = X.ncol();
	int n_outs = Y.ncol();
	int * hidden_layer_sizes = RcppVectorToCArray(hidden_layer);
	int n_layers = hidden_layer.size();
	int ** train_X = RcppMatrixToC2DArray(X);
	int ** train_Y = RcppMatrixToC2DArray(Y);
	
	DBN dbn(train_N, n_ins, hidden_layer_sizes, n_outs, n_layers);

  // pretrain
  dbn.pretrain(*train_X, pretrain_lr, k, pretraining_epochs);

  // finetune
  dbn.finetune(*train_X, *train_Y, finetune_lr, finetune_epochs);
  
  double ** test_Y;
  int** test_X = RcppMatrixToC2DArray(test);
  int test_N = test.nrow();
  test_Y = new double *[test_N];
  for(int i=0; i<test_N; i++) {
	  test_Y[i] = new double[n_outs];
    dbn.predict(test_X[i], test_Y[i]);

  }
  
  return CMatrixToRcppMatrix(test_N, n_outs, test_Y);
}

