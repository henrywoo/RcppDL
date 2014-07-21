#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

inline double uniform(double min, double max) {
  return rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

inline int binomial(int n, double p) {
  if (p < 0 || p > 1)
    return 0;

  int c = 0;
  double r;

  for (int i = 0; i < n; i++) {
    r = rand() / (RAND_MAX + 1.0);
    if (r < p)
      c++;
  }

  return c;
}

inline double sigmoid(double x) {
  return 1.0 / (1.0 + exp(-x));
}

inline vector<vector<int> > RcppMatrixToC2DArray(IntegerMatrix x) {
  int nrow = x.nrow(), ncol = x.ncol();
  vector<vector<int> > out(nrow);
  for (int i = 0; i < nrow; i++) {
    for (int j = 0; j < ncol; j++) {
      out[i].push_back(x(i, j));
    }
  }
  return out;
}
inline NumericMatrix CMatrixToRcppMatrix(vector<vector<double> > matrix) {
  NumericMatrix matrixOutput(matrix.size(), matrix[0].size());
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      matrixOutput(i, j) = matrix[i][j];
    }
  }
  return matrixOutput;
}
#endif
