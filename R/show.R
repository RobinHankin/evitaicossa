setMethod("show", "aaa", function(object){invisible(print(aaa_show(object)))})


aaa_show <- function(a){
    paste(
    single_string(a),
    double_string(a),
    triple_string(a),
    sep=" ")
}

single_string <- function(a){
    if(length(sc(a))>0){
        paste(paste(sc(a),s1(a),sep=""),collapse=" + ")
    } else {
        ""
    }
}

double_string <- function(a){
    if(length(dc(a))>0){
        paste(paste(sc(a),d1(a),d2(a),sep=""),collapse=" + ")
    } else {
        ""
    }
}

triple_string <- function(a){
    if(length(tc(a))>0){
        paste(paste(tc(a),"(",t1(a),t2(a),")",t3(a),sep=""),collapse=" + ")
    } else {
        ""
    }
}
