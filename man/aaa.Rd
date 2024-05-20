\name{aaa}
\alias{aaa}
\title{
Function to create objects of class \code{aaa}
}
\description{

}
\usage{
aaa(s1 = character(0), sc = numeric(0), d1 = character(0), d2 = character(0), dc = numeric(0), t1 = character(0), t2 = character(0), t3 = character(0), tc = numeric(0))
}
\arguments{
  \item{s1,d1,d2,t1,t2,t3}{single, double, triple symbols}
  \item{sc,dc,tc}{single, double, triple coefficients}
  \item{cout}{list}
}
\details{

  Function \code{lavter()} is the formal creation method for \code{aaa}
  objects; it is the only place that \code{new()} is called.  It takes a
  single argumet \code{cout}, which is a list as returned by
  \proglang{C} function \code{retval()}.  But it is a little awkward to
  use and the user should use function \code{aaa()}, which is more
  user-friendly and has sensible defaults.

}
\value{Return objects of class \code{aaa}}
\author{Robin K. S. Hankin}
\examples{
aaa() # the zero object
aaa(s1=letters[1:5],sc=1:5)
aaa(d1=c("fish","chips"),d2=c("x","y"),dc=c(6,7))
}
