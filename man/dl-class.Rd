\name{deeplearning-class}
\docType{class}
\alias{deeplearning-class}
\alias{da-class}
\alias{sda-class}
\alias{rbm-class}
\alias{dbn-class}
\alias{Rcpp_Sda-class}
\alias{Rcpp_dA-class}
\alias{Rcpp_Rbm-class}
\alias{Rcpp_Dbn-class}
\alias{class:deeplearning}
\alias{class:sda}
\alias{class:Rcpp_Sda}
\alias{class:da}
\alias{class:Rcpp_dA}
\alias{summary,da-method}
\alias{CorruptionLevel,da-method}
\alias{TrainingEpochs,da-method}
\alias{LearningRate,da-method}
\alias{HiddenRepresentation,da-method}
\alias{train,da-method}
\alias{reconstruct,da,matrix-method}
\alias{setCorruptionLevel,da,numeric-method}



\alias{summary,sda-method}
\alias{CorruptionLevel,sda-method}
\alias{LearningRate,sda-method}
\alias{PretrainLearningRate,sda-method}
\alias{PretrainingEpochs,sda-method}
\alias{FinetuneEpochs,sda-method}
\alias{FinetuneLearningRate,sda-method}
\alias{pretrain,sda-method}
\alias{finetune,sda-method}
\alias{predict,sda,matrix-method}
\alias{setCorruptionLevel,sda,numeric-method}


\alias{summary,rbm-method}
\alias{TrainingEpochs,rbm-method}
\alias{LearningRate,rbm-method}
\alias{HiddenRepresentation,rbm-method}
\alias{Step,rbm-method}
\alias{train,rbm-method}
\alias{reconstruct,rbm,matrix-method}

\alias{summary,dbn-method}
\alias{LearningRate,dbn-method}
\alias{PretrainLearningRate,dbn-method}
\alias{PretrainingEpochs,dbn-method}
\alias{FinetuneEpochs,dbn-method}
\alias{FinetuneLearningRate,dbn-method}
\alias{Step,dbn-method}
\alias{pretrain,dbn-method}
\alias{finetune,dbn-method}
\alias{predict,dbn,matrix-method}



\title{Class \code{deeplearning} and sub-classes}
\description{
  The class \code{deeplearning} is the main class for deep learning
  methods in this package. It is a virtual class and thus not supposed to be instanciated
  directly.

  The sub-classes implement four methods: \code{da} for denoising autoencoder;
  \code{sda} for stacked denoising autoencoder; \code{rbm} for restricted Boltzmann machine;
  \code{dbn} for deep belief net.
}
\author{
  Qiang Kou
}

\section{Methods}{
  Methods currently implemented for \code{da}
  \describe{
    \item{summary}{\code{signature(object = "da")}: ... }
    \item{train}{\code{signature(object = "da")}: ... }
    \item{CorruptionLevel}{\code{signature(object = "da")}: ... }
    \item{LearningRate}{\code{signature(object = "da")}: ... }
    \item{reconstruct}{\code{signature(object = "da", test = "matrix")}: ... }
    \item{setCorruptionLevel}{\code{signature(object = "da", cl = "numeric")}: ... }
  }
  Methods currently implemented for \code{sda}
  \describe{
    \item{summary}{\code{signature(object = "sda")}: ... }
    \item{pretrain}{\code{signature(object = "sda")}: ... }
    \item{finetune}{\code{signature(object = "sda")}: ... }
    \item{predict}{\code{signature(object = "sda", test = "matrix")}: ... }
    \item{CorruptionLevel}{\code{signature(object = "sda")}: ... }
    \item{LearningRate}{\code{signature(object = "sda")}: ... }
    \item{FinetuneEpochs}{\code{signature(object = "sda")}: ... }
    \item{FinetuneLearningRate}{\code{signature(object = "sda")}: ... }
    \item{setCorruptionLevel}{\code{signature(object = "da", cl = "numeric")}: ... }
  }
  Methods currently implemented for \code{rbm}
  \describe{
    \item{summary}{\code{signature(object = "rbm")}: ... }
    \item{train}{\code{signature(object = "rbm")}: ... }
    \item{LearningRate}{\code{signature(object = "rbm")}: ... }
    \item{reconstruct}{\code{signature(object = "rbm", test = "matrix")}: ... }
  }
  Methods currently implemented for \code{dbn}
  \describe{
    \item{summary}{\code{signature(object = "dbn")}: ... }
    \item{pretrain}{\code{signature(object = "dbn")}: ... }
    \item{finetune}{\code{signature(object = "dbn")}: ... }
    \item{predict}{\code{signature(object = "dbn", test = "matrix")}: ... }
    \item{LearningRate}{\code{signature(object = "dbn")}: ... }
    \item{FinetuneEpochs}{\code{signature(object = "dbn")}: ... }
    \item{FinetuneLearningRate}{\code{signature(object = "dbn")}: ... }
  }
}

\examples{
 data(test)
 dbn_test <- Rdbn(train_X, train_Y, hidden)
 summary(dbn_test)
 LearningRate(dbn_test)
 pretrain(dbn_test)
 finetune(dbn_test)
 predict(dbn_test, test_X)
}
\keyword{classes}
