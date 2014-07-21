#include "dA.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List rcpp_dA(double learning_rate, double corruption_level, int training_epochs, int n_visible, int n_hidden, IntegerMatrix train, IntegerMatrix test) {

  vector<vector<int> > train_X = RcppMatrixToC2DArray(train);

  // construct dA
  dA da(train_X.size(), n_visible, n_hidden);

  // train
  for (int epoch = 0; epoch < training_epochs; epoch++) {
    for (int i = 0; i < train_X.size(); i++) {
      da.train(train_X[i], learning_rate, corruption_level);
    }
  }

  // test data
  vector<vector<int> > test_X = RcppMatrixToC2DArray(test);

  vector<vector<double> > reconstructed_X(test_X.size());

  for(int i = 0; i < test_X.size(); i++){
	  reconstructed_X[i].resize(test_X[i].size());
  }

  for (size_t i = 0; i < test_X.size(); i++) {
    da.reconstruct(test_X[i], reconstructed_X[i]);
  }
  
  return Rcpp::List::create(
                   Rcpp::_["weight"]  = CMatrixToRcppMatrix(da.W),
                   Rcpp::_["reconstruct"]  = CMatrixToRcppMatrix(reconstructed_X));
}

