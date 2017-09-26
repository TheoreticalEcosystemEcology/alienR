### Development practices

- the `master` branch is protected -- code can only arrive in it after a pull request, that has to be reviewed and approved by Steve
- everyone work on branches in this repo
- `git fetch` / `git pull` before you do anything else
- new branches must be made from `master` -- if not, you are responsible for rebasing
- good commit messages are 72 chars on the first line and explain what has been done in the imperative tone. A good rule of thumb is that if you say "If merged, this commit will" before the commit message, it should be a sentence. A good commit message is: `add informations about development practices`. A bad commit message is `CONTRIBUTING changes`
- if the branching complexity of your function is > 3 (number of nested for / if / while), rewrite

### Style Guide

- function names are explicit and with `CamelCased` verbs, *e.g.* `SimulatesNicheModel`.
- objects are declared with lowercase, underscores and small caps, *e.g.* `trophic_level`
- namespaces with `::` (e.g `reshape2::acast`)
- Packages dependancies are declared in the `DESCRIPTION` (import section)
- all `roxygen2` flags (e.g. @param etc.) are to be set up.
- R extension file has to be written in capital letter (e.g `fitBayesReg.R`)

Have a look at [http://adv-r.had.co.nz/Style.html](http://adv-r.had.co.nz/Style.html)

For further details on namespaces: [http://r-pkgs.had.co.nz/namespace.html](http://r-pkgs.had.co.nz/namespace.html)