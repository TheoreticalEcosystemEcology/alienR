#' @name fit4corner
#'
#' @title Fit fourth corner prediction model
#'
#' @description Fit fourth corner prediction model using either the approach proposed by Brown et al. (2014) (\code{\link[mvabund]{traitglm}}) or Ovaskainen et al. (2017) (\link[HMSC]{hmsc}).
#'
#' @param data an object of the class alienData, see as.alienData function.
#' @param formulaFrom A one-sided formula specifying how to construct the trait variables associated to the "From" organisms. Default is "~ .".
#' @param formulaTo A one-sided formula specifying how to construct the trait variables associated to the "To" organisms. Default is "~ .".
#' @param binary Logical. Whether the adjacency matrix is binary or not. Default is TRUE.
#' @param type Method to be used to estimate the model. Either 'mvabund' or 'HMSC' for the implementation of the 'mvabund' (\link[mvabund]{traitglm}) or the 'HMSC' (\link[HMSC]{hmsc}) R package, respectively.
#' @param family For 'mvabund', the family of the response variable can be defined using \link[stats]{family}. The negative binomial with unknown overdispersion and a log-link can be specified as "negative.binomial", and it is the default. For 'HMSC', use either 'probit', 'logit', 'gaussian', 'poisson', 'overPoisson'.
#' @param priors An object of class \code{HMSCprior} (\code{\link[HMSC]{as.HMSCprior}}). If NULL, the function will generate flat priors to estimate the model. This argument is active only when "HMSC" is used.
#' @param iniParam An object of class \code{HMSCparam} (\code{\link[HMSC]{as.HMSCparam}}). If NULL, the function will generate initial parameters ramdomly. This argument is active only when "HMSC" is used.
#' @param \dots Other parameters passed to either \link[mvabund]{traitglm} or \link[HMSC]{hmsc}.
#' 
#' @details 
#' 
#' The fourth corner models are designed to be used on bipartite network where traits are available for both sets of species interacting in the network. It should not be used otherwise.
#' 
#' The fourth corner models assume that adjacency matrix (species by species matrix) used to perform the analysis has as rows the "From" species and as columns the "To" species.
#' 
#' The arguments \code{formulaFrom} and \code{formulaTo} should take the form \code{~ x + y * z}, that is, the left side of the equation should not be given. Also, note that the default formulas always include an intercept.
#' 
#' @return
#' 
#' An object of class alienFit.
#' 
#' @author
#' F. Guillaume Blanchet
#' 
#' @export


fit4corner <- function(data, formulaFrom = "~ .", 
                       formulaTo = "~ .", binary = TRUE,
                       type = "HMSC", family = NULL, 
                       priors = NULL, iniParam = NULL, ...){
  # General check
  stopifnot(class(data) == "alienData")
  
  #############
  # Format data
  #############
  # Adjacency matrix
  adjMat <- getAdjacencyMatrix(data, bipartite = TRUE, 
                                binary = binary)
  
  traits <- getTrait(data, bipartite = TRUE)
  
  # Trait data from
  traitsFrom <- stats::model.matrix(as.formula(formulaFrom), 
                                    data = traits$from)
  
  if(any(colSums(traitsFrom)==0)){
    stop("Some trait combinations defined by formulaFrom do not exist")
  }
  
  # Trait data to
  traitsTo <- stats::model.matrix(as.formula(formulaTo), 
                                  data = traits$to)

  if(any(colSums(traitsTo)==0)){
    stop("Some trait combinations defined by formulaTo do not exist")
  }
  
  # mvabund
  if(type == "mvabund"){
    # Perform traitglm analysis
    model <- mvabund::traitglm(adjMat, traits$to, traits$from,
                               family = family, ...)
  }

  # HMSC
  if(type == "HMSC"){
    # Trait data from
    traitsFrom <- stats::model.matrix(as.formula(formulaFrom),
                                      data = traits$from)
    
    # Trait data to
    traitsTo <- stats::model.matrix(as.formula(formulaTo),
                                    data = traits$to)
    
    # Construct HMSCdata object
    Data <- HMSC::as.HMSCdata(Y = adjMat, X = traitsTo,
                              Tr = t(traitsFrom), scaleX = FALSE,
                              scaleTr = FALSE,
                              interceptX = FALSE,
                              interceptTr = FALSE)

    # Construct HMSCprior object
    if(is.null(priors)){
      priors <- HMSC::as.HMSCprior(Data, family = family)
    }
    
    # Construct HMSCprior object
    if(is.null(iniParam)){
      iniParam <- HMSC::as.HMSCparam(Data, priors)
    }
      
    # Perform HMSC analysis
    model <- HMSC::hmsc(Data, param = iniParam, priors = priors,
                      family = family, ...)
    
  }
  
  # Prediction
  res <- predict(model)
  
  # Add model as attribute
  baseAttr <- attributes(res)
  attributes(res) <- list(dim = baseAttr$dim,
                          dimnames = baseAttr$dimnames,
                          model = model,
                          adjMat = adjMat)
  
  # Define object class
  class(res) <- "alienFit"
  
  return(res)
}
  