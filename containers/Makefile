CC = g++
INCLPATH = ./headers
CFLAGS = -std=c++2a $(foreach H, $(INCLPATH), -I$(H))
MAIN = main.cpp
EXEC = a.out

all: $(EXEC)

$(EXEC) : $(MAIN)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re : fclean all

run: $(EXEC)
	./$^

crun: $(EXEC)
	clear
	./$^

.PHONY: all clean fclean re run crun
