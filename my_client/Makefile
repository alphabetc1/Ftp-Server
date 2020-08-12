SRC:=$(wildcard *.c)
a.out:$(SRC)
	gcc $^ -o $@ -lpthread -I /usr/include/mysql/ -lmysqlclient -lcrypt -lssl
clean:
	rm a.out
