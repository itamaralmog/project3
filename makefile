all: isort txtfind

isort: isort.c
	gcc isort.c -o isort

txtfind: txtfind.c txtfindfun.c
	gcc txtfind.c txtfindfun.c -o txtfind

clean: 
	rm *.o isort txtfind *.a 