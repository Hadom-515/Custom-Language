all:
	bison -t -d -v parser.y
	flex lexer.lex
	g++ --std=c++11 lex.yy.c parser.tab.c -lfl

