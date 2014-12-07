\name{metadata}
\alias{PretrainLearningRate}
\alias{CorruptionLevel}
\alias{PretrainingEpochs}
\alias{FinetuneLearningRate}
\alias{FinetuneEpochs}
\alias{Step}
\alias{HiddenRepresentation}

\title{
  Access the metadata from a \code{deeplearning} object.
}

\usage{
PretrainLearningRate(object)
CorruptionLevel(object)
PretrainingEpochs(object)
FinetuneLearningRate(object)
FinetuneEpochs(object)
Step(object)
HiddenRepresentation(object)
}
\arguments{
  \item{object}{An instantiated \code{deeplearning} object.}
}

\description{
  Accessors to the metadata of a \code{deeplearning} object.
  \code{summary} will show a summary of the paramters as a named list,
  and other functions will return corresponding features.
}

\author{
  Qiang Kou
}
