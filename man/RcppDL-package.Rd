\name{RcppDL-package}
\alias{RcppDL-package}
\alias{RcppDL}
\docType{package}
\title{
Deep learning package using Rcpp
}
\description{
Deep learning package using Rcpp
}
\details{
\tabular{ll}{
Package: \tab RcppDL\cr
Type: \tab Package\cr
Version: \tab 0.0.1\cr
Date: \tab 2014-07-20\cr
License: \tab GPL3 \cr
}
~~ An overview of how to use the package, including the most important ~~
~~ functions ~~
}
\author{
Qiang Kou, Yusuke Sugomori

Maintainer: Qiang Kou <qkou@umail.iu.edu>
}
\references{
~~ Literature or other references for background information ~~
}
~~ Optionally other standard keywords, one per line, from file KEYWORDS in ~~
~~ the R documentation directory ~~
\keyword{ package }
\seealso{
~~ Optional links to other man pages, e.g. ~~
~~ \code{\link[<pkg>:<pkg>-package]{<pkg>}} ~~
}
\examples{
x<- c( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0 , 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,
      1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1,
      1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      1, 1, 1, 1, 1, 1, 1, 1 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
      1, 1, 1, 0, 1 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
      1, 1 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 )
      
y <- matrix(x, 20, 10)

x <-c( 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0)

z <- matrix(x,20, 2)

rcpp_dA(train=t(y), test=t(z))
}
