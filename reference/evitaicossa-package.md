# Antiassociative Algebra

Methods to deal with the free antiassociative algebra over the reals
with an arbitrary number of indeterminates. Antiassociativity means that
(xy)z = -x(yz). Antiassociative algebras are nilpotent with nilindex
four (Remm, 2022, \<doi:10.48550/arXiv.2202.10812\>) and this drives the
design and philosophy of the package. Methods are defined to create and
manipulate arbitrary elements of the antiassociative algebra, and to
extract and replace coefficients. A vignette is provided.

## Details

The DESCRIPTION file: This package was not yet installed at build
time.  
Index: This package was not yet installed at build time.  

Functionality to work with the free antiassociative algebra in R. The
hex sticker features an image taken from Hoffnung (1959) in which
musical concepts \[pizzicato, crescendo, etc\] are given whimsical
visual form. The character on the hex sticker is captioned “A Discord”:
Hoffnung's interpretation of the musical concept of dissonance. In the
book, the preceding image was a “*chord*”, evoking harmony. The discord,
on the other hand, embodies–for me at least–antiassociativity:
everything is wrong, wrong, wrong.

## Author

Robin K. S. Hankin \[aut, cre\] (ORCID:
\<https://orcid.org/0000-0001-5982-0415\>)

Maintainer: Robin K. S. Hankin \<hankin.robin@gmail.com\>

## References

Hoffnung G (1959). *Hoffnung's Acoustics*. Dobson.

## See also

[`aaa`](https://robinhankin.github.io/evitaicossa/reference/aaa.md)

## Examples

``` r
x <- raaa()
x
#> free antiassociative algebra element:
#> +5c +2d +4b.b +1c.c +4d.d +4(b.c)c +1(b.c)d +3(c.d)d
y <- raaa()

x+y
#> free antiassociative algebra element:
#> +2a +1b +6c +2d +2b.a +4b.b +1c.c +4d.a +7d.d +3(a.c)b +1(b.b)b +4(b.c)c
#> +1(b.c)d +2(c.d)c +3(c.d)d
x*y
#> free antiassociative algebra element:
#> +10c.a +5c.b +5c.c +4d.a +2d.b +2d.c +8(b.b)a +4(b.b)b +4(b.b)c -10(c.b)a
#> +2(c.c)a +1(c.c)b +1(c.c)c -20(c.d)a -15(c.d)d -4(d.b)a +4(d.d)b +4(d.d)c
#> -6(d.d)d
```
