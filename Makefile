EXNUM ?= 000
CH := $(shell printf '%s' '$(EXNUM)' | cut -c1)

run:
	clang chapter0${CH}/exercise$(EXNUM).c -o x$(EXNUM).out && ./x$(EXNUM).out

generate:
	mkdir -p chapter0${CH} && cp template/main.c chapter0${CH}/exercise$(EXNUM).c

format:
	clang-format -i $$(find chapter*/ -name '*.c')

print:
	@echo EXNUM=$(EXNUM) CH=$(CH)
