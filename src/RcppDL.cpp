#include "RcppDL.h"

using namespace Rcpp;

RcppDA::RcppDA() {

    da = (dA *)malloc(sizeof(dA *));
    learning_rate = 0.1;
    corruption_level = 0.3;
    training_epochs = 100;
    n_hidden = 5;

}

void RcppDA::init(SEXP x) {
    train_X = as<int**>(x);
    NumericMatrix xx(x);
    train_N = xx.nrow();
    n_visible = xx.ncol();
    da = new dA(train_N, n_visible, n_hidden, NULL, NULL, NULL);
}

void RcppDA::train() {

    for(int epoch = 0; epoch < training_epochs; epoch++) {
        for(int i=0; i<train_N; i++) {
            da->train(train_X[i], learning_rate, corruption_level);
        }
    }
}

NumericMatrix RcppDA::reconstruct(SEXP test) {

    int ** test_X = as<int**>(test);
    NumericMatrix t(test);
    double ** reconstructed_X;
    int test_N = t.nrow();
    reconstructed_X = new double*[test_N];
    for(int i = 0; i< test_N; i++) {
        reconstructed_X[i] = new double[n_visible];
        da->reconstruct(test_X[i], reconstructed_X[i]);
    }
    return wrap(reconstructed_X, test_N, n_visible);
}

Rcpp::List RcppDA::show() {
    return Rcpp::List::create(
               Rcpp::_["LearningRate"] = learning_rate,
               Rcpp::_["CorruptionLevel"] = corruption_level,
               Rcpp::_["TrainingEpochs"] = training_epochs,
               Rcpp::_["HiddenRepresentation"] = n_hidden
           );
}

RCPP_MODULE(dA) {
    using namespace Rcpp;

    class_<RcppDA>("dA")
    .constructor("Initialises a new Rccp dA object.")
    .method("init", &RcppDA::init, "Initialises a new Rccp dA object.")
    .method("summary", &RcppDA::show, "Summary abouth the dA object")
    .method("train", &RcppDA::train, "Train the dA")
    .method("reconstruct", &RcppDA::reconstruct, "dA reconstruct")
    .method("setLearningRate", &RcppDA::setlr, "Set learning rate")
    .method("setCorruptionLevel", &RcppDA::setcl, "Set corruption level")
    .method("setTrainingEpochs", &RcppDA::setTE, "Set trainingepochs")
    .method("setHiddenRepresentation", &RcppDA::setHidden, "Set hidden representation")
    ;
}

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

void RcppSDA::pretrain() {

    sda->pretrain(train_X, pretrain_lr, corruption_level, pretraining_epochs);

}

void RcppSDA::finetune() {

    sda->finetune(train_X, train_Y, finetune_lr, finetune_epochs);

}

Rcpp::NumericMatrix RcppSDA::predict(SEXP test) {

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

RCPP_EXPOSED_CLASS_NODECL(RcppSDA)
RCPP_MODULE(Sda) {
    using namespace Rcpp;

    class_<RcppSDA>("Sda")
    .constructor("Initialises a new Rccp Sda object.")
    .method("init", &RcppSDA::init, "Initialises a new Rccp Sda object.")
    .method("summary", &RcppSDA::show, "Summary abouth the Sda object")
    .method("pretrain", &RcppSDA::pretrain, "Pretrain Sda")
    .method("setPretrainEpochs", &RcppSDA::setPE, "Set pretrain epochs")
    .method("setPretrainLearningRate", &RcppSDA::setPlr, "Set pretrain learning rate")
    .method("setFinetuneEpochs", &RcppSDA::setFE, "Set finetune epochs")
    .method("setFinetuneLearningRate", &RcppSDA::setFlr, "Set finetune learning rate")
    .method("setCorruptionLevel", &RcppSDA::setcl, "Set corruption level rate")
    .method("finetune", &RcppSDA::finetune, "Finetune Sda")
    .method("predict", &RcppSDA::predict, "Sda prediction")
    ;
}
