\name{zero}
\alias{zero}
\alias{is.zero}
\title{The additive zero in antiassociative algebras}
\description{
Function \code{is.zero()} tests for its argument being the additive
zero.
}
\usage{
is.zero(x)
}
\arguments{
  \item{x}{Object of class \code{aaa}}
}
\value{Returns a Boolean.}
\author{Robin K. S. Hankin}
\note{
In any antiassociative algebra, the only scalar is zero.
}
\examples{
is.zero(raaa())
}
