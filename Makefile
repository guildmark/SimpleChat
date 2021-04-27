# Makefile for compiling SimpleChat into executable program
#
CC = gcc
FLAGS = -g -std=gnu11 -Wall -Werror -Wextra -Wpedantic

client: client.o
	$(CC) $(FLAGS) client.o -o client

client.o: client.c
	$(CC) $(FLAGS) -c client.c
