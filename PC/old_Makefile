CC = gcc
CFLAGS = -Wall -O3 -lm
CPPFLAGS = 

lab2_S4: Lab2_S4.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

lab2_S5: Lab2_S5.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

lab2_S8: Lab2_S8.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

assortment: assortment.c
	gcc -o ass assortment.c -Wall -O3 -lm

lab: Laborator1.c
	gcc -o lab1 Laborator1.c -Wall -O3 -lm

Laborator1.c:
	echo "meow"

clean:
	rm lab1
