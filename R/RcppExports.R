

RcppDBN <- function(X, Y, pretrain_lr, pretraining_epochs, k, finetune_lr, finetune_epochs, hidden_layer, test) {
    .Call('RcppDL_rcpp_dbn', PACKAGE = 'RcppDL', X, Y, pretrain_lr, pretraining_epochs, k, finetune_lr, finetune_epochs, hidden_layer, test)
}
