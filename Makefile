rfun := $(wildcard R/*.R)
rman := $(wildcard man/)
rcpp := $(wildcard src/*.cpp)
rtes := $(wildcard tests/testthat/*.R)
rdm = README.Rmd
md = README.md
chk = record_updates.txt
rscr = pkg2date.R


all: $(md) $(chk)

$(md): $(rdm)
	Rscript --no-site-file  --no-init-file $(rscr) 0

$(chk): $(rfun) $(rtes) $(rman) $(rcpp)
	Rscript --no-site-file  --no-init-file $(rscr) 1

clean:
	rm -rf man/* NAMESPACES src/*.o src/*.so R/RcppExports.R src/RcppExports.cpp
