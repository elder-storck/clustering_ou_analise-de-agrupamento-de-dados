PROJ_NAME = trab1
CC_FLAGS=-c -w -Wall -g -lm

$(PROJ_NAME): obj/main.o obj/methodFile.o obj/methodDistance.o obj/UF.o obj/Point.o
	gcc -o $(PROJ_NAME) obj/main.o obj/methodFile.o obj/methodDistance.o obj/UF.o obj/Point.o -lm

obj/main.o: implementation/main.c
	gcc -o obj/main.o implementation/main.c $(CC_FLAGS)

obj/methodFile.o: implementation/methodFile.c
	gcc -o obj/methodFile.o implementation/methodFile.c $(CC_FLAGS)

obj/methodDistance.o: implementation/methodDistance.c
	gcc -o obj/methodDistance.o implementation/methodDistance.c $(CC_FLAGS)

obj/Point.o: implementation/Point.c
	gcc -o obj/Point.o implementation/Point.c $(CC_FLAGS)

obj/UF.o: implementation/UF.c
	gcc -o obj/UF.o implementation/UF.c $(CC_FLAGS)




clean:
	rm -rf obj/*.o
	rm -rf $(PROJ_NAME)

rmpromper: clean
	rm -rf $(PROJ_NAME)

run:
	valgrind ./$(PROJ_NAME) ./in-exemplos/1.txt 2 saida.txt
	