// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// traitsBasedJointCooc
NumericMatrix traitsBasedJointCooc(NumericVector env, NumericMatrix metaweb, double alpha, NumericVector trait1, Nullable<NumericVector> trait2, Nullable<NumericVector> trait3);
RcppExport SEXP alienR_traitsBasedJointCooc(SEXP envSEXP, SEXP metawebSEXP, SEXP alphaSEXP, SEXP trait1SEXP, SEXP trait2SEXP, SEXP trait3SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type env(envSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type metaweb(metawebSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type trait1(trait1SEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type trait2(trait2SEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type trait3(trait3SEXP);
    rcpp_result_gen = Rcpp::wrap(traitsBasedJointCooc(env, metaweb, alpha, trait1, trait2, trait3));
    return rcpp_result_gen;
END_RCPP
}
// webFromNicheModel
LogicalMatrix webFromNicheModel(int nbsp, double connec, bool connect_all, bool unbias, Nullable<NumericVector> niche);
RcppExport SEXP alienR_webFromNicheModel(SEXP nbspSEXP, SEXP connecSEXP, SEXP connect_allSEXP, SEXP unbiasSEXP, SEXP nicheSEXP) {
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
// webFromTraitMatching
LogicalMatrix webFromTraitMatching(int nbsp, Nullable<NumericVector> trait1, Nullable<NumericVector> trait2, Nullable<NumericVector> trait3, Nullable<NumericVector> trait4);
RcppExport SEXP alienR_webFromTraitMatching(SEXP nbspSEXP, SEXP trait1SEXP, SEXP trait2SEXP, SEXP trait3SEXP, SEXP trait4SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbsp(nbspSEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type trait1(trait1SEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type trait2(trait2SEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type trait3(trait3SEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type trait4(trait4SEXP);
    rcpp_result_gen = Rcpp::wrap(webFromTraitMatching(nbsp, trait1, trait2, trait3, trait4));
    return rcpp_result_gen;
END_RCPP
}
