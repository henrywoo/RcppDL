
Rsda <- function(x, y, pretrain_lr = 0.1, corruption_level = 0.3, pretraining_epochs = 1000, finetune_lr = 0.1, finetune_epochs = 500, hidden, test) {
    .Call('RcppDL_rcpp_sda', PACKAGE = 'RcppDL', x, y, pretrain_lr, corruption_level, pretraining_epochs, finetune_lr, finetune_epochs, hidden, test)
}

