# All symbols in an aaa object

Function `allsymbols()` returns a character vector whose entries include
all symbols of its argument.

## Usage

``` r
allsymbols(a)
```

## Arguments

- a:

  Object of class `aaa`

## Value

Returns a character vector

## Author

Robin K. S. Hankin

## Examples

``` r
a <- raaaa()
a
#> free antiassociative algebra element:
#> +16a +5b +23c +14d +15e +16f +31g +18h +10i +29j +5a.b +7a.d +8a.e +6a.f +3b.c
#> +5b.e +16b.h +1b.j +6c.a +9c.e +6d.e +1d.i +5d.j +1e.i +3f.f +3f.h +7f.i +4g.a
#> +10g.d +2g.j +9h.c +5h.i +4h.j +4j.a +10j.c +3j.h +1j.i +8j.j +3(a.g)e +1(a.g)h
#> +10(b.b)j +3(b.d)h +4(b.h)f +9(c.d)d +4(c.e)g +6(c.i)e +5(d.a)a +8(e.b)b
#> +10(e.c)g +6(e.i)e +5(f.f)c +9(f.f)f +6(f.f)i +4(f.i)b +4(g.d)d +4(g.g)g
#> +4(g.h)e +9(h.d)b +3(h.f)a +10(h.f)g +6(h.g)d +9(h.j)e +8(h.j)g +9(i.d)c
#> +9(i.d)j +7(i.f)h +7(j.h)c +9(j.h)j
allsymbols(a)
#>  [1] "a" "b" "c" "d" "e" "f" "g" "h" "i" "j"

a[cbind(allsymbols(a))] == single(a)
#> [1] TRUE
```
