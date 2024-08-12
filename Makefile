CC = g++
#HELPERSPATH = ../gr_helpers/
INCLPATH = ./ 
# $(HELPERSPATH)
CFLAGS = -std=c++2a $(foreach H, $(INCLPATH), -I$(H))
MAIN = train.cpp
EXEC = ./a.out
#HELPERS = $(HELPERSPATH)*.cpp

all: $(EXEC)
#$(HELPERS)
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
