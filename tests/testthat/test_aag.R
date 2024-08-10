## Specific tests for equality

test_that("Test suite aag.R",{  

    abc <- letters[1:3]
    expect_false(aaa(s1=abc,                 sc=1:3) == aaa(s1=abc,                 sc=c(1,3,3)))
    expect_false(aaa(d1=abc, d2=abc,         dc=1:3) == aaa(d1=abc, d2=abc,         dc=c(1,3,3)))
    expect_false(aaa(t1=abc, t2=abc, t3=abc, tc=1:3) == aaa(t1=abc, t2=abc, t3=abc, tc=c(1,3,3)))

    } )


    
