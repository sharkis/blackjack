all : utf8_encode.o
	gcc bj.c ./utf8_encode.o
utf8encode.o : 
	gcc -c utf8_encode.c
clean :
	rm ./a.out ./*.o
