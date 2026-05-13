# Functions to create objects of class `aaa`

Objects of class `aaa`

## Usage

``` r
aaa(s1 = character(0), sc = numeric(0), d1 = character(0), d2 =
character(0), dc = numeric(0), t1 = character(0), t2 = character(0), t3
= character(0), tc = numeric(0))
lavter(cout)
as.aaa(s)
thing_to_aaa(L)
```

## Arguments

- s1,d1,d2,t1,t2,t3:

  single, double, triple symbols

- sc,dc,tc:

  single, double, triple coefficients

- L:

  A list with elements `s1` etc

- cout:

  list

- s:

  Object that function `as.aaa()` will coerce to an `aaa` object

## Details

Function `lavter()` is the formal creation method for `aaa` objects; it
is the only place that `new()` is called. It takes a single argument
`cout`, which is a list as returned by C function `retval()`. However,
it is a little awkward and is not intended for day-to-day use. One
should use other functions for creation, which are more user-friendly
and have sensible defaults:

- Function `aaa()` takes named arguments `s1` etc, with defaults
  corresponding to “not present”

- Function `thing_to_aaa()` takes a list with names `s1` etc

- Function `as.aaa()` tries hard to coerce its argument to an `aaa`
  object

## Value

Return objects of class `aaa`

## Author

Robin K. S. Hankin

## Examples

``` r

aaa(s1 = "x", sc = 13)
#> free antiassociative algebra element:
#> +13x
aaa(d1 = "z", d2 = "w", dc = 14)
#> free antiassociative algebra element:
#> +14z.w
aaa(t1 = "x", t2 = "y", t3 = "z", tc = 15)
#> free antiassociative algebra element:
#> +15(x.y)z

aaa(
    s1 = c("a","d"),
    sc = c( 4 , 2 ),
    d1 = c("a", "a", "a", "b"),
    d2 = c("a", "b", "d", "a"),
    dc = c( 3 ,  4 ,  4 ,  3 ),
    t1 = c("a", "a", "a", "b", "b"),
    t2 = c("c", "d", "d", "c", "c"),
    t3 = c("a", "c", "d", "a", "b"),
    tc = c(-4 , -1 , -4 , 11 , 20 )
)
#> free antiassociative algebra element:
#> +4a +2d +3a.a +4a.b +4a.d +3b.a -4(a.c)a -1(a.d)c -4(a.d)d +11(b.c)a +20(b.c)b


aaa() # the zero object
#> the zero free antiassociative algebra element.

aaa(s1=letters,sc=seq_along(letters))
#> free antiassociative algebra element:
#> +1a +2b +3c +4d +5e +6f +7g +8h +9i +10j +11k +12l +13m +14n +15o +16p +17q
#> +18r +19s +20t +21u +22v +23w +24x +25y +26z
aaa(d1=state.abb,d2=rev(state.abb),dc=seq_along(state.abb))
#> free antiassociative algebra element:
#> +2AK.WI +1AL.WY +4AR.WA +3AZ.WV +5CA.VA +6CO.VT +7CT.UT +8DE.TX +9FL.TN
#> +10GA.SD +11HI.SC +15IA.OK +12ID.RI +13IL.PA +14IN.OR +16KS.OH +17KY.ND
#> +18LA.NC +21MA.NJ +20MD.NM +19ME.NY +22MI.NH +23MN.NV +25MO.MT +24MS.NE
#> +26MT.MO +33NC.LA +34ND.KY +27NE.MS +29NH.MI +30NJ.MA +31NM.MD +28NV.MN
#> +32NY.ME +35OH.KS +36OK.IA +37OR.IN +38PA.IL +39RI.ID +40SC.HI +41SD.GA
#> +42TN.FL +43TX.DE +44UT.CT +46VA.CA +45VT.CO +47WA.AR +49WI.AK +48WV.AZ
#> +50WY.AL

as.aaa(state.abb)
#> free antiassociative algebra element:
#> +1AK +1AL +1AR +1AZ +1CA +1CO +1CT +1DE +1FL +1GA +1HI +1IA +1ID +1IL +1IN +1KS
#> +1KY +1LA +1MA +1MD +1ME +1MI +1MN +1MO +1MS +1MT +1NC +1ND +1NE +1NH +1NJ +1NM
#> +1NV +1NY +1OH +1OK +1OR +1PA +1RI +1SC +1SD +1TN +1TX +1UT +1VA +1VT +1WA +1WI
#> +1WV +1WY


evita <- aaa(s1=letters[1:5],sc=1:5)
icossa <- aaa(d1=c("fish","chips"),d2=c("x","y"),dc=c(6,7))

evita
#> free antiassociative algebra element:
#> +1a +2b +3c +4d +5e
evita + icossa
#> free antiassociative algebra element:
#> +1a +2b +3c +4d +5e +7chips.y +6fish.x
evita * icossa
#> free antiassociative algebra element:
#> -7(a.chips)y -6(a.fish)x -14(b.chips)y -12(b.fish)x -21(c.chips)y -18(c.fish)x
#> -28(d.chips)y -24(d.fish)x -35(e.chips)y -30(e.fish)x
evita^2
#> free antiassociative algebra element:
#> +1a.a +2a.b +3a.c +4a.d +5a.e +2b.a +4b.b +6b.c +8b.d +10b.e +3c.a +6c.b +9c.c
#> +12c.d +15c.e +4d.a +8d.b +12d.c +16d.d +20d.e +5e.a +10e.b +15e.c +20e.d
#> +25e.e

f <- function(o){aaa(state.abb[o],seq_along(o))}
f(8:9) - (f(1:2) - f(6:8)^2)^2
#> free antiassociative algebra element:
#> +1DE +2FL -4AK.AK -2AK.AL -2AL.AK -1AL.AL -2(AK.CO)CO -4(AK.CO)CT -6(AK.CO)DE
#> -4(AK.CT)CO -8(AK.CT)CT -12(AK.CT)DE -6(AK.DE)CO -12(AK.DE)CT -18(AK.DE)DE
#> -1(AL.CO)CO -2(AL.CO)CT -3(AL.CO)DE -2(AL.CT)CO -4(AL.CT)CT -6(AL.CT)DE
#> -3(AL.DE)CO -6(AL.DE)CT -9(AL.DE)DE +2(CO.CO)AK +1(CO.CO)AL +4(CO.CT)AK
#> +2(CO.CT)AL +6(CO.DE)AK +3(CO.DE)AL +4(CT.CO)AK +2(CT.CO)AL +8(CT.CT)AK
#> +4(CT.CT)AL +12(CT.DE)AK +6(CT.DE)AL +6(DE.CO)AK +3(DE.CO)AL +12(DE.CT)AK
#> +6(DE.CT)AL +18(DE.DE)AK +9(DE.DE)AL
```
