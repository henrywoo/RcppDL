\name{metadata}
\alias{PretrainLearningRate}
\alias{CorruptionLevel}
\alias{PretrainingEpochs}
\alias{FinetuneLearningRate}
\alias{FinetuneEpochs}

\title{
  Access the metadata from a \code{deeplearning} object.
}

\usage{
PretrainLearningRate(object)
CorruptionLevel(object)
PretrainingEpochs(object)
FinetuneLearningRate(object)
FinetuneEpochs(object)
}
\arguments{
  \item{object}{An instantiated \code{deeplearning} object.}
}

\description{
  Accessors to the analytical setup metadata of a run.
  \code{summary} will show a summary of the paramters as a named list,
  including \code{PretrainLearningRate}, \code{CorruptionLevel}, \code{PretrainingEpochs},
  \code{FinetuneLearningRate}, \code{FinetuneEpochs}.
}

\author{
  Qiang Kou
}
