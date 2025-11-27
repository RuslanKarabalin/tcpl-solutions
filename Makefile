EXNUM ?= 00

run:
	g++ exercise$(EXNUM)/main.cpp -o x$(EXNUM).out && ./x$(EXNUM).out

generate:
	mkdir -p exercise$(EXNUM) && cp exercise00/main.cpp exercise$(EXNUM)/main.cpp

format:
	clang-format -i $$(find exercise*/ -name '*.cpp')
