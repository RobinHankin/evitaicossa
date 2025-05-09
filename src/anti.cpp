#include "anti.h"

const a1 empty_single;
const a2 empty_double;
const a3 empty_triple;




/*
assert(empty_single.empty());
assert(empty_double.empty());
assert(empty_triple.empty());


*/


template <typename T>
Rcpp::NumericVector coeffs(const T& A) {
  Rcpp::NumericVector out(A.size());
  std::transform(A.begin(), A.end(), out.begin(),
                 [](const auto& pair) { return pair.second; });
  return out;
}

Rcpp::CharacterVector names_single(const a1 &F){
  CharacterVector out(1*F.size());      /* different */
  size_t i=0;
  for (const auto& [symbol, _] : F) {
    out[i++] = symbol.e1;
  }
  return out;
}

Rcpp::CharacterVector names_double(const a2 &F){
  CharacterVector out(2*F.size());     /* different */
  size_t i=0;
  for (const auto& [symbol, _] : F) {
    out[i++] = symbol.e1;
    out[i++] = symbol.e2;
  }
  return out;
}

Rcpp::CharacterVector names_triple(const a3 &F){
  CharacterVector out(3*F.size());     /* different */
  size_t i=0;
  for (const auto& [symbol, _] : F) {
    out[i++] = symbol.e1;
    out[i++] = symbol.e2;
    out[i++] = symbol.e3;
  }
  return out;
}

template <typename AssocContainer>
AssocContainer nonzero(const AssocContainer& F) {
  AssocContainer out;
  for (const auto& [symbol, coefficient] : F) {
    if (coefficient != 0) {
      out[symbol] = coefficient;
    }
  }
  return out;
}

a1 sum1(a1 F1, a1 F2){
  if(F1.size() > F2.size()){
    for(const auto& [key, value] : F2){ // iterate through F2 as it is the smaller one
      F1[key] += value;
    }
    return nonzero(F1);
  } else { 
    for(const auto& [key, value] : F1){  // iterate through F1 as it is the smaller one
      F2[key] += value;
    }
    return nonzero(F2);
  }
}

a2 sum2(a2 F1, a2 F2){
  if(F1.size() > F2.size()){
    for(const auto& [key, value] : F2){ // iterate through F2 as it is the smaller one
      F1[key] += value;
    }
    return nonzero(F1);
  } else {
    for(const auto& [key, value] : F1){  // iterate through F1 as it is the smaller one
      F2[key] += value;
    }
    return nonzero(F2);
  }
}

a3 sum3(a3 F1, a3 F2){
  if(F1.size() > F2.size()){
    for(const auto& [key, value] : F2){ // iterate through F2 as it is the smaller one
      F1[key] += value;
    }
    return nonzero(F1);
  } else { 
    for(const auto& [key, value] : F1){  // iterate through F1 as it is the smaller one
      F2[key] += value;
    }
    return nonzero(F2);
  }
}


a2 prod_a1_a1(const a1 &F1, const a1 &F2){
  a2 out;
  for (const auto& [key1, value1] : F1){
    for (const auto& [key2, value2] : F2){
      double_symbol ds{ key1.e1, key2.e1 };
      out[ds] += value1 * value2;
    }
  }
  return out;
}

a3 prod_a2_a1(const a2 &F2, const a1 &F1){
  a3 out;
  for (const auto& [ab, value2] : F2){  // ab is a double_symbol
    for (const auto& [c, value1] : F1){ // c  is a single_symbol
      const triple_symbol jj{ ab.e1, ab.e2, c.e1 };
      out[jj] += value1 * value2;  // The meat
    }
  }
  return out;
}

a3 prod_a1_a2(const a1 &F1, const a2 &F2){
  a3 out;
  for (const auto& [a, value1] : F1){    // a  is a single_symbol
    for (const auto& [bc, value2] : F2){ // bc is a double_symbol
      const triple_symbol jj{ a.e1, bc.e1, bc.e2 };
      out[jj] +=  (K) * value1 * value2;  // K = -1 by default: this is the meat of the whole package
    }
  }
  return out;
}

a1 extract1(a1 F,
	    const CharacterVector names1){
  a1 out;
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    single_symbol a;
    a.e1 = names1[i];
    out[a] += F[a];  // the meat
  }
  return nonzero(out);
}

a2 extract2(a2 F,
	    const CharacterVector names1,
	    const CharacterVector names2){
  a2 out;
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    double_symbol ab;
    ab.e1 = names1[i];
    ab.e2 = names2[i];
    out[ab] += F[ab];  // the meat
  }
  return nonzero(out);
}

