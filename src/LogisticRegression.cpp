#include <iostream>
#include <string>
#include <cmath>
#include "LogisticRegression.h"

LogisticRegression::LogisticRegression(int size, int in, int out) {
  N = size;
  n_in = in;
  n_out = out;

  // initialize W, b
  W.resize(n_out);
  for (int i = 0; i < n_out; i++)
    W[i].resize(n_in);

  b.resize(n_out);

  for (int i = 0; i < n_out; i++) {
    for (int j = 0; j < n_in; j++) {
      W[i][j] = 0;
    }
    b[i] = 0;
  }
}

void LogisticRegression::train(std::vector<int> x, std::vector<int> y,
                               double lr) {
//  double *p_y_given_x = new double[n_out];
  std::vector<double> p_y_given_x;
  p_y_given_x.resize(n_out);
  std::vector<double> dy;
  dy.resize(n_out);

  for (int i = 0; i < n_out; i++) {
    p_y_given_x[i] = 0;
    for (int j = 0; j < n_in; j++) {
      p_y_given_x[i] += W[i][j] * x[j];
    }
    p_y_given_x[i] += b[i];
  }
  softmax(p_y_given_x);

  for (int i = 0; i < n_out; i++) {
    dy[i] = y[i] - p_y_given_x[i];

    for (int j = 0; j < n_in; j++) {
      W[i][j] += lr * dy[i] * x[j] / N;
    }

    b[i] += lr * dy[i] / N;
  }
  p_y_given_x.clear();
}

void LogisticRegression::softmax(std::vector<double> &x) {
  double max = 0.0;
  double sum = 0.0;

  for (int i = 0; i < n_out; i++)
    if (max < x[i])
      max = x[i];
  for (int i = 0; i < n_out; i++) {
    x[i] = exp(x[i] - max);
    sum += x[i];
  }

  for (int i = 0; i < n_out; i++)
    x[i] /= sum;
}

void LogisticRegression::predict(std::vector<int> x, std::vector<double> &y) {
  for (int i = 0; i < n_out; i++) {
    y[i] = 0;
    for (int j = 0; j < n_in; j++) {
      y[i] += W[i][j] * x[j];
    }
    y[i] += b[i];
  }

  softmax(y);
}

