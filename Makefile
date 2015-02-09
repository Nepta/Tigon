BISON = bison
BISONFLAGS =
FLEX = flex
FLEXFLAGS =
CFLAGS=-Wall -Wextra
all: calc

calc: parsecalc.o scancalc.o
	$(CXX) $^ -o $@

scancalc.o: parsecalc.hpp

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

%.cpp: %.ll
	$(FLEX) $(FLEXFLAGS) -o$@ $<

%.cpp: %.yy
	$(BISON) $(BISONFLAGS) $< -o$@

.PHONY: check
check: calc
	test $$(echo "1+2" | ./calc) = 3
	test $$(echo "1+2*3" | ./calc) = 7
	test $$(echo "(1+2)*3" | ./calc) = 9
	test $$(echo "(1+2)*0" | ./calc) = 0
	test $$(echo "8/4/2" | ./calc) = 1
	test $$(echo "1-2-3" | ./calc) = -4
	test "$$(printf "1+1\n2+3\n" | ./calc)" = "$$(printf "2\n5\n")"
	! echo "1++2" | ./calc
	! echo "1+" | ./calc
	! echo "(1" | ./calc
	! echo "(1))" | ./calc

.PRECIOUS: %.cpp

CLEANFILES = \
  *~ *.o calc \
  parsecalc.cpp parsecalc.h parsecalc.output \
  scancalc.cpp

.PHONY: clean
clean:
	rm -f $(CLEANFILES)
