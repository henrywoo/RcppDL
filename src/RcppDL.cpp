#include "RcppDL.h"

using namespace Rcpp;

RcppSDA::RcppSDA() {

    pretrain_lr = 0.1;
    corruption_level = 0.3;
    pretraining_epochs = 1000;
    finetune_lr = 0.1;
    finetune_epochs = 500;
}

void RcppSDA::init(SEXP x, SEXP y, SEXP hidden) {
    NumericMatrix xx(x);
    NumericMatrix yy(y);

    train_N = xx.nrow();
    n_ins = xx.ncol();
    n_outs = yy.ncol();

    hidden_layer_sizes = Rcpp::as<std::vector<int> >(hidden);

    int n_layers = 	hidden_layer_sizes.size();

    train_X = as<int**>(x);
    train_Y = as<int**>(y);

}

Rcpp::List RcppSDA::show() {
    return Rcpp::List::create(
               Rcpp::_["PretrainLearningRate"]	= pretrain_lr,
               Rcpp::_["CorruptionLevel"]	= corruption_level,
               Rcpp::_["PretrainingEpochs"]	= pretraining_epochs,
               Rcpp::_["FinetuneLearningRate"]	= finetune_lr,
               Rcpp::_["FinetuneEpochs"]	= finetune_epochs
           );
}


RCPP_MODULE(Sda) {
    using namespace Rcpp;

    class_<RcppSDA>("Sda")
    .constructor("Initialises a new Rccp Sda object.")
    .method("init", &RcppSDA::init, "Initialises a new Rccp Sda object.")
    .method("summary", &RcppSDA::show, "Summary abouth the Sda object")
    ;
}
