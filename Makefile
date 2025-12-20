EXNUM ?= 000
CH := $(shell printf '%s' '$(EXNUM)' | cut -c1)

run:
	clang chapter0${CH}/exercise$(EXNUM).cpp -o x$(EXNUM).out && ./x$(EXNUM).out

generate:
	mkdir -p chapter0${CH} && cp template/main.cpp chapter0${CH}/exercise$(EXNUM).cpp

format:
	clang-format -i $$(find chapter*/ -name '*.cpp')
