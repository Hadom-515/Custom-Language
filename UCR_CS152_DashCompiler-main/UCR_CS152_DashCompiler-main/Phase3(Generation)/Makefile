CC=g++
CFLAGS=-std=c++11
BISON=bison
FLEX=flex
RM=rm -f

TARGET= Parse

all: $(TARGET)

$(TARGET): lex.yy.c parser.tab.c
	$(CC) $(CFLAGS) -o $@ $^ -lfl

lex.yy.c: lexer.lex parser.tab.h
	$(FLEX) $<

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d $<

clean:
	$(RM) $(TARGET) lex.yy.c parser.tab.c parser.tab.h
