PROJ_NAME = Compacta
CC_FLAGS=-c -w -Wall

$(PROJ_NAME): obj/main.o
	gcc -o $(PROJ_NAME) obj/main.o

obj/main.o: implementation/main.c
	gcc -o obj/main.o implementation/main.c $(CC_FLAGS)



clean:
	rm -rf obj/*.o
	rm -rf $(PROJ_NAME)
	rm -rf $(PROJ_NAME_DESCOMP)

rmpromper: clean
	rm -rf $(PROJ_NAME)

run:
	./$(PROJ_NAME) ./in-exemplos/1.txt 3 saida