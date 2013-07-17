CC=gcc

FILES:=main.c
FILES+=parser.c

argsparser:
	$(CC) -o parser $(FILES)

clean:
	rm parser
