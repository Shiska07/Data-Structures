execulatable: main.o edit_distance.o
	gcc -o edit_distance main.o edit_distance.o
main.o: main.c edit_distance.h
	gcc -c main.c edit_distance.h
edit_distance.o: edit_distance.c edit_distance.h
	gcc -c edit_distance.c edit_distance.h
cleanup:
	rm *.o 
	rm edit_distance
