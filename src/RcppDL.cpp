#include "RcppDL.h"

using namespace Rcpp;

RcppSDA::RcppSDA() {
	sda = (SdA *)malloc(sizeof(SdA *));
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
    
    sda = new SdA(train_N, n_ins, &hidden_layer_sizes[0], n_outs, n_layers);

}

void RcppSDA::pretrain(){
	
	sda->pretrain(train_X, pretrain_lr, corruption_level, pretraining_epochs);
	
}

void RcppSDA::finetune(){
	
	sda->finetune(train_X, train_Y, finetune_lr, finetune_epochs);
	
}

Rcpp::NumericMatrix RcppSDA::predict(SEXP test){
	
	int ** test_X = as<int**>(test);
    NumericMatrix t(test);
    double ** test_Y;
    int test_N = t.nrow();
    test_Y = new double*[test_N];

    for(int i=0; i< test_N; i++) {
        test_Y[i] = new double[n_outs];
        sda->predict(test_X[i], test_Y[i]);
    }

    return wrap(test_Y, test_N, n_outs);
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
    .method("pretrain", &RcppSDA::pretrain, "Pretrain Sda")
    .method("finetune", &RcppSDA::finetune, "Finetune Sda")
    .method("predict", &RcppSDA::predict, "Sda prediction")
    ;
}
