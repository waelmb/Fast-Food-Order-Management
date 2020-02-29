proj4: proj4Main.o proj4Functions.o proj4List.o
	gcc -g -o proj4 proj4Main.o proj4Functions.o proj4List.o

proj4Main.o: proj4Main.c proj4.h
	gcc -g -c proj4Main.c

proj4Functions.o: proj4Functions.c proj4.h
	gcc -g -c proj4Functions.c

proj4List.o: proj4List.c proj4.h
	gcc -g -c proj4List.c

clean:
	rm proj4Main.o proj4Functions.o proj4List. proj4