a3 extract3(a3 F,
	    const CharacterVector names1,
	    const CharacterVector names2,
	    const CharacterVector names3){
  a3 out;
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    triple_symbol abc;
    abc.e1 = names1[i];
    abc.e2 = names2[i];
    abc.e3 = names3[i];
    out[abc] += F[abc];  // the meat
  }
  return nonzero(out);
}

a1 overwrite1(a1 F,
	      const CharacterVector names1,
	      const NumericVector value){
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    single_symbol a;
    a.e1 = names1[i];
    F[a] = value[0];  // the meat
  }
  return nonzero(F);
}

a2 overwrite2(a2 F,
	      const CharacterVector names1,
	      const CharacterVector names2,
	      const NumericVector value){
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    double_symbol ab;
    ab.e1 = names1[i];
    ab.e2 = names2[i];
    F[ab] = value[0];  // the meat
  }
  return nonzero(F);
}

a3 overwrite3(a3 F,
	      const CharacterVector names1,
	      const CharacterVector names2,
	      const CharacterVector names3,
	      const NumericVector value){
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    triple_symbol abc;
    abc.e1 = names1[i];
    abc.e2 = names2[i];
    abc.e3 = names3[i];
    F[abc] = value[0];  // the meat
  }
  return nonzero(F);
}




aaa sum_anti(const aaa &F1, const aaa &F2){
  aaa out;

  out.single_indeterminate = sum1(F1.single_indeterminate,F2.single_indeterminate);
  out.double_indeterminate = sum2(F1.double_indeterminate,F2.double_indeterminate);
  out.triple_indeterminate = sum3(F1.triple_indeterminate,F2.triple_indeterminate);
  return out;
}

aaa prod_anti(const aaa &F1, const aaa &F2){
  aaa out;
  const a1 F1_single = F1.single_indeterminate;
  const a1 F2_single = F2.single_indeterminate;

  const a2 F1_double = F1.double_indeterminate;
  const a2 F2_double = F2.double_indeterminate;

  a1 zero;
  out.single_indeterminate = zero;
  out.double_indeterminate = prod_a1_a1(F1_single,F2_single);
  out.triple_indeterminate = sum3(prod_a1_a2(F1_single,F2_double), prod_a2_a1(F1_double,F2_single));
  return out;
}

a1 a1maker(
	   const CharacterVector names1,
	   const NumericVector coeffs){
  if(
     names1.size() != coeffs.size()
     ){
    throw std::invalid_argument("a1maker(): names and coeffs are not same length");
  }
  a1 out;
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    single_symbol a;
    a.e1 = names1[i];
    if(coeffs[i] != 0){
      out[a] += coeffs[i];  // the meat
    }
  }
  return nonzero(out);  // nonzero() needed here if, eg, c(a=1,b=3,a=-1)
}

a2 a2maker(
	   const CharacterVector names1,
	   const CharacterVector names2,
	   const NumericVector coeffs){
  if(
     (names1.size() != coeffs.size()) ||
     (names2.size() != coeffs.size())
     ){
    throw std::invalid_argument("a2maker(): names and coeffs are not same length");
  }
  a2 out;
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    double_symbol ab;
    ab.e1 = names1[i];
    ab.e2 = names2[i];
    if(coeffs[i] != 0){
      out[ab] += coeffs[i];  // the meat
    }
  }
  return nonzero(out);  // nonzero() needed here if, eg, c(a=1,b=3,a=-1)
}

a3 a3maker(
	   const CharacterVector names1,
	   const CharacterVector names2,
	   const CharacterVector names3,
	   const NumericVector coeffs){
  if(
     (names1.size() != coeffs.size()) ||
     (names2.size() != coeffs.size()) ||
     (names3.size() != coeffs.size())
     ){
    throw std::invalid_argument("a3maker(): names and coeffs are not same length");
  }
  a3 out;
  for(size_t i=0 ; i < (size_t) names1.size() ; i++){
    triple_symbol abc;
    abc.e1 = names1[i];
    abc.e2 = names2[i];
    abc.e3 = names3[i];
    if(coeffs[i] != 0){
      out[abc] += coeffs[i];  // the meat
    }
  }
  return nonzero(out);  // nonzero() needed here if, eg, c(a=1,b=3,a=-1)
}

