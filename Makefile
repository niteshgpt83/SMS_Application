CC = gcc

OBJ = main.o gsmmodem.o mainmenu.o  gsmdelonesms.o gsmdelsmsmenu.o gsmdelsms.o password.o 

$%.o: %.c
	$(CC) -c -o $@

test: $(OBJ)
	$(CC) -o $@ $^


clean: 
	rm *.o
