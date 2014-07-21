#ifndef LOGISTIC_H_
#define LOGISTIC_H_

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

//#include <armadillo>

class LogisticRegression {

 public:
  int N;  // num of inputs
  int n_in;
  int n_out;
  std::vector<std::vector<double> > W;
//  arma::mat w;
  std::vector<double> b;
  LogisticRegression(int, int, int);

  void train(std::vector<int>, std::vector<int>, double);
  void softmax(std::vector<double> &x);
  void predict(std::vector<int> x, std::vector<double> &y);
};

#endif
