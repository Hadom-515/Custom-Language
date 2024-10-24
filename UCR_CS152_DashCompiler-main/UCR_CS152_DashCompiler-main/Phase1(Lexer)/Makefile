all: lexer

lexer: lexer.lex
	flex lexer.lex
	gcc -o lexer.o lex.yy.c -lfl
ean:
	rm -f lexer lex.yy.c
