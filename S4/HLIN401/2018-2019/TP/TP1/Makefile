DOT=$(wildcard *.dot)

TP1: TP1.cc ArbreBinaire.cc
	g++ $^ -o $@

clean:
	rm -f $(DOT) $(DOT:.dot=.pdf)