aaa aaamaker(
	     const CharacterVector single_indeterminate_name1,
	     const NumericVector   single_indeterminate_coeff,
	     const CharacterVector double_indeterminate_name1,
	     const CharacterVector double_indeterminate_name2,
	     const NumericVector   double_indeterminate_coeff,
	     const CharacterVector triple_indeterminate_name1,
	     const CharacterVector triple_indeterminate_name2,
	     const CharacterVector triple_indeterminate_name3,
	     const NumericVector   triple_indeterminate_coeff
	     ){
  
  aaa out;
  out.single_indeterminate = a1maker(single_indeterminate_name1,                                                      single_indeterminate_coeff);
  out.double_indeterminate = a2maker(double_indeterminate_name1,double_indeterminate_name2,                           double_indeterminate_coeff);
  out.triple_indeterminate = a3maker(triple_indeterminate_name1,triple_indeterminate_name2,triple_indeterminate_name3,triple_indeterminate_coeff);
  return out;
}

aaa extract(
	    const aaa &F, 
	    const CharacterVector single_indeterminate_name1,
	    const CharacterVector double_indeterminate_name1,
	    const CharacterVector double_indeterminate_name2,
	    const CharacterVector triple_indeterminate_name1,
	    const CharacterVector triple_indeterminate_name2,
	    const CharacterVector triple_indeterminate_name3){
  aaa out;
  out.single_indeterminate = extract1(F.single_indeterminate, single_indeterminate_name1                                                        );
  out.double_indeterminate = extract2(F.double_indeterminate, double_indeterminate_name1, double_indeterminate_name2                            );
  out.triple_indeterminate = extract3(F.triple_indeterminate, triple_indeterminate_name1, triple_indeterminate_name2, triple_indeterminate_name3);
  return out;
}

aaa overwrite(
	    const aaa &F, 
	    const CharacterVector single_indeterminate_name1,
	    const NumericVector   single_indeterminate_coeff,
	    const CharacterVector double_indeterminate_name1,
	    const CharacterVector double_indeterminate_name2,
	    const NumericVector   double_indeterminate_coeff,
	    const CharacterVector triple_indeterminate_name1,
	    const CharacterVector triple_indeterminate_name2,
	    const CharacterVector triple_indeterminate_name3,
	    const NumericVector   triple_indeterminate_coeff,
	    const NumericVector value){
  aaa out;
  out.single_indeterminate = overwrite1(F.single_indeterminate, single_indeterminate_name1,                                                        value);
  out.double_indeterminate = overwrite2(F.double_indeterminate, double_indeterminate_name1, double_indeterminate_name2,                            value);
  out.triple_indeterminate = overwrite3(F.triple_indeterminate, triple_indeterminate_name1, triple_indeterminate_name2, triple_indeterminate_name3,value);
  return out;
}

List retval(const aaa &F){  // Returns an 'aaa' object to R
  return List::create(
		      Named("names1")  = names_single(F.single_indeterminate),
		      Named("names2")  = names_double(F.double_indeterminate),
		      Named("names3")  = names_triple(F.triple_indeterminate),
		      Named("coeffs1") = coeffs(F.single_indeterminate),
		      Named("coeffs2") = coeffs(F.double_indeterminate),
		      Named("coeffs3") = coeffs(F.triple_indeterminate)
		      );
}

bool equal1(a1 &F1, a1 &F2){
  if(F1.size() != F2.size()){
    return false;
  }
  for (const auto& [symbol, value] : F1) {
    if (F2[symbol] != value) {
      return false;
    }
  }
  return true;
}

template <typename T>
bool equal_generic(const T& F1, const T& F2) {
  if (F1.size() != F2.size()) {
    return false;
  }
  for (const auto& [symbol, value] : F1) {
    if (F2.at(symbol) != value) {
      return false;
    }
  }
  return true;
}

bool equal(aaa F1, aaa F2){
  return
    equal_generic(F1.single_indeterminate,F2.single_indeterminate) &&
    equal_generic(F1.double_indeterminate,F2.double_indeterminate) &&
    equal_generic(F1.triple_indeterminate,F2.triple_indeterminate);
}

// [[Rcpp::export]]
List aaa_identity(
		  const CharacterVector single_indeterminate_name1,
		  const NumericVector   single_indeterminate_coeff,
		  const CharacterVector double_indeterminate_name1,
		  const CharacterVector double_indeterminate_name2,
		  const NumericVector   double_indeterminate_coeff,
		  const CharacterVector triple_indeterminate_name1,
		  const CharacterVector triple_indeterminate_name2,
		  const CharacterVector triple_indeterminate_name3,
		  const NumericVector   triple_indeterminate_coeff
		  ){
  return retval(aaamaker(  // the meat
			 single_indeterminate_name1,
			 single_indeterminate_coeff,
			 double_indeterminate_name1,
			 double_indeterminate_name2,
			 double_indeterminate_coeff,
			 triple_indeterminate_name1,
			 triple_indeterminate_name2,
			 triple_indeterminate_name3,
			 triple_indeterminate_coeff));
}

