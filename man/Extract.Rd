\name{Extract}
\alias{s1}
\alias{sc}
\alias{d1}
\alias{d2}
\alias{dc}
\alias{t1}
\alias{t2}
\alias{t3}
\alias{tc}
\alias{s1,aaa-method}
\alias{sc,aaa-method}
\alias{d1,aaa-method}
\alias{d2,aaa-method}
\alias{dc,aaa-method}
\alias{t1,aaa-method}
\alias{t2,aaa-method}
\alias{t3,aaa-method}
\alias{tc,aaa-method}
\alias{single}
\alias{double}
\alias{triple}
\alias{single<-}
\alias{double<-}
\alias{triple<-}
\alias{getthings}
\alias{coeffs}
\title{Extract or Replace Parts of \code{aaa} objects}
\description{

  Extraction methods for \code{aaa} objects.  The names of the
  two-letter functions follow a pattern: the initial letter (s, d, t)
  stands for \dQuote{single}, \dQuote{double}, or \dQuote{triple}; the
  second symbol is c for \dQuote{coefficients}, or a number (1, 2, 3)
  denoting first, second, or third.  Thus \dQuote{\code{dc()}} gets the
  coefficients of the double-symbol components, and \dQuote{\code{t2()}}
  gets the second symbol of the triple-symbol components.

  Function \code{getthings()} is a lower-level method, not really
  intended for the end-user.

 }
 \usage{
\S4method{s1}{aaa}(a)
\S4method{sc}{aaa}(a)
\S4method{d1}{aaa}(a)
\S4method{d2}{aaa}(a)
\S4method{dc}{aaa}(a)
\S4method{t1}{aaa}(a)
\S4method{t2}{aaa}(a)
\S4method{t3}{aaa}(a)
\S4method{tc}{aaa}(a)
single(a)
double(a)
triple(a)
}
\arguments{\item{a}{Object of class \code{aaa}}}
\details{
  An \code{aaa} object is a list of 9 vectors, three numeric and six
  character, which are extractd by functions \code{s1()} etc.

  Functions \code{single()}, \code{double()} and
  \code{triple()} extract the single, double, and triple components
  of their argument, and return the corresponding \code{aaa} object.

  There is no function \code{evitaicoss::coeffs()} because the three
  types of elements are qualitatively different; use \code{sc()},
  \code{dc()}, and \code{tc()} to get the coefficients in \code{disord}
  format.
  
  }
\value{Return disord or \code{aaa} objects}
\author{Robin K. S. Hankin}
\examples{

a <- raaaa()
sc(a)
t2(a)
single(a)

single(a) + double(a) + triple(a) == a

aaa(d1=d1(a),d2=d2(a), dc=dc(a)) == double(a)

x <- raaaa()
single(x) <- 0
double(x) <- double(raaa())

}
