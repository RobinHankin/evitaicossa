---
title: "evitaicossa: An R package for anti-associative algebra"
tags:
- R
- computational algebra
- symbolic computation
- associativity
- "anti-associativity"
date: "July 25th, 2024"
authors:
- name: Robin K. S. Hankin
  orcid: "0000-0001-5982-0415"
  affiliation: '1'
  corresponding: true
affiliations: name "University of Stirling"
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

and numerical verification
given, using the package.



# Statement of need

Software for working with antiassociative algebra does not appear to
be available.  The `evitaicossa` R package fills this need by the
provision of efficient software that operates within the R ecology.


# References
