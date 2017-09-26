context("alienData function")

# define df_nd0, df_sit0, df_occ0 and df_sit0
source("minimalEx.R")



df_nd3 <- df_nd2 <- df_nd1 <- df_nd0

names(df_nd1) <- "val1"
df_nd2$idNodes[nbnod] <- df_nd0$idNodes[1L]
df_nd3$var1 <- runif(nbnod)
df_nd3$var2 <- runif(nbnod)

##----
df_int5 <- df_int4 <- df_int3 <- df_int2 <- df_int1 <- df_int0
names(df_int1)[1L] <- "new"
names(df_int2)[2L] <- "new"
df_int3[1L,1L] <- "new"
df_int4[1L,2L] <- "new"
df_int5$idSite <- idsit
df_int7 <- df_int6 <- df_int5
df_int6$idSite[1L] <- "new"
df_int7$value <- runif(nrow(df_int0))

##----
df_sit2 <- df_sit1 <- df_sit0
names(df_sit1)[1L] <- "new"
df_sit2$idSite[5L] <- df_sit2$idSite[1L]
# add one variable
df_sit3 <- cbind(df_sit0, var = runif(nrow(df_sit0)))

##----
 df_occ4 <-df_occ3 <- df_occ2 <- df_occ1 <- df_occ0
 names(df_occ1)[1L] <- "new"
 names(df_occ2)[2L] <- "new"
 df_occ3[1L,1L] <- "new"
 df_occ4[1L,2L] <- "new"

# ####
res0 <- alienData(df_nd0, df_int0, dfSites=df_sit0, verbose=F)
res1 <- alienData(df_nd0, df_int0, dfSites=df_sit0, dfOcc = df_occ0, verbose=F)
res2 <- alienData(df_nd3, df_int0, dfSites=df_sit0, dfOcc = df_occ0, trait=2, phylo=2, taxo=3, verbose=F)
res3 <- alienData(df_nd3, df_int7, verbose=F)
res4 <- alienData(df_nd0, df_int0, dfSites = df_sit3, siteEnv = 2, verbose = F)

sum2 <- summary(res2)

##
test_that("check dfSpecies", {
  expect_error(alienData(df_nd1, df_int0), '"idNodes" %in% names(dfNodes) is not TRUE', fixed = TRUE)
  expect_error(alienData(df_nd2, df_int0), "!any(table(dfNodes$idNodes) > 1) is not TRUE", fixed = TRUE)
})

##
test_that("check dfEdges", {
  expect_error(alienData(df_nd0, df_int1), '"idFrom" %in% names(dfEdges) is not TRUE', fixed = TRUE)
  expect_error(alienData(df_nd0, df_int2), '"idTo" %in% names(dfEdges) is not TRUE', fixed = TRUE)
  expect_error(alienData(df_nd0, df_int3), "all(dfEdges$idFrom %in% dfNodes$idNodes) is not TRUE", fixed=TRUE)
  expect_error(alienData(df_nd0, df_int4), "all(dfEdges$idTo %in% dfNodes$idNodes) is not TRUE", fixed=TRUE)
  expect_warning(alienData(df_nd0, df_int0[1L,], verbose=F))
})

##
test_that("check dfSites", {
  expect_error(alienData(df_nd0, df_int0, dfSites = df_sit1), '"idSite" %in% names(dfSites) is not TRUE', fixed = TRUE)
  expect_error(alienData(df_nd0, df_int0, dfSites = df_sit2), "all(table(dfSites$idSite) == 1) is not TRUE", fixed = TRUE)
  expect_error(alienData(df_nd0, df_int6, dfSites = df_sit0), "all(dfEdges$idSite %in% dfSites$idSite) is not TRUE", fixed = TRUE)
})

##
test_that("check dfOcc", {
  expect_error(alienData(df_nd0, df_int0, dfSites = df_sit0, dfOcc = df_occ1), '"idSite" %in% names(dfOcc) is not TRUE', fixed = TRUE)
  expect_error(alienData(df_nd0, df_int0, dfSites = df_sit0, dfOcc = df_occ2), '"idNodes" %in% names(dfOcc) is not TRUE', fixed = TRUE)
  expect_error(alienData(df_nd0, df_int0, dfSites = df_sit0, dfOcc = df_occ3), "all(dfOcc$idSite %in% dfSites$idSite) is not TRUE", fixed = TRUE)
  expect_error(alienData(df_nd0, df_int0, dfSites = df_sit0, dfOcc = df_occ4), "all(dfOcc$idNodes %in% dfNodes$idNodes) is not TRUE", fixed = TRUE)
})

##
test_that("check output values", {
  expect_warning(alienData(df_nd0, df_int0, dfSites=df_sit0, verbose=F), "Site information provided without any occurrence")
  expect_is(res1, "alienData")
  expect_equal(res1$nbNodes, nrow(df_nd0))
  expect_equal(res1$nbEdges, nrow(df_int0))
  expect_equal(res1$nbSite, nrow(df_sit0))
  expect_equal(res1$availableMeths$available, c(TRUE, FALSE, FALSE))
  expect_true(all(res1$dfEdges$value==1))
  expect_equal(res2$nmTrait, "var1")
  expect_equal(res2$nmPhylo, "var1")
  expect_equal(res2$nmTaxo, "var2")
  expect_true(all(res2$availableMeths$available))
  #
  expect_equal(res3$nbSites, length(unique(idsit)))
  expect_true(!all(res3$dfEdges$value==1))
  #
  # expect_true(all(dim(res4$dfSite) == c(nrow(df_sit0), 2)))

  ##
  expect_is(sum2, "summary.alienData")
  expect_is(sum2$dfNodes, "table")
  expect_is(sum2$Traits, "table")
  expect_is(sum2$Phylos, "table")
  expect_is(sum2$Taxos, "table")
  ##

})