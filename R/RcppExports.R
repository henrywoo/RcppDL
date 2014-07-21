
RdA <- function(learning_rate = 0.1, corruption_level = 0.3, training_epochs = 100, n_visible = 20, n_hidden = 5, train, test) {
    .Call('RcppDL_rcpp_dA', PACKAGE = 'RcppDL', learning_rate, corruption_level, training_epochs, n_visible, n_hidden, train, test)
}