//[[Rcpp::export]]
List c_aaa_add(
		  const CharacterVector F1_single_indeterminate_name1,
		  const NumericVector   F1_single_indeterminate_coeff,
		  const CharacterVector F1_double_indeterminate_name1,
		  const CharacterVector F1_double_indeterminate_name2,
		  const NumericVector   F1_double_indeterminate_coeff,
		  const CharacterVector F1_triple_indeterminate_name1,
		  const CharacterVector F1_triple_indeterminate_name2,
		  const CharacterVector F1_triple_indeterminate_name3,
		  const NumericVector   F1_triple_indeterminate_coeff,

		  const CharacterVector F2_single_indeterminate_name1,
		  const NumericVector   F2_single_indeterminate_coeff,
		  const CharacterVector F2_double_indeterminate_name1,
		  const CharacterVector F2_double_indeterminate_name2,
		  const NumericVector   F2_double_indeterminate_coeff,
		  const CharacterVector F2_triple_indeterminate_name1,
		  const CharacterVector F2_triple_indeterminate_name2,
		  const CharacterVector F2_triple_indeterminate_name3,
		  const NumericVector   F2_triple_indeterminate_coeff
	       ){
  return retval(sum_anti( // the meat
			 aaamaker(
				  F1_single_indeterminate_name1,
				  F1_single_indeterminate_coeff,
				  F1_double_indeterminate_name1,
				  F1_double_indeterminate_name2,
				  F1_double_indeterminate_coeff,
				  F1_triple_indeterminate_name1,
				  F1_triple_indeterminate_name2,
				  F1_triple_indeterminate_name3,
				  F1_triple_indeterminate_coeff
				  ),
			 aaamaker(
				  F2_single_indeterminate_name1,
				  F2_single_indeterminate_coeff,
				  F2_double_indeterminate_name1,
				  F2_double_indeterminate_name2,
				  F2_double_indeterminate_coeff,
				  F2_triple_indeterminate_name1,
				  F2_triple_indeterminate_name2,
				  F2_triple_indeterminate_name3,
				  F2_triple_indeterminate_coeff
				  )
			 
			 ));
}

//[[Rcpp::export]]
List c_aaa_prod(
		  const CharacterVector F1_single_indeterminate_name1,
		  const NumericVector   F1_single_indeterminate_coeff,
		  const CharacterVector F1_double_indeterminate_name1,
		  const CharacterVector F1_double_indeterminate_name2,
		  const NumericVector   F1_double_indeterminate_coeff,
		  const CharacterVector F1_triple_indeterminate_name1,
		  const CharacterVector F1_triple_indeterminate_name2,
		  const CharacterVector F1_triple_indeterminate_name3,
		  const NumericVector   F1_triple_indeterminate_coeff,

		  const CharacterVector F2_single_indeterminate_name1,
		  const NumericVector   F2_single_indeterminate_coeff,
		  const CharacterVector F2_double_indeterminate_name1,
		  const CharacterVector F2_double_indeterminate_name2,
		  const NumericVector   F2_double_indeterminate_coeff,
		  const CharacterVector F2_triple_indeterminate_name1,
		  const CharacterVector F2_triple_indeterminate_name2,
		  const CharacterVector F2_triple_indeterminate_name3,
		  const NumericVector   F2_triple_indeterminate_coeff
	       ){
  return retval(prod_anti( // the meat
			 aaamaker(
				  F1_single_indeterminate_name1,
				  F1_single_indeterminate_coeff,
				  F1_double_indeterminate_name1,
				  F1_double_indeterminate_name2,
				  F1_double_indeterminate_coeff,
				  F1_triple_indeterminate_name1,
				  F1_triple_indeterminate_name2,
				  F1_triple_indeterminate_name3,
				  F1_triple_indeterminate_coeff
				  ),
			 aaamaker(
				  F2_single_indeterminate_name1,
				  F2_single_indeterminate_coeff,
				  F2_double_indeterminate_name1,
				  F2_double_indeterminate_name2,
				  F2_double_indeterminate_coeff,
				  F2_triple_indeterminate_name1,
				  F2_triple_indeterminate_name2,
				  F2_triple_indeterminate_name3,
				  F2_triple_indeterminate_coeff
				  )
			 
			 ));
}

