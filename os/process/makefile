all:get copy put main
	echo "complete"
get:get.o
	gcc -o get get.o
copy:copy.o
	gcc -o copy copy.o
put:put.o
	gcc -o put put.o
main:main.o
	gcc -o main main.o
get.o:get.c
	gcc -c get.c
copy.o:copy.c
	gcc -c copy.c
put.o:put.c
	gcc -c put.c
main.o:main.c
	gcc -c main.c
