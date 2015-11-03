# Makefile for Project 4: Hashing Twitter
# Brandon Vowell

all:
	g++ -Wall -std=c++11 tweets.cpp node.cpp hashmap.cpp -o project4

clean:
	rm -f project4
