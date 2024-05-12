#setMethod("show", "aaa", function(object){invisible(print(aaa_show(object)))})


aaa_show <- function(a){
    paste(
    single_string(a),
    double_string(a),
    triple_string(a),
    sep=" ")
}

single_string <- function(a){
    s1(a)
    sc(a)
}
    
