all : utf8_encode.o deck.o
	gcc bj.c ./utf8_encode.o ./deck.o
utf8encode.o : 
	gcc -c utf8_encode.c
deck.o : 
	gcc -c deck.c
clean :
	rm ./a.out ./*.o
