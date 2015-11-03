// Project 4: Hashing Twitter
// HashMap Class Implementation File
// Brandon Vowell

#include <string>
#include <iostream>
#include "hashmap.h"
#include "node.h"


HashMap::HashMap() {
    number = 0;
    size = 8011;
    keys = new int[size];
    array = new Node*[size];
    for(int i = 0; i < size; i++) {
        keys[i] = -1;
        array[i] = NULL;
    }
}

HashMap::~HashMap() {
    for(int i = 0; i < size; i++) {
        if(array[i] != NULL) {
            array[i]->removeFront();
            array[i] = array[i]->getNext();
        }
        keys[i] = -1;
    }
}

int HashMap::getIndex(int key) {
    int index = key % size;
    while(1) {
        if(keys[index] == -1)
            return index;
        if(keys[index] == key)
            return index;
        index++;
    }
}

int HashMap::findIndex(int key) {
    int index = key % size;
    if(keys[index] == key)
        return index;
    while(keys[index] != key)
        index++;
    return index;
}

void HashMap::put(int index, int value) {
    keys[index] = value;
    return;
}

void HashMap::get(int index) {
    std::string value;
    Node *ptr = array[index];
    while(ptr != NULL) {
        value = ptr->getText();
        std::cout << value << std::endl;
        ptr = ptr->getNext();
    }
    return;
}

bool HashMap::contains(int key) {
    int i = key % size;
    while(keys[i] != -1) {
        if(keys[i] == key)
            return true;
        i++;
    }
    return false;
}

void HashMap::putNode(Node *ptr,int index) {
    if(array[index] == NULL)
        array[index] = ptr;
    else {
        Node *temp;
        temp = array[index];
        while(temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp->setNext(ptr);
    }
    number++;
    return;
}

int HashMap::count() {
    return number;
}

void HashMap::remove(int key) {
    int index = findIndex(key);
    while(array[index] != NULL) {
        array[index]->removeFront();
        number--;
        array[index] = array[index]->getNext();
    }
    keys[index] = -1;
    return;
}

