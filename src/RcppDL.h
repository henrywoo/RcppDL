#ifndef RCPPDL_H_
#define RCPPDL_H_

#include <vector>
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
        int i, j;
        for(i = 0; i < nrow; i++)
        {
            res[i] = new int[ncol];
            for(j = 0; j < ncol; j++)
            {
                res[i][j] = (int)p[i + nrow * j];
            }
        }
        return res;
    }
}

#include <Rcpp.h>

namespace Rcpp{
	
	NumericMatrix wrap(int ** m , int nrow, int ncol){
			
		std::vector<int> vec;
	
		for(int i = 0; i < nrow; i++)
		{
			for(int j = 0; j < ncol; j++)
				vec.push_back(m[i][j]);
		}
        
		NumericVector output = wrap(vec);
        
		output.attr("dim") = Dimension(nrow, ncol);

		return wrap(output);
	}
	
	NumericMatrix wrap(double ** m , int nrow, int ncol){
			
		std::vector<double> vec;
	
		for(int i = 0; i < ncol; i++)
		{
			for(int j = 0; j < nrow; j++)
				vec.push_back(m[j][i]);
		}
        
		NumericVector output = wrap(vec);
        
		output.attr("dim") = Dimension(nrow, ncol);

		return wrap(output);
	}
}

#include "deeplearning/dA.h"
#include "deeplearning/DBN.h"
#include "deeplearning/HiddenLayer.h"
#include "deeplearning/LogisticRegression.h"
#include "deeplearning/RBM.h"
#include "deeplearning/SdA.h"

#endif
