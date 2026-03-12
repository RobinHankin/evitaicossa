# Extract or Replace Parts of `aaa` objects

Extraction methods for `aaa` objects. The names of the two-letter
functions and arguments follow a pattern: the initial letter (s, d, t)
stands for “single”, “double”, or “triple”; the second symbol is c for
“coefficients”, or a number (1, 2, 3) denoting first, second, or third.
Thus “`dc()`” gets the coefficients of the double-symbol components, and
“`t2()`” gets the second symbol of the triple-symbol components.

## Usage

``` r
# S4 method for class 'aaa'
s1(a)
# S4 method for class 'aaa'
sc(a)
# S4 method for class 'aaa'
d1(a)
# S4 method for class 'aaa'
d2(a)
# S4 method for class 'aaa'
dc(a)
# S4 method for class 'aaa'
t1(a)
# S4 method for class 'aaa'
t2(a)
# S4 method for class 'aaa'
t3(a)
# S4 method for class 'aaa'
tc(a)
single(a)
double(a)
triple(a)
```

## Arguments

- a:

  Object of class `aaa`

## Details

An `aaa` object is a list of 9 vectors, three numeric and six character,
which are extracted by functions `s1()` etc.

Functions `single()`, `double()` and `triple()` extract the single,
double, and triple components of their argument, and return the
corresponding `aaa` object.

There is no function `evitaicossa::coeffs()` because the three types of
elements are qualitatively different; use `sc()`, `dc()`, and `tc()` to
get the coefficients in `disord` format.

Functions `getthings()`, `extracter()` and `overwriter()` are
lower-level methods, not really intended for the end-user. Function
`getthings()` takes an `aaa` object and returns a named list with
elements being `disord` objects corresponding to components
`s1`,`sc`,`d1` etc. Function `extracter()` takes an `aaa` object and
arguments `s1`, `d1`,`d2`,`t1` etc. and returns the `aaa` object
corresponding to the specified index elements. Function `overwriter`
takes

Functions `single()`, `double()`, and `triple()` return the index-1,
index-2, and index-3 components of their arguments respectively.
Functions `single<-()` *et seq.* are the corresponding setting methods
which overwrite the index-1 (resp. 2,3) components with the right hand
side. The right hand side must be purely the correct component otherwise
an error is returned; thus in `double(a) <- x`, for example, the
single-symbol and triple-symbol components of `x` must be zero.

Square bracket extraction and replacement methods are more
user-friendly. These operate in two distinct modes. If given named
arguments (`s1`, `d1`,`d2`, *et seq.*) then these are interpreted as
symbols and coefficients of the different orders. If given an unnamed
argument, this is interpreted as a character vector of length one, two,
or three specifying a particular term in the object. But note that
list-based extraction, as in `a[list(s1=3)]`, the names to be given. See
examples.

## Value

Return disord or `aaa` objects

## Author

Robin K. S. Hankin

## Examples

``` r
x <- linear1(1:3) + (linear1(1:2) + linear2(1:3))^2
x
#> free antiassociative algebra element:
#> +1a +2b +3c +1a.a +2a.b +2b.a +4b.b +2(a.a)b -2(a.b)b -3(a.c)c -2(b.a)a
#> +2(b.b)a -6(b.c)c +3(c.c)a +6(c.c)b
x[d1=c("a","a"),d2=c("a","b")]
#> free antiassociative algebra element:
#> +1a.a +2a.b
x[s1="a", t1="b", t2="c", t3="c"]
#> free antiassociative algebra element:
#> +1a -6(b.c)c


x[s1="a", t1="b", t2="c", t3="c"] <- 88
x
#> free antiassociative algebra element:
#> +88a +2b +3c +1a.a +2a.b +2b.a +4b.b +2(a.a)b -2(a.b)b -3(a.c)c -2(b.a)a
#> +2(b.b)a +88(b.c)c +3(c.c)a +6(c.c)b
x[c("c","c","b")] <- -777
x
#> free antiassociative algebra element:
#> +88a +2b +3c +1a.a +2a.b +2b.a +4b.b +2(a.a)b -2(a.b)b -3(a.c)c -2(b.a)a
#> +2(b.b)a +88(b.c)c +3(c.c)a -777(c.c)b

x[list("c","c","b")]            # returns zero...
#> the zero free antiassociative algebra element.
x[list(t1="c", t2="c", t3="b")] # ...you probably meant this 
#> free antiassociative algebra element:
#> -777(c.c)b

a <- raaaa()
sc(a)
#> A disord object with hash bfccd2d2e8fa0773e6fda3a034b823c2629d74fb and elements
#>  [1]  2 31 10 16 33 19 20  2 13  6
#> (in some order)
t2(a)
#> A disord object with hash 58a673119a16074ec2509c8fa2c595708df2c923 and elements
#>  [1] "d" "h" "h" "c" "e" "h" "d" "e" "i" "j" "b" "b" "h" "j" "b" "f" "f" "b" "c"
#> [20] "e" "j" "a" "b" "c" "g" "i" "j" "a" "d" "f"
#> (in some order)
single(a)
#> free antiassociative algebra element:
#> +2a +31b +10c +16d +33e +19f +20g +2h +13i +6j

single(a) + double(a) + triple(a) == a  # should be TRUE
#> [1] TRUE

aaa(d1=d1(a),d2=d2(a), dc=dc(a)) == double(a)
#> [1] TRUE

x <- raaaa()
single(x) <- 0
double(x) <- double(raaa())
```
