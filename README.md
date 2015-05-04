# Tigon
interpreter inspired by Tiger syntax

What's implemented:
- variables (with scope)
- if then else
- while
- sequences
- print value of variable

how to execute:

$ make
$ ./calc -v
1+1
@ (1 + 1)
by default interpreter don't make pretty print, to turn the evaluation feature
use environement variable YYEVAL

$ YYEVAL=1 ./calc -v
1+1
@2

we use the "-v" flag to have verbose output, which mean you have a result for each line.
As a result, using pretty printer without "-v" flag is useless.
To have something printed in evaluation mode, you can use the extension "§varname"
$ YYEVAL=1 ./calc
cirno := 9
§cirno
@{9}

moreover, there are test file included with the source in directory "src/"
$ YYEVAL=1 ./calc < src/factoriel9.txt 
@{362880}

