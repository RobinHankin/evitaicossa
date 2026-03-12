# Linear functions

Linear functions returning single, double, or triple-symbol `aaa`
objects.

## Usage

``` r
linear1(x)
linear2(x)
linear3(x)
```

## Arguments

- x:

  A numeric vector

## Details

These functions return an antiassociative algebra element with the
specified coefficients. Given a numeric vector `v` with elements
\\v_1,v_2,\ldots, v_n\\ then

`linear1(v)` returns \\v_1\mathbf{a} + v_2\mathbf{b}+\cdots+
v_n\mathbf{L_n}\\, where \\\mathbf{L_n}\\ is the \\n^\mathrm{th}\\
letter of the alphabet. Similarly, `linear2(v)` returns
\\v_1\mathbf{a}\mathbf{a}+\cdots+ v_n\mathbf{L_n}\mathbf{L_n}\\, and
`linear3(v)` returns \\v_1(\mathbf{a}\mathbf{a})\mathbf{a}+\cdots+
v_n(\mathbf{L_n}\mathbf{L_n})\mathbf{L_n}\\. They are linear in the
sense that

\$\$ f(\alpha\mathbf{x}+\beta\mathbf{y})= \alpha f(\mathbf{x})+\beta
f(\mathbf{y})\$\$

where \\\alpha,\beta\in\mathbb{R}\\ and
\\\mathbf{x},\mathbf{y}\in\mathbb{R}^n\\.

## Value

These functions return an object of class `aaa`.

## Author

Robin K. S. Hankin

## Examples

``` r
linear1(sample(8))
#> free antiassociative algebra element:
#> +7a +6b +5c +2d +3e +8f +1g +4h
linear2(sample(8))
#> free antiassociative algebra element:
#> +8a.a +3b.b +1c.c +6d.d +7e.e +2f.f +5g.g +4h.h
linear3(sample(8))
#> free antiassociative algebra element:
#> +2(a.a)a +4(b.b)b +3(c.c)c +6(d.d)d +7(e.e)e +5(f.f)f +1(g.g)g +8(h.h)h

a <- 3
b <- 7
x <- sample(9)
y <- sample(9)

linear1(a*x + b*y) == a*linear1(x) + b*linear1(y)
#> [1] TRUE
linear2(a*x + b*y) == a*linear2(x) + b*linear2(y)
#> [1] TRUE
linear3(a*x + b*y) == a*linear3(x) + b*linear3(y)
#> [1] TRUE
```
