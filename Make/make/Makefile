result:main.o fun1.o fun2.o
	gcc main.o fun1.o fun2.o -o result
main.o:main.c header.h
	gcc -c main.c
fun1.o:fun1.c header.h
	gcc -c fun1.c
fun2.o:fun2.c header.h
	gcc -c fun2.c
.PHONY:clean
clean:
	rm *.o result
