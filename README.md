Antiassociative algebra with the evitaicossa package
================

<!-- README.md is generated from README.Rmd. Please edit that file -->

# <img src="man/figures/evitaicossa.png" width = "150" align="right" />

An *algebra* is a vector space in which the vectors may be multiplied.
The `evitaicossa` package gives some R-centric functionality to deal
with *antiassociative* algebras in which the usual associativity
relation
![\mathbf{u}(\mathbf{v}\mathbf{w})=(\mathbf{u}\mathbf{v})\mathbf{w}](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bu%7D%28%5Cmathbf%7Bv%7D%5Cmathbf%7Bw%7D%29%3D%28%5Cmathbf%7Bu%7D%5Cmathbf%7Bv%7D%29%5Cmathbf%7Bw%7D "\mathbf{u}(\mathbf{v}\mathbf{w})=(\mathbf{u}\mathbf{v})\mathbf{w}")
is replaced by the relation
![\mathbf{u}(\mathbf{v}\mathbf{w})=-(\mathbf{u}\mathbf{v})\mathbf{w}](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bu%7D%28%5Cmathbf%7Bv%7D%5Cmathbf%7Bw%7D%29%3D-%28%5Cmathbf%7Bu%7D%5Cmathbf%7Bv%7D%29%5Cmathbf%7Bw%7D "\mathbf{u}(\mathbf{v}\mathbf{w})=-(\mathbf{u}\mathbf{v})\mathbf{w}").

In an R session, you can install the released version of `evitaicossa`
from [CRAN](https://CRAN.R-project.org) with:

``` r
# install.packages("evitaicossa")  # uncomment to install the package
library("evitaicossa")             # loads the package 
```

The package includes a single S4 class `aaa` \[for
“**a**nti**a**ssociative **a**lgebra”\] and a range of functions to
create objects of this class.

``` r
x <- as.aaa("x")
y <- as.aaa("y")
x
#> free antiassociative algebra element:
#> +1x
```

``` r
y
#> free antiassociative algebra element:
#> +1y
```
