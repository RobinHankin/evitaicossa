setClass("aaa",
         slots = c(
             single_indeterminate_name1 = "character",
             single_indeterminate_coeff = "numeric"  ,
             double_indeterminate_name1 = "character",
             double_indeterminate_name2 = "character",
             double_indeterminate_coeff = "numeric"  ,
             triple_indeterminate_name1 = "character",
             triple_indeterminate_name2 = "character",
             triple_indeterminate_name3 = "character",
             triple_indeterminate_coeff = "numeric"
         ),
         validity = function(object){
             l1 <- c(
                 length(object@single_indeterminate_name1),
                 length(object@single_indeterminate_coeff)
             )
             l2 <- c(
                 length(object@double_indeterminate_name1),
                 length(object@double_indeterminate_name2),
                 length(object@double_indeterminate_coeff)
             )
             l3 <- c(
                 length(object@triple_indeterminate_name1),
                 length(object@triple_indeterminate_name2),
                 length(object@triple_indeterminate_name3),
                 length(object@triple_indeterminate_coeff)
             )
             stopifnot(min(l1)==max(l1))
             stopifnot(min(l2)==max(l2))
             stopifnot(min(l3)==max(l3))
         }
         )

`aaa` <-
    function(
             s1 = character(0), # single_indeterminate_name1
             sc = numeric(0)  , # single_indeterminate_coeff
             d1 = character(0), # double_indeterminate_name1
             d2 = character(0), # double_indeterminate_name2
             dc = numeric(0)  , # double_indeterminate_coeff
             t1 = character(0), # triple_indeterminate_name1
             t2 = character(0), # triple_indeterminate_name2
             t3 = character(0), # triple_indeterminate_name3
             tc = numeric(0)    # triple_indeterminate_coeff
             ){
        return(
            lavter(
                aaa_identity(
                    single_indeterminate_name1 = s1,
                    single_indeterminate_coeff = sc,
                    double_indeterminate_name1 = d1,
                    double_indeterminate_name2 = d2,
                    double_indeterminate_coeff = dc,
                    triple_indeterminate_name1 = t1,
                    triple_indeterminate_name2 = t2,
                    triple_indeterminate_name3 = t3,
                    triple_indeterminate_coeff = tc
                )
            )
        )
    }

            
lavter <- function(cout){   # "lavter" is "retval" in reverse

    sn <- matrix(cout$names1,nrow=1)
    dn <- matrix(cout$names2,nrow=2)
    tn <- matrix(cout$names3,nrow=3)
    
    new("aaa", # the only time new() is called
        single_indeterminate_name1 = sn[1,],
        single_indeterminate_coeff = cout$coeffs1,
        double_indeterminate_name1 = dn[1,],
        double_indeterminate_name2 = dn[2,],
        double_indeterminate_coeff = cout$coeffs2,
        triple_indeterminate_name1 = tn[1,],
        triple_indeterminate_name2 = tn[2,],
        triple_indeterminate_name3 = tn[3,],
        triple_indeterminate_coeff = cout$coeffs3
        )
}

            
setGeneric("s1",function(a){standardGeneric("s1")})
setGeneric("sc",function(a){standardGeneric("sc")})
setGeneric("d1",function(a){standardGeneric("d1")})
setGeneric("d2",function(a){standardGeneric("d2")})
setGeneric("dc",function(a){standardGeneric("dc")})
setGeneric("t1",function(a){standardGeneric("t1")})
setGeneric("t2",function(a){standardGeneric("t2")})
setGeneric("t3",function(a){standardGeneric("t3")})
setGeneric("tc",function(a){standardGeneric("tc")})

setMethod("s1",signature(a="aaa"),function(a){a@single_indeterminate_name1})
setMethod("sc",signature(a="aaa"),function(a){a@single_indeterminate_coeff})
setMethod("d1",signature(a="aaa"),function(a){a@double_indeterminate_name1})
setMethod("d2",signature(a="aaa"),function(a){a@double_indeterminate_name2})
setMethod("dc",signature(a="aaa"),function(a){a@double_indeterminate_coeff})
setMethod("t1",signature(a="aaa"),function(a){a@triple_indeterminate_name1})
setMethod("t2",signature(a="aaa"),function(a){a@triple_indeterminate_name2})
setMethod("t3",signature(a="aaa"),function(a){a@triple_indeterminate_name3})
setMethod("tc",signature(a="aaa"),function(a){a@triple_indeterminate_coeff})
## accessor methods end

`aaa_single` <- function(v){aaa(s1 = v[1],                  sc = 1) }  # aaa_single("a") = a
`aaa_double` <- function(v){aaa(d1 = v[1], d2=v[2],         dc = 1) }  # aaa_double(c("a","b")) = a.b
`aaa_triple` <- function(v){aaa(t1 = v[1], t2=v[2],t3=v[3], tc = 1) }  # aaa_triple(c("a","b","c")) = a.(b.c)

