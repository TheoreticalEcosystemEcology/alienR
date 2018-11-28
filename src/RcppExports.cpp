// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// getNull
arma::mat getNull(arma::mat A);
RcppExport SEXP _alien_getNull(SEXP ASEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type A(ASEXP);
    rcpp_result_gen = Rcpp::wrap(getNull(A));
    return rcpp_result_gen;
END_RCPP
}
// getNullOne
arma::mat getNullOne(int nbsp);
RcppExport SEXP _alien_getNullOne(SEXP nbspSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbsp(nbspSEXP);
    rcpp_result_gen = Rcpp::wrap(getNullOne(nbsp));
    return rcpp_result_gen;
END_RCPP
}
// prodNorm
arma::vec prodNorm(int nbsp, arma::mat B, arma::vec V);
RcppExport SEXP _alien_prodNorm(SEXP nbspSEXP, SEXP BSEXP, SEXP VSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbsp(nbspSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type V(VSEXP);
    rcpp_result_gen = Rcpp::wrap(prodNorm(nbsp, B, V));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_alien_getNull", (DL_FUNC) &_alien_getNull, 1},
    {"_alien_getNullOne", (DL_FUNC) &_alien_getNullOne, 1},
    {"_alien_prodNorm", (DL_FUNC) &_alien_prodNorm, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_alien(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
