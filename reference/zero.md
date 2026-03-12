# The additive zero in antiassociative algebras

Function `is.zero()` tests for its argument being the additive zero.

Package idiom to create the zero element of the antiassociative algebra
is
[`aaa()`](https://robinhankin.github.io/evitaicossa/reference/aaa.md).

## Usage

``` r
is.zero(x)
```

## Arguments

- x:

  Object of class `aaa`

## Value

Returns a Boolean.

## Author

Robin K. S. Hankin

## Note

In any antiassociative algebra, the only scalar is zero.

## Examples

``` r
is.zero(raaa())
#> [1] FALSE
is.zero(raaa()*0)
#> [1] TRUE
is.zero(aaa())
#> [1] TRUE
```
