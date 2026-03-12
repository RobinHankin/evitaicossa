# Print method for antiassociative algebra objects

Show methods for `aaa` objects

## Usage

``` r
# S4 method for class 'aaa'
show(object)
aaa_show(a)
```

## Arguments

- a,object:

  Object of class `aaa`

## Details

A bunch of functionality to print `aaa` objects.

Function `putsign()` is a low-level helper function that puts the sign
(that is, `+` or `-`) before each element of a numeric vector. Functions
`single_string()`, `double_string()`, and `triple_string()` process the
1,2, and 3- symbols for printing.

## Value

No return value, called for side-effects

## Author

Robin K. S. Hankin

## Examples

``` r
aaa_show(raaa())
#> [1] +1a +4b +2c +4a.b +1c.b +2d.d +4(a.c)b +2(b.d)a +1(d.d)c
aaa_show(aaa())
#> [1]   
```
