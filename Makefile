all : utf8_encode.o
	gcc -o bj bj.c ./utf8_encode.o
utf8encode.o : 
	gcc -c utf8_encode.c
clean :
	rm ./bj ./*.o
