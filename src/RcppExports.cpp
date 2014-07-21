#include <Rcpp.h>

using namespace Rcpp;

// rcpp_dA
NumericMatrix rcpp_dA(double learning_rate, double corruption_level, int training_epochs, int n_visible, int n_hidden, IntegerMatrix train, IntegerMatrix test);
RcppExport SEXP RcppDL_rcpp_dA(SEXP learning_rateSEXP, SEXP corruption_levelSEXP, SEXP training_epochsSEXP, SEXP n_visibleSEXP, SEXP n_hiddenSEXP, SEXP trainSEXP, SEXP testSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< double >::type learning_rate(learning_rateSEXP );
        Rcpp::traits::input_parameter< double >::type corruption_level(corruption_levelSEXP );
        Rcpp::traits::input_parameter< int >::type training_epochs(training_epochsSEXP );
        Rcpp::traits::input_parameter< int >::type n_visible(n_visibleSEXP );
        Rcpp::traits::input_parameter< int >::type n_hidden(n_hiddenSEXP );
        Rcpp::traits::input_parameter< IntegerMatrix >::type train(trainSEXP );
        Rcpp::traits::input_parameter< IntegerMatrix >::type test(testSEXP );
        NumericMatrix __result = rcpp_dA(learning_rate, corruption_level, training_epochs, n_visible, n_hidden, train, test);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
