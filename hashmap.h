// Project 4: Hashing Twitter
// Hashmap Class Header File
// Brandon Vowell

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <string>
#include "node.h"

class HashMap {
    
    public:
        HashMap();
        ~HashMap();
        int getIndex(int);
        int findIndex(int);
        void put(int, int);
        void putNode(Node *, int);
        void get(int);
        bool contains(int);
        int count();
        void remove(int);

  
    private:
        int *keys;
        Node **array;
        int number;
        int size;
};
    
#endif
