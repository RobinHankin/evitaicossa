# Random elements of the free antiassociative algebra

Random elements of the free antiassociative algebra, intended as quick
“get you going” examples of `aaa` objects

## Usage

``` r
raaa(n = 4, s = 3)
raaaa(n = 10, s = 30)
```

## Arguments

- n:

  Number of terms to generate

- s:

  Number of symbols to use in the alphabet

## Details

Function `raaa()` returns a random `aaa` object. Function `raaaa()`
returns, by default, a more complicated `aaa` object.

## Value

Returns an object of class `aaa`

## Author

Robin K. S. Hankin

## Examples

``` r
raaa()
#> free antiassociative algebra element:
#> +1a +4b +1c +1b.b +1b.d +2d.b +2(a.a)d +3(c.a)b +1(d.c)b
raaaa()
#> free antiassociative algebra element:
#> +22a +6b +4c +7d +41e +32f +13g +2h +3i +44j +3a.b +9a.g +6b.a +10b.c +10b.j
#> +5c.a +9c.f +8c.j +3d.d +7d.i +14e.a +6e.h +1e.i +8f.h +2f.j +6g.b +10g.c +6g.d
#> +9g.h +4h.c +2h.d +10i.g +1i.h +6i.i +10j.b +4j.d +6j.f +1(a.a)e +2(a.c)i
#> +1(a.e)d +7(a.h)f +1(b.a)h +10(b.c)d +2(b.e)h +3(c.e)a +4(c.g)a +1(d.b)i
#> +7(d.g)h +4(e.a)h +4(e.c)d +10(e.d)i +2(f.c)i +1(f.i)d +10(f.j)c +7(f.j)j
#> +6(g.b)g +3(g.i)b +10(g.j)c +8(h.a)b +9(h.i)g +10(h.j)e +7(i.b)j +5(i.d)i
#> +4(i.g)i +8(j.i)c +4(j.j)a
```
