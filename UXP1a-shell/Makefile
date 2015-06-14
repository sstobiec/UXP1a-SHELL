# Makefile

OBJS	= bison.o lex.o main.o
OBJ_DEBUG = localfunction.o unix.o arg_list.o

CC = gcc
CFLAGS	= -g -Wall 

shell:	$(OBJ_DEBUG) $(OBJS)
		$(CC) $(CFLAGS) $(OBJ_DEBUG) $(OBJS) -o shell -lfl

lex.o:	lex.c
		$(CC) $(CFLAGS) -c lex.c -o lex.o

lex.c:	shell.lex 
		flex shell.lex
		cp lex.yy.c lex.c

bison.o:	bison.c
		$(CC) $(CFLAGS) -c bison.c -o bison.o

bison.c:	shell.y
		bison -d -v shell.y
		cp shell.tab.c bison.c
		cmp -s shell.tab.h tok.h || cp shell.tab.h tok.h

main.o:		main.c
		$(CC) $(CFLAGS) -c main.c -o main.o

lex.o yac.o main.o	: header.h
lex.o main.o		: tok.h

localfunction.o: localfunction.c
	$(CC) $(CFLAGS) -c localfunction.c -o localfunction.o

unix.o: unix.c
	$(CC) $(CFLAGS) -c unix.c -o unix.o

arg_list.o: arg_list.c
	$(CC) $(CFLAGS) -c arg_list.c -o arg_list.o

clean:
	rm -f *.o *~ lex.c lex.yy.c bison.c tok.h shell.tab.c shell.tab.h shell.output shell