"aaa_arith_aaa" <- function(e1,e2){
  switch(.Generic,
         "+" = aaa_plus_aaa(e1, e2),
         "-" = aaa_plus_aaa(e1,aaa_negative(e2)),
         "*" = aaa_prod_aaa(e1, e2),
         "/" = stop("aaa/aaa not defined"),
         "^" = stop("aaa^aaa not defined"),
         stop(gettextf("binary operator %s not defined for aaas", dQuote(.Generic)))
         )
}

"aaa_arith_numeric" <- function(e1,e2){  # e1 aaa, e2 numeric
  switch(.Generic,
         "+" = aaa_plus_numeric (e1, e2),
         "-" = aaa_plus_numeric (e1,-e2),
         "*" = aaa_prod_numeric (e1, e2),
         "/" = aaa_over_numeric (e1, e2),
         "^" = aaa_power_numeric(e1, e2),
         stop(gettextf("binary operator %s not defined for aaas", dQuote(.Generic)))
         )
}


"numeric_arith_aaa" <- function(e1,e2){ # e1 numeric, e2 aaa
  switch(.Generic,
         "+" = aaa_plus_numeric ( e2,e1),
         "-" = aaa_plus_numeric (-e2,e1),
         "*" = aaa_prod_numeric ( e1,e2),
         "/" = aaa_over_numeric ( e1,e2),
         "^" = aaa_power_numeric( e1,e2),
         stop(gettextf("binary operator %s not defined for aaas", dQuote(.Generic)))
         )
}

`aaa_negative` <- function(a){
    aaa(
        s1 =  s1(a),
        sc = -sc(a),
        d1 =  d1(a),
        d2 =  d2(a),
        dc = -dc(a),
        t1 =  t1(a),
        t2 =  t2(a),
        t3 =  t3(a),
        tc = -tc(a)
    )
}

`aaa_plus_aaa` <- function(a,b){
        return(
            lavter(
                c_aaa_add(  # cf aaa_prod_add() below
                    F1_single_indeterminate_name1 = s1(a),
                    F1_single_indeterminate_coeff = sc(a),
                    F1_double_indeterminate_name1 = d1(a),
                    F1_double_indeterminate_name2 = d2(a),
                    F1_double_indeterminate_coeff = dc(a),
                    F1_triple_indeterminate_name1 = t1(a),
                    F1_triple_indeterminate_name2 = t2(a),
                    F1_triple_indeterminate_name3 = t3(a),
                    F1_triple_indeterminate_coeff = tc(b),
                    F2_single_indeterminate_name1 = s1(b),
                    F2_single_indeterminate_coeff = sc(b),
                    F2_double_indeterminate_name1 = d1(b),
                    F2_double_indeterminate_name2 = d2(b),
                    F2_double_indeterminate_coeff = dc(b),
                    F2_triple_indeterminate_name1 = t1(b),
                    F2_triple_indeterminate_name2 = t2(b),
                    F2_triple_indeterminate_name3 = t3(b),
                    F2_triple_indeterminate_coeff = tc(b)
                )
            )
        )
}

`aaa_prod_aaa` <- function(a,b){
        return(
            lavter(
                c_aaa_prod(  # cf aaa_plus_aaa() above
                    F1_single_indeterminate_name1 = s1(a),
                    F1_single_indeterminate_coeff = sc(a),
                    F1_double_indeterminate_name1 = d1(a),
                    F1_double_indeterminate_name2 = d2(a),
                    F1_double_indeterminate_coeff = dc(a),
                    F1_triple_indeterminate_name1 = t1(a),
                    F1_triple_indeterminate_name2 = t2(a),
                    F1_triple_indeterminate_name3 = t3(a),
                    F1_triple_indeterminate_coeff = tc(b),
                    F2_single_indeterminate_name1 = s1(b),
                    F2_single_indeterminate_coeff = sc(b),
                    F2_double_indeterminate_name1 = d1(b),
                    F2_double_indeterminate_name2 = d2(b),
                    F2_double_indeterminate_coeff = dc(b),
                    F2_triple_indeterminate_name1 = t1(b),
                    F2_triple_indeterminate_name2 = t2(b),
                    F2_triple_indeterminate_name3 = t3(b),
                    F2_triple_indeterminate_coeff = tc(b)
                )
            )
        )
}

`aaa_prod_numeric`  <- function(a,b){
    aaa(
        s1 =  s1(a),
        sc =  sc(a)*b,
        d1 =  d1(a),
        d2 =  d2(a),
        dc =  dc(a)*b,
        t1 =  t1(a),
        t2 =  t2(a),
        t3 =  t3(a),
        tc =  tc(a)*b
    )
}

`aaa_plus_numeric`  <- function(a,b){
    stop("there are no scalars in antiassociative algebras")
}

setMethod("+", signature(e1 = "aaa", e2 = "missing"), function(e1,e2){e1              })
setMethod("-", signature(e1 = "aaa", e2 = "missing"), function(e1,e2){aaa_negative(e1)})

setMethod("Arith",signature(e1 = "aaa"  , e2="aaa"    ), aaa_arith_aaa     )
setMethod("Arith",signature(e1 = "aaa"  , e2="numeric"), aaa_arith_numeric )
setMethod("Arith",signature(e1 = "numeric", e2="aaa"  ), numeric_arith_aaa )
