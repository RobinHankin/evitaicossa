\name{Compare-methods}
\docType{methods}
\alias{Compare-methods}
\alias{Compare,aaa,aaa-method}
\alias{Compare,aaa,ANY-method}
\alias{Compare,aaa,numeric-method}
\alias{Compare,ANY,aaa-method}
\alias{Compare,numeric,aaa-method}
\alias{aaa_compare_aaa}
\alias{aaa_compare_error}
\title{Methods for Function \code{Compare}}
\description{

 Comparison methods generally do not make sense for elements of an
 antiassociative algebra.  The only exception is equality: \code{x == y}
 returns \code{TRUE} if \code{aaa} objects \code{x} and \code{y} are
 identical.

 The test is somewhat inefficient as \code{x == y} is syntactic sugar
 for \code{is.zero(x-y)}; a more efficient approach would be to follow
 the \CRANpkg{frab} package: go through the keys of \code{x}, compare
 the corresponding values of \code{y}, and return \code{FALSE} when any
 difference is detected.

 Technically, \code{x==0} makes sense but I thought consistency was more
 important: in the package, numeric values cannot be compared with
 \code{aaa} objects.
 
}
\section{Methods}{
\describe{

\item{\code{signature(e1 = "aaa", e2 = "aaa")}}{}
\item{\code{signature(e1 = "aaa", e2 = "ANY")}}{}
\item{\code{signature(e1 = "aaa", e2 = "numeric")}}{}
\item{\code{signature(e1 = "ANY", e2 = "aaa")}}{}
\item{\code{signature(e1 = "numeric", e2 = "aaa")}}{}
}}


