
#include <Rcpp.h>

using namespace Rcpp;

// rcpp_dbn
NumericMatrix rcpp_dbn(IntegerMatrix X, IntegerMatrix Y, double pretrain_lr, int pretraining_epochs, int k, double finetune_lr, int finetune_epochs, IntegerVector hidden_layer, IntegerMatrix test);
RcppExport SEXP RcppDL_rcpp_dbn(SEXP XSEXP, SEXP YSEXP, SEXP pretrain_lrSEXP, SEXP pretraining_epochsSEXP, SEXP kSEXP, SEXP finetune_lrSEXP, SEXP finetune_epochsSEXP, SEXP hidden_layerSEXP, SEXP testSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< IntegerMatrix >::type X(XSEXP );
        Rcpp::traits::input_parameter< IntegerMatrix >::type Y(YSEXP );
        Rcpp::traits::input_parameter< double >::type pretrain_lr(pretrain_lrSEXP );
        Rcpp::traits::input_parameter< int >::type pretraining_epochs(pretraining_epochsSEXP );
        Rcpp::traits::input_parameter< int >::type k(kSEXP );
        Rcpp::traits::input_parameter< double >::type finetune_lr(finetune_lrSEXP );
        Rcpp::traits::input_parameter< int >::type finetune_epochs(finetune_epochsSEXP );
        Rcpp::traits::input_parameter< IntegerVector >::type hidden_layer(hidden_layerSEXP );
        Rcpp::traits::input_parameter< IntegerMatrix >::type test(testSEXP );
        NumericMatrix __result = rcpp_dbn(X, Y, pretrain_lr, pretraining_epochs, k, finetune_lr, finetune_epochs, hidden_layer, test);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
