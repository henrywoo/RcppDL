#ifndef RCPPDL_H_
#define RCPPDL_H_

#include <RcppCommon.h>

namespace Rcpp
{
template <> int** as(SEXP x)
{
    SEXP dim = Rf_getAttrib( x, R_DimSymbol ) ;
    int nrow = INTEGER(dim)[0];
    int ncol = INTEGER(dim)[1];
    int ** res;
    double * p = REAL(x);
    res = new int*[nrow];
    int i,j;
    for( i=0; i<nrow; i++)
    {
        res[i] = new int[ncol];
        for( j=0; j<ncol; j++)
        {
            res[i][j] = (int)p[i+nrow*j];
        }
    }
    return res;
}

template <> SEXP wrap(const std::vector<std::vector<double> > &object);
}

#include <Rcpp.h>

namespace Rcpp
{

template <> inline SEXP wrap(const std::vector<std::vector<double> > &object)
{
    std::vector<double> vec;
    for(int i = 0; i < object.size(); i++)
    {
        vec.insert(vec.end(), object[i].begin(), object[i].end());
    }
    NumericVector output = wrap(vec);
    output.attr("dim") = Dimension(object[0].size(), object.size());
    return output;
}
}

#include "deeplearning/dA.h"
#include "deeplearning/DBN.h"
#include "deeplearning/HiddenLayer.h"
#include "deeplearning/LogisticRegression.h"
#include "deeplearning/RBM.h"
#include "deeplearning/SdA.h"

#endif
