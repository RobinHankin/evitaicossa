---
title: "evitaicossa: An R package for anti-associative algebra"
tags:
- R
- computational algebra
- symbolic computation
- associativity
- "anti-associativity"
date: "July 26th, 2024"
authors:
- name: Robin K. S. Hankin
  orcid: "0000-0001-5982-0415"
  affiliation: "1"
  corresponding: true
affiliations:
- name: "University of Stirling"
  index: 1
bibliography: paper.bib
---

# Summary

Non-associative algebras are interesting and useful objects that have
applications throughout mathematices and physics; examples would
include the octonions, Jordan algebra, and Lie algebra.
Antiassociative algebras obey the relation
$\mathbf{x}(\mathbf{y}\mathbf{z}) = -(\mathbf{x}\mathbf{y})\mathbf{z}$
and appear to have interesting and non-trivial structure [@remm2024].

Here I introduce the `evitaicossa` R package for antiassociative
algebras.  In the associated package documentation, design decisions
are motivated, and examples of the software in use are given.  A new
identity is presented:

$$
\left(\mathbf{a}+\mathbf{a}\mathbf{x}\right)
\left(\mathbf{b}+\mathbf{x}\mathbf{b}\right)
=
\mathbf{a}\mathbf{b}
$$

and numerical verification given, using the package.


# Introduction

An *algebra* is a vector space [@cohn1984] equipped with a bilinear
product [@bourbaki2012]: the vectors may be multiplied.  Algebras may
be defined over any field [@schafer1994] but here we use the real
numbers.  An _antiassociative_ algebra is an algebra in which the
usual associativity relation $\mathbf{u}(\mathbf{v}
\mathbf{w})=(\mathbf{u} \mathbf{v})\mathbf{w}$ for vector
multiplication is replaced by $\mathbf{u}(\mathbf{v}
\mathbf{w})=-(\mathbf{u} \mathbf{v})\mathbf{w}$.  Antiassociative
algebras are nilpotent of nilindex 4: the product of any four vectors
is zero.  Antiassociative algebras are the direct sum of elements of
degree 1,2 and 3 (the antiassociativity condition implies that the
degree zero component is trivial, and the nilpotence ensures that
components of degree four or above do not exist).  Thus the general
form of an element of an antiassociative algebra is thus
$\scriptstyle\sum_{i}\alpha_i\mathbf{x}_i +
\sum_{i,j}\alpha_{ij}\mathbf{x}_i\mathbf{x}_j+
\sum_{i,j,k}\alpha_{ijk}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k$ where
$\scriptstyle\alpha_{i}$, $\scriptstyle\alpha_{ij}$,
$\scriptstyle\alpha_{ijk}$ are constants and the $\mathbf{x}_i$ are
indeterminates.


# Statement of need

Software for working with antiassociative algebra does not appear to
be available.  The `evitaicossa` R package fills this need by the
provision of efficient software that operates within the R ecology.


# References
