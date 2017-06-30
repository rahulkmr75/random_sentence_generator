obj=main.o functions.o vector.o

main:$(obj)
	gcc -o main $(obj)
main.o:main.c
	gcc -c main.c
functions.o:functions.c functions.h
	gcc -c functions.c
vector.o:vector.c vector.h
	gcc -c vector.c
cleanobj:
	rm *.o
clean:
	make cleanobj
	rm main
