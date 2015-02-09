CC = clang
BISON = bison
BISONFLAGS =
FLEX = flex
FLEXFLAGS =

all: calc

calc: parsecalc.o scancalc.o
	$(CC) $^ -o $@

scancalc.o: parsecalc.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.c: %.l
	$(FLEX) $(FLEXFLAGS) -o$@ $<

%.c: %.y
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

.PRECIOUS: %.c

CLEANFILES = \
  *~ *.o calc \
  parsecalc.c parsecalc.h parsecalc.output \
  scancalc.c

.PHONY: clean
clean:
	rm -f $(CLEANFILES)
