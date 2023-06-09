PROJ_NAME = trab1
CC_FLAGS=-c -w -Wall -g -lm

$(PROJ_NAME): obj/main.o obj/outFile.o obj/edgeFile.o obj/UF.o obj/Point.o obj/utility.o
	gcc -o $(PROJ_NAME) obj/main.o obj/outFile.o obj/edgeFile.o obj/UF.o obj/Point.o obj/utility.o -lm

obj/main.o: implementation/main.c
	gcc -o obj/main.o implementation/main.c $(CC_FLAGS)

obj/outFile.o: implementation/outFile.c
	gcc -o obj/outFile.o implementation/outFile.c $(CC_FLAGS)

obj/edgeFile.o: implementation/edgeFile.c
	gcc -o obj/edgeFile.o implementation/edgeFile.c $(CC_FLAGS)

obj/Point.o: implementation/Point.c
	gcc -o obj/Point.o implementation/Point.c $(CC_FLAGS)

obj/UF.o: implementation/UF.c
	gcc -o obj/UF.o implementation/UF.c $(CC_FLAGS)

obj/utility.o: implementation/utility.c
	gcc -o obj/utility.o implementation/utility.c $(CC_FLAGS)




clean:
	rm -rf obj/*.o
	rm -rf $(PROJ_NAME)

rmpromper: clean
	rm -rf $(PROJ_NAME)

run:
	./$(PROJ_NAME) ./in-exemplos/1.txt 2 saida.txt
	