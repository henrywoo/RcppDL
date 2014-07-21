#include <iostream>

#include "dA.h"

dA::dA(int size, int n_v, int n_h, vector<vector<double> > w,
       vector<double> hb, vector<double> vb) {
  N = size;
  n_visible = n_v;
  n_hidden = n_h;

  if (w.size() == 0) {
    W.resize(n_hidden);

    for (int i = 0; i < n_hidden; i++)
      W[i].resize(n_visible);

    double a = 1.0 / n_visible;

    for (int i = 0; i < n_hidden; i++) {
      for (int j = 0; j < n_visible; j++) {
        W[i][j] = uniform(-a, a);
      }
    }
  } else {
    W = w;
  }

  if (hb.size() == 0) {
    hbias.resize(n_hidden);
    for (int i = 0; i < n_hidden; i++)
      hbias[i] = 0;
  } else {
    hbias = hb;
  }

  if (vb.size() == 0) {
    vbias.resize(n_visible);
    for (int i = 0; i < n_visible; i++)
      vbias[i] = 0;
  } else {
    vbias = vb;
  }
}

dA::dA(int size, int n_v, int n_h) {
  N = size;
  n_visible = n_v;
  n_hidden = n_h;

  W.resize(n_hidden);

  for (int i = 0; i < n_hidden; i++)
    W[i].resize(n_visible);

  double a = 1.0 / n_visible;

  for (int i = 0; i < n_hidden; i++) {
    for (int j = 0; j < n_visible; j++) {
      W[i][j] = uniform(-a, a);
    }
  }

  hbias.resize(n_hidden);
  for (int i = 0; i < n_hidden; i++)
    hbias[i] = 0;

  vbias.resize(n_visible);
  for (int i = 0; i < n_visible; i++)
    vbias[i] = 0;

}

void dA::get_corrupted_input(vector<int> x, vector<int> & tilde_x,
                             double p) {
  for (int i = 0; i < n_visible; i++) {
    if (x[i] == 0) {
      tilde_x[i] = 0;
    } else {
      tilde_x[i] = binomial(1, p);
    }
  }
}

// Encode
void dA::get_hidden_values(vector<int> x, vector<double> &y) {
  for (int i = 0; i < n_hidden; i++) {
    y[i] = 0;
    for (int j = 0; j < n_visible; j++) {
      y[i] += W[i][j] * x[j];
    }
    y[i] += hbias[i];
    y[i] = sigmoid(y[i]);
  }
}

// Decode
void dA::get_reconstructed_input(vector<double> y,
                                 vector<double> &z) {
  for (int i = 0; i < n_visible; i++) {
    z[i] = 0;
    for (int j = 0; j < n_hidden; j++) {
      z[i] += W[j][i] * y[j];
    }
    z[i] += vbias[i];
    z[i] = sigmoid(z[i]);
  }
}

void dA::train(vector<int> x, double lr, double corruption_level) {
  vector<int> tilde_x;
  tilde_x.resize(n_visible);
  vector<double> y;
  y.resize(n_hidden);
  vector<double> z;
  z.resize(n_visible);

vector<double> L_vbias;
L_vbias.resize(n_visible);

  vector<double> L_hbias;
   L_hbias.resize(n_hidden);

  double p = 1 - corruption_level;

  get_corrupted_input(x, tilde_x, p);
  get_hidden_values(tilde_x, y);
  get_reconstructed_input(y, z);

  // vbias
  for (int i = 0; i < n_visible; i++) {
    L_vbias[i] = x[i] - z[i];
    vbias[i] += lr * L_vbias[i] / N;
  }

  // hbias
  for (int i = 0; i < n_hidden; i++) {
    L_hbias[i] = 0;
    for (int j = 0; j < n_visible; j++) {
      L_hbias[i] += W[i][j] * L_vbias[j];
    }
    L_hbias[i] *= y[i] * (1 - y[i]);

    hbias[i] += lr * L_hbias[i] / N;
  }

  // W
  for (int i = 0; i < n_hidden; i++) {
    for (int j = 0; j < n_visible; j++) {
      W[i][j] += lr * (L_hbias[i] * tilde_x[j] + L_vbias[j] * y[i]) / N;
    }
  }


}

void dA::reconstruct(vector<int> x, vector<double> &z) {
  vector<double> y;
  y.resize(n_hidden);

  get_hidden_values(x, y);
  get_reconstructed_input(y, z);

//  delete[] y;
}

