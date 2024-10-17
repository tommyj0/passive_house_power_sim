CC=gcc
INC_FILES=inc
all:
	$(CC) src/*.c -g -o passive_house_sim -I$(INC_FILES) -lm -std=c2x
	./passive_house_sim


	
