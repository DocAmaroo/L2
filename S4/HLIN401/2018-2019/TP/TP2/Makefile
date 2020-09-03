DOT=$(wildcard *.dot)

TP2: TP2.cc Couples.cc
	g++ $^ -o $@

clean:
	rm -f $(DOT) $(DOT:.dot=.pdf)
