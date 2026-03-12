# Jittering aaa objects

Jitters the components of an aaa object.

## Value

Returns an object of class `aaa`

## Author

Robin K. S. Hankin

## Examples

``` r
jitter(raaa())
#> free antiassociative algebra element:
#> +5.18453609114513b +1.82390237841755d +6.07727591674775c.b +4.18216349873692c.c
#> +2.19822741569951(a.c)b +1.99922210872173(a.d)b +0.892117907758802(c.b)c
jitter(raaa(), amount=1e-6)
#> free antiassociative algebra element:
#> +3.0000001767407a +5.99999998395707d +2.99999957155389a.a +5.99999901683919b.c
#> +1.00000010154859(a.b)b +4.00000062646182(a.b)d +3.00000028714917(c.b)d
```
