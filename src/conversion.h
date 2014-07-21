#ifndef CONVERSION_H_
#define CONVERSION_H_

#include "Rcpp.h"

int ** RcppMatrixToC2DArray(Rcpp::IntegerMatrix& in);

int * RcppVectorToCArray(Rcpp::IntegerVector& in);

Rcpp::NumericMatrix CMatrixToRcppMatrix(int nbSample, int pbDimension, double** matrix);

#endif
