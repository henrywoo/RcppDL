/*
 * Denoising Autoencoders
 */

#ifndef DA_H_
#define DA_H_

#include <cmath>
#include <vector>

#include "utils.h"

class dA {

 public:
  int N;
  int n_visible;
  int n_hidden;
  vector<vector<double> > W;

  vector<double> hbias;
  vector<double> vbias;
  dA(int, int, int, vector<vector<double> >, vector<double>,
     std::vector<double>);
  dA(int, int, int);

  void get_corrupted_input(vector<int>, vector<int>&, double);
  void get_hidden_values(vector<int>, vector<double> &);
  void get_reconstructed_input(vector<double>, vector<double> &);
  void train(vector<int>, double, double);
  void reconstruct(vector<int>, vector<double> &);
};

#endif