//[[Rcpp::export]]
bool c_aaa_equal(
		  const CharacterVector F1_single_indeterminate_name1,
		  const NumericVector   F1_single_indeterminate_coeff,
		  const CharacterVector F1_double_indeterminate_name1,
		  const CharacterVector F1_double_indeterminate_name2,
		  const NumericVector   F1_double_indeterminate_coeff,
		  const CharacterVector F1_triple_indeterminate_name1,
		  const CharacterVector F1_triple_indeterminate_name2,
		  const CharacterVector F1_triple_indeterminate_name3,
		  const NumericVector   F1_triple_indeterminate_coeff,

		  const CharacterVector F2_single_indeterminate_name1,
		  const NumericVector   F2_single_indeterminate_coeff,
		  const CharacterVector F2_double_indeterminate_name1,
		  const CharacterVector F2_double_indeterminate_name2,
		  const NumericVector   F2_double_indeterminate_coeff,
		  const CharacterVector F2_triple_indeterminate_name1,
		  const CharacterVector F2_triple_indeterminate_name2,
		  const CharacterVector F2_triple_indeterminate_name3,
		  const NumericVector   F2_triple_indeterminate_coeff
	       ){
  return equal(
	       aaamaker(
			F1_single_indeterminate_name1,
			F1_single_indeterminate_coeff,
			F1_double_indeterminate_name1,
			F1_double_indeterminate_name2,
			F1_double_indeterminate_coeff,
			F1_triple_indeterminate_name1,
			F1_triple_indeterminate_name2,
			F1_triple_indeterminate_name3,
			F1_triple_indeterminate_coeff
			),
	       aaamaker(
			F2_single_indeterminate_name1,
			F2_single_indeterminate_coeff,
			F2_double_indeterminate_name1,
			F2_double_indeterminate_name2,
			F2_double_indeterminate_coeff,
			F2_triple_indeterminate_name1,
			F2_triple_indeterminate_name2,
			F2_triple_indeterminate_name3,
			F2_triple_indeterminate_coeff
			)
	       
	       );
}

//[[Rcpp::export]]
List c_aaa_extract(
		  const CharacterVector F1_single_indeterminate_name1,
		  const NumericVector   F1_single_indeterminate_coeff,
		  const CharacterVector F1_double_indeterminate_name1,
		  const CharacterVector F1_double_indeterminate_name2,
		  const NumericVector   F1_double_indeterminate_coeff,
		  const CharacterVector F1_triple_indeterminate_name1,
		  const CharacterVector F1_triple_indeterminate_name2,
		  const CharacterVector F1_triple_indeterminate_name3,
		  const NumericVector   F1_triple_indeterminate_coeff,
		  const CharacterVector s1,
		  const CharacterVector d1,
		  const CharacterVector d2,
		  const CharacterVector t1,
		  const CharacterVector t2,
		  const CharacterVector t3){
  return retval(extract( // the meat
			 aaamaker(
				  F1_single_indeterminate_name1,
				  F1_single_indeterminate_coeff,
				  F1_double_indeterminate_name1,
				  F1_double_indeterminate_name2,
				  F1_double_indeterminate_coeff,
				  F1_triple_indeterminate_name1,
				  F1_triple_indeterminate_name2,
				  F1_triple_indeterminate_name3,
				  F1_triple_indeterminate_coeff),
			 s1,d1,d2,t1,t2,t3));
}
//[[Rcpp::export]]
List c_aaa_overwriter(
		  const CharacterVector F1_single_indeterminate_name1,
		  const NumericVector   F1_single_indeterminate_coeff,
		  const CharacterVector F1_double_indeterminate_name1,
		  const CharacterVector F1_double_indeterminate_name2,
		  const NumericVector   F1_double_indeterminate_coeff,
		  const CharacterVector F1_triple_indeterminate_name1,
		  const CharacterVector F1_triple_indeterminate_name2,
		  const CharacterVector F1_triple_indeterminate_name3,
		  const NumericVector   F1_triple_indeterminate_coeff,
		  const CharacterVector s1,
		  const NumericVector   sc,
		  const CharacterVector d1,
		  const CharacterVector d2,
		  const NumericVector   dc,
		  const CharacterVector t1,
		  const CharacterVector t2,
		  const CharacterVector t3,
		  const NumericVector   tc,
		  const NumericVector   value){
  return retval(overwrite( // the meat
			 aaamaker(
				  F1_single_indeterminate_name1,
				  F1_single_indeterminate_coeff,
				  F1_double_indeterminate_name1,
				  F1_double_indeterminate_name2,
				  F1_double_indeterminate_coeff,
				  F1_triple_indeterminate_name1,
				  F1_triple_indeterminate_name2,
				  F1_triple_indeterminate_name3,
				  F1_triple_indeterminate_coeff),
			 s1,      sc,
			 d1,d2,   dc,
			 t1,t2,t3,tc,
			 value));
}
