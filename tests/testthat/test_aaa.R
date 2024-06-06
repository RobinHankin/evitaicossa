## This file follows the structure of aaa.R in the free group package.

## Define some checker functions, and call them at the end.  They
## should all return TRUE if the package works, and stop with error if
## a test is failed.  Function checker1() has one argument, checker2()
## two, and so on.

test_that("Test suite aaa.R",{

checker1 <- function(x){

    expect_error(x <  x)
    expect_error(x >  x)
    expect_error(x <= x)
    expect_error(x >= x)

    expect_error(x == 0)
    expect_error(x == 3)
    expect_error(x/x)
    expect_error(x^x)
    expect_error(x^(-1))
  
    expect_error(x+1)
    expect_error(x-1)
    expect_error(1+x)
    expect_error(1-x)

    expect_true(x == x, info=x)
    expect_true(x == +x, info=x)
    expect_true(+x == x, info=x)
    expect_true(x == -(-x), info=x)
  
    expect_false( x != x, info=x)

    expect_true(x+x == 2*x, info=x)
    expect_true(x+x == x*2, info=x)
    expect_true(x+x-x == x, info=x)

    expect_true(is.zero(x-x), info=x)
    expect_true(is.zero(x*0), info=x)

    expect_true(x/2 + x/2 == x, info=x)
  
    expect_error(x^0, info=x)
    expect_true(x^1 == x, info=x)
    expect_true(x^2 == x*x, info=x)
    expect_error(x^3, info=x)
    expect_true(is.zero(x^4), info=x)
    expect_true(is.zero(x^5), info=x)
    expect_true(is.zero(x^6), info=x)

    expect_output(print(x))

    expect_true(is.zero(x*linear3(sample(9))))

    expect_true(as.aaa(getthings(x)) == x)

    expect_true(get_single(x) + get_double(x) + get_triple(x) == x)

    return(TRUE)
}  # checker1() closes


checker2 <- function(x,y){
  expect_true(x == -y+x+y, info=list(x,y))
  expect_true(x+y == x-(-y), info=list(x,y))

  expect_true(x+y == y+x, info=list(x,y))

  expect_true((-x)*y == -(x*y), info=list(x,y))
  expect_true(x*(-y) == -(x*y), info=list(x,y))

  return(TRUE)
}


checker3 <- function(x,y,z){
  expect_true(x+(y+z) == (x+y)+z, info=list(x,y,z)) # additive associativity

  expect_true(x*(y+z) == x*y + x*z, info=list(x,y,z))  # left distributivity
  expect_true((y+z)*x == y*x + z*x, info=list(x,y,z))  # right distributivity
  return(TRUE)
} # checker3() closes

checker4 <- function(x,y,z,p){
    expect_true(is.zero(x*y*z*p))
}


for(i in 1:2){
    x <- raaa()
    y <- raaa()
    z <- raaa()
    p <- raaa()
    
    checker1(x)
    checker2(x,y)
    checker3(x,y,z)
    checker4(x,y,z,p)

    checker1(raaaa())
}

checker1(aaa())
checker1(linear1(1:6))
checker1(linear2(1:6))
checker1(linear3(1:6))

})
