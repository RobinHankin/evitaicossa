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
numbers.  Associativity (that is, the assumption
$\mathbf{u}(\mathbf{v} \mathbf{w})=(\mathbf{u} \mathbf{v})\mathbf{w}$
for vectors $\mathbf{u}, \mathbf{v}, \mathbf{w}$ is not generally an
axiom and non-associative algebras include Jordan algebra
[@hankin2023_jordan] and the octonions [@hankin2006_onion].

An _antiassociative_ algebra is an algebra in which the usual
associativity relation $\mathbf{u}(\mathbf{v} \mathbf{w})=(\mathbf{u}
\mathbf{v})\mathbf{w}$ for vector multiplication is replaced by
$\mathbf{u}(\mathbf{v} \mathbf{w})=-(\mathbf{u}
\mathbf{v})\mathbf{w}$.  Antiassociative algebras are nilpotent of
nilindex 4: the product of any four vectors is zero.  Antiassociative
algebras are the direct sum of elements of degree 1,2 and 3 (the
antiassociativity condition implies that the degree zero component is
trivial, and the nilpotence ensures that components of degree four or
above do not exist).  Thus the general form of an element of an
antiassociative algebra is thus
$\scriptstyle\sum_{i}\alpha_i\mathbf{x}_i +
\sum_{i,j}\alpha_{ij}\mathbf{x}_i\mathbf{x}_j+
\sum_{i,j,k}\alpha_{ijk}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k$ where
$\scriptstyle\alpha_{i}$, $\scriptstyle\alpha_{ij}$,
$\scriptstyle\alpha_{ijk}$ are constants and the $\mathbf{x}_i$ are
indeterminates.  Addition is performed elementwise among the single-,
double-, and triple- components; the result is the (formal)
composition of the three results.  Given


$$A=
\sum_{i}\alpha_i\mathbf{x}_i +
\sum_{i,j}\alpha_{ij}\mathbf{x}_i\mathbf{x}_j+
\sum_{i,j,k}\alpha_{ijk}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k
$$

$$B=
\sum_{i}\beta_i\mathbf{x}_i +
\sum_{i,j}\beta_{ij}\mathbf{x}_i\mathbf{x}_j+
\sum_{i,j,k}\beta_{ijk}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k
$$

(where the sums run from $1$ to $n$), we define the sum $A+B$ to be

$$
\sum_{i}(\alpha_i+\beta_i)\mathbf{x}_i +
\sum_{i,j}(\alpha_{ij}+\beta_{ij})\mathbf{x}_i\mathbf{x}_j+
\sum_{i,j,k}(\alpha_{ijk}+\beta_{ijk})(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k
$$

Multiplication is slightly more involved.  We define the product $AB$
to be

$$
\sum_{i,j}\alpha_i\beta_{ij}\mathbf{x}_i\mathbf{x}_j
+\sum_{i,j,k}\alpha_{ij}\beta_{k}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k
-\sum_{i,j,k}\alpha_i\beta_{jk}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k.
$$

The minus sign in front of the third term embodies antiassociativity.

# The `evitaicossa` package in use

The `evitaicossa` package implements these relations in the context of
an R-centric suite of software.  I give some examples of the package
in use.  A good place to start is function `raaa()`, which returns a
simple random element of the free antiassociative algebra:

``` r
(evita <- raaa())
#> free antiassociative algebra element:
#> +1a +3b +2d +3a.b +1c.b +1c.c +1(a.b)a +1(b.b)c +1(b.c)a
```

Above we see that the print method returns a natural symbolic
representation of its argument.  Arithmetic operations are supported:

``` r
icossa <- raaa()
itna <- raaa()
evita+icossa
#> free antiassociative algebra element:
#> +5a +5b +2d +2a.a +3a.b +1c.b +3c.c +2d.d +1(a.b)a +1(b.b)c +1(b.c)a +2(b.d)d
#> +1(c.d)a +4(d.b)c
evita*icossa
#> free antiassociative algebra element:
#> +4a.a +2a.b +12b.a +6b.b +8d.a +4d.b -2(a.a)a +12(a.b)a +6(a.b)b -2(a.c)c
#> -2(a.d)d -6(b.a)a -6(b.c)c -6(b.d)d +4(c.b)a +2(c.b)b +4(c.c)a +2(c.c)b
#> -4(d.a)a -4(d.c)c -4(d.d)d
```

It is possible to verify some of the axioms as follows:

``` r
c(
left_distributive  = evita*(icossa + itna) == evita*icossa + evita*itna,
right_distributive = (evita + icossa)*itna == evita*itna + icossa*itna,
antiassociative    = evita*(icossa*itna)   == -(evita*icossa)*itna
)
#>  left_distributive right_distributive    antiassociative 
#>               TRUE               TRUE               TRUE
```

As a final illustration, we may verify the identity
$\left(\mathbf{a}+\mathbf{a}\mathbf{x}\right)
\left(\mathbf{b}+\mathbf{x}\mathbf{b}\right) =\mathbf{a}\mathbf{b}$:


``` r
a <- raaa()
b <- raaa()
x <- raaa()
(a + a*x)*(b + x*b) == a*b
#> [1] TRUE
```

# Statement of need

Software for working with antiassociative algebra does not appear to
be available.  The `evitaicossa` R package fills this need by the
provision of efficient software that operates within the R ecology.


# References
