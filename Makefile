# Makefile for compiling SimpleChat into executable program
#
CC = gcc
FLAGS = -g -std=gnu11 -Wall -Wextra -Wpedantic

all: client server

client: client.o
	$(CC) $(FLAGS) client.o -o client

client.o: client.c
	$(CC) $(FLAGS) -c client.c

server: server.o
	$(CC) $(FLAGS) server.o -o server

server.o: server.c
	$(CC) $(FLAGS) -c server.c
