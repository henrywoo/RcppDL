#include "conversion.h"

int ** RcppMatrixToC2DArray(Rcpp::IntegerMatrix& in)
{
  // get the vector dimension
  int nrow = in.nrow();
  int ncol = in.ncol();
  
  // allocate columns
  int ** out = new int * [nrow];
  for (int i=0; i<nrow; i++)
  {
    // allocate rows
    out[i] = new int[ncol];
    // get values
    for (int j=0; j<ncol; j++)
    {
      out[i][j] = in(i,j);
    }
  }
  // return C matrix
  return out;
}

Rcpp::NumericMatrix CMatrixToRcppMatrix(int nbSample, int pbDimension, double** matrix)
{
  //NumericMatrix for matrix
  Rcpp::NumericMatrix matrixOutput(nbSample,pbDimension);
  for(int i=0;i<nbSample;i++)
  {
    for(int j=0;j<pbDimension;j++)
    {
      matrixOutput(i,j) = matrix[i][j];
    }
  }
  return matrixOutput;
}
