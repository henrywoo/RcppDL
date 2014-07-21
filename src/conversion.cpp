#include "conversion.h"

int ** RcppMatrixToC2DArray(Rcpp::IntegerMatrix& in)
{

  int nrow = in.nrow();
  int ncol = in.ncol();
  
  int ** out = new int * [nrow];
  for (int i=0; i<nrow; i++)
  {

    out[i] = new int[ncol];

    for (int j=0; j<ncol; j++)
    {
      out[i][j] = in(i,j);
    }
  }
  return out;
}

Rcpp::NumericMatrix CMatrixToRcppMatrix(int nbSample, int pbDimension, double** matrix)
{

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

int * RcppVectorToCArray(Rcpp::IntegerVector& in)
{

  int size = in.size();
  int * out = new int[size];
  for (int i=0; i<size; i++)
  {
    out[i] = in[i];
  }
  return out;
}
