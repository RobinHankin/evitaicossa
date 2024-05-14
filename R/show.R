setMethod("show", "aaa", function(object){invisible(print(aaa_show(object)))})


aaa_show <- function(a){
    paste(
    single_string(a),
    double_string(a),
    triple_string(a),
    sep=" ")
}

single_string <- function(a){paste(paste(sc(a),s1(a),sep=""),collapse=" + ")}
double_string <- function(a){paste(paste(sc(a),d1(a),d2(a),sep=""),collapse=" + ")}
triple_string <- function(a){paste(paste(sc(a),"(",t1(a),t2(a),")",t3(a),sep=""),collapse=" + ")}
    

