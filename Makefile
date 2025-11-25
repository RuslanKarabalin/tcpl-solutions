EXNUM ?= 00

run:
	gcc exercise$(EXNUM)/main.c -o x$(EXNUM).out && ./x$(EXNUM).out

generate:
	mkdir -p exercise$(EXNUM) && cp exercise00/main.c exercise$(EXNUM)/main.c

format:
	clang-format -i $$(find exercise*/ -name '*.c')
