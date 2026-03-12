# Arithmetic methods for `aaa` objects

Arithmetic methods for objects of class `aaa`.

## Methods

- `signature(e1 = "aaa", e2 = "aaa")`:

  Dispatches to `aaa_arith_aaa()`

- `signature(e1 = "aaa", e2 = "numeric")`:

  Dispatches to `aaa_arith_numeric()`

- `signature(e1 = "numeric", e2 = "aaa")`:

  Dispatches to `numeric_arith_aaa()`

The S4 methods call lower-level functions `aaa_plus_aaa()`,
`aaa_prod_aaa()`, `aaa_prod_numeric()`, `aaa_negative()`, and
`aaa_plus_numeric()`.

These functions call the Rcpp functions
[`aaa_identity()`](https://robinhankin.github.io/evitaicossa/reference/aaa.md),
`c_aaa_add()`, and `c_aaa_prod()`.
