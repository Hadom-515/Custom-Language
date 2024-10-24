all:  parser

lexer: lexer.yy.c
	gcc -o $@ $@.yy.c -lfl

parser: lexer.yy.c parser.tab.c parser.tab.h
	gcc -o parser parser.tab.c lexer.yy.c -lfl -lm -std=c99 -D_GNU_SOURCE


%.yy.c:  %.lex
	flex -o$@ $<

%.tab.c %.tab.h: %.y
	bison -t -v -d $<

clean:
	rm -f *.tab.c *.tab.h *.yy.c *.output .*.swp 

