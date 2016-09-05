include ../../.mk/makefile.def

BIN = test_dijkstra

all: $(BIN) graph.pdf

graph.pdf:graph.dot
	dot -Kfdp -Tpdf $< -o$@ 

include ../../.mk/makefile.inc
