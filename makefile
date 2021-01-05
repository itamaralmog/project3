all: isort txtfind

isort: isort.c
	gcc -Wall isort.c -o isort

txtfind: txtfind.c txtfindfun.c
	gcc -Wall txtfind.c txtfindfun.c -o txtfind

clean: 
	rm isort txtfind 