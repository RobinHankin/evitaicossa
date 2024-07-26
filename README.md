Antiassociative algebra in R: introducing the `evitaicossa` package
================

<!-- README.md is generated from README.Rmd. Please edit that file -->

# <img src="man/figures/evitaicossa.png" width = "150" align="right" />

An *algebra* is a vector space equipped with a bilinear product: the
vectors may be multiplied. Algebras may be defined over any field but
here we use the real numbers. An *antiassociative* algebra is an algebra
in which the usual associativity relation
![\mathbf{u}(\mathbf{v} \mathbf{w})=(\mathbf{u} \mathbf{v})\mathbf{w}](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bu%7D%28%5Cmathbf%7Bv%7D%20%5Cmathbf%7Bw%7D%29%3D%28%5Cmathbf%7Bu%7D%20%5Cmathbf%7Bv%7D%29%5Cmathbf%7Bw%7D "\mathbf{u}(\mathbf{v} \mathbf{w})=(\mathbf{u} \mathbf{v})\mathbf{w}")
for vector multiplication is replaced by ![\mathbf{u}(\mathbf{v}
\mathbf{w})=-(\mathbf{u} \mathbf{v})\mathbf{w}](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bu%7D%28%5Cmathbf%7Bv%7D%0A%5Cmathbf%7Bw%7D%29%3D-%28%5Cmathbf%7Bu%7D%20%5Cmathbf%7Bv%7D%29%5Cmathbf%7Bw%7D "\mathbf{u}(\mathbf{v}
\mathbf{w})=-(\mathbf{u} \mathbf{v})\mathbf{w}"). Antiassociative
algebras are nilpotent of nilindex 4: the product of any four vectors is
zero. Antiassociative algebras are the direct sum of elements of degree
1,2 and 3 (the antiassociativity condition implies that the degree zero
component is trivial, and the nilpotence ensures that components of
degree four or above do not exist). Thus the general form of an element
of an antiassociative algebra is thus
![\scriptstyle\sum\_{i}\alpha_i\mathbf{x}\_i +
\sum\_{i,j}\alpha\_{ij}\mathbf{x}\_i\mathbf{x}\_j+
\sum\_{i,j,k}\alpha\_{ijk}(\mathbf{x}\_i\mathbf{x}\_j)\mathbf{x}\_k](https://latex.codecogs.com/png.latex?%5Cscriptstyle%5Csum_%7Bi%7D%5Calpha_i%5Cmathbf%7Bx%7D_i%20%2B%0A%5Csum_%7Bi%2Cj%7D%5Calpha_%7Bij%7D%5Cmathbf%7Bx%7D_i%5Cmathbf%7Bx%7D_j%2B%0A%5Csum_%7Bi%2Cj%2Ck%7D%5Calpha_%7Bijk%7D%28%5Cmathbf%7Bx%7D_i%5Cmathbf%7Bx%7D_j%29%5Cmathbf%7Bx%7D_k "\scriptstyle\sum_{i}\alpha_i\mathbf{x}_i +
\sum_{i,j}\alpha_{ij}\mathbf{x}_i\mathbf{x}_j+
\sum_{i,j,k}\alpha_{ijk}(\mathbf{x}_i\mathbf{x}_j)\mathbf{x}_k") where
![\scriptstyle\alpha\_{i}](https://latex.codecogs.com/png.latex?%5Cscriptstyle%5Calpha_%7Bi%7D "\scriptstyle\alpha_{i}"),
![\scriptstyle\alpha\_{ij}](https://latex.codecogs.com/png.latex?%5Cscriptstyle%5Calpha_%7Bij%7D "\scriptstyle\alpha_{ij}"),
![\scriptstyle\alpha\_{ijk}](https://latex.codecogs.com/png.latex?%5Cscriptstyle%5Calpha_%7Bijk%7D "\scriptstyle\alpha_{ijk}")
are constants and the
![\mathbf{x}\_i](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bx%7D_i "\mathbf{x}_i")
are indeterminates.

The `evitaicossa` package provides some R-centric functionality for
working with antiassociative algebras. In an R session, you can install
the released version of the package from
[CRAN](https://CRAN.R-project.org) with:

``` r
# install.packages("evitaicossa")  # uncomment to install the package
library("evitaicossa")             # loads the package 
```

The package includes a single S4 class `aaa` \[for
“**a**nti**a**ssociative **a**lgebra”\] and a range of functions to
create objects of this class. A good place to start is function
`raaa()`, which creates a random object of class `aaa`:

``` r
(evita <- raaa())
#> free antiassociative algebra element:
#> +1a +3b +2d +3a.b +1c.b +1c.c +1(a.b)a +1(b.b)c +1(b.c)a
(icossa <- raaa())
#> free antiassociative algebra element:
#> +4a +2b +2a.a +2c.c +2d.d +2(b.d)d +1(c.d)a +4(d.b)c
(itna <- raaa())
#> free antiassociative algebra element:
#> +2a +2c +4d +1b.d +2c.b +2c.d +3(b.a)d +3(b.b)c +4(b.c)b
```

Above, we see objects `evita`, `icossa` and `itna` are random
antiassociative algebra elements, with indeterminates `a`, `b`, `c`,
`d`. These objects may be combined with standard arithmetic operations:

``` r
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

For further details, see the package vignette

`vignette("evitaicossa")`
