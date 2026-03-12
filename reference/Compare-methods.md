# Comparison methods for antiassociative algebra

Comparison methods generally do not make sense for elements of an
antiassociative algebra. The only exception is equality: `x == y`
returns `TRUE` if `aaa` objects `x` and `y` are identical.

The test for equality follows the
[frab](https://CRAN.R-project.org/package=frab) package: go through the
keys of `x`, compare the corresponding values of `y`, and return `FALSE`
when any difference is detected. This is faster than `is.zero(x-y)`.

Technically, `x==0` makes sense but I thought consistency was more
important: in the package, numeric values cannot be compared with `aaa`
objects.

Functions `aaa_compare_aaa()` etc. are used in S4 dispatch;
`c_aaa_equal()` is a low-level helper function that uses Rcpp to call
the appropriate C routine.

## Methods

- `signature(e1 = "aaa", e2 = "aaa")`:
- `signature(e1 = "aaa", e2 = "ANY")`:
- `signature(e1 = "aaa", e2 = "numeric")`:
- `signature(e1 = "ANY", e2 = "aaa")`:
- `signature(e1 = "numeric", e2 = "aaa")`:
