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
// interaction_proba
double interaction_proba(NumericVector M1_i, NumericVector M2_j, double cent1_i, double cent2_j, NumericVector Lambda, double m);
RcppExport SEXP _alien_interaction_proba(SEXP M1_iSEXP, SEXP M2_jSEXP, SEXP cent1_iSEXP, SEXP cent2_jSEXP, SEXP LambdaSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type M1_i(M1_iSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type M2_j(M2_jSEXP);
    Rcpp::traits::input_parameter< double >::type cent1_i(cent1_iSEXP);
    Rcpp::traits::input_parameter< double >::type cent2_j(cent2_jSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< double >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(interaction_proba(M1_i, M2_j, cent1_i, cent2_j, Lambda, m));
    return rcpp_result_gen;
END_RCPP
}
// likelihoodMC_core
double likelihoodMC_core(NumericMatrix netObs, NumericMatrix M1, NumericMatrix M2, NumericVector cent1, NumericVector cent2, NumericVector Lambda, double m);
RcppExport SEXP _alien_likelihoodMC_core(SEXP netObsSEXP, SEXP M1SEXP, SEXP M2SEXP, SEXP cent1SEXP, SEXP cent2SEXP, SEXP LambdaSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type netObs(netObsSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type M1(M1SEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type M2(M2SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type cent1(cent1SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type cent2(cent2SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< double >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(likelihoodMC_core(netObs, M1, M2, cent1, cent2, Lambda, m));
    return rcpp_result_gen;
END_RCPP
}
// webFromNicheModel
LogicalMatrix webFromNicheModel(int nbsp, double connec, bool connect_all, bool unbias, Nullable<NumericVector> niche);
RcppExport SEXP _alien_webFromNicheModel(SEXP nbspSEXP, SEXP connecSEXP, SEXP connect_allSEXP, SEXP unbiasSEXP, SEXP nicheSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbsp(nbspSEXP);
    Rcpp::traits::input_parameter< double >::type connec(connecSEXP);
    Rcpp::traits::input_parameter< bool >::type connect_all(connect_allSEXP);
    Rcpp::traits::input_parameter< bool >::type unbias(unbiasSEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type niche(nicheSEXP);
    rcpp_result_gen = Rcpp::wrap(webFromNicheModel(nbsp, connec, connect_all, unbias, niche));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_alien_getNull", (DL_FUNC) &_alien_getNull, 1},
    {"_alien_getNullOne", (DL_FUNC) &_alien_getNullOne, 1},
    {"_alien_prodNorm", (DL_FUNC) &_alien_prodNorm, 3},
    {"_alien_interaction_proba", (DL_FUNC) &_alien_interaction_proba, 6},
    {"_alien_likelihoodMC_core", (DL_FUNC) &_alien_likelihoodMC_core, 7},
    {"_alien_webFromNicheModel", (DL_FUNC) &_alien_webFromNicheModel, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_alien(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
