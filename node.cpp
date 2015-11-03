// Project 4: Hashing Twitter
// Node Class Implementation File
// Brandon Vowell

#include <string>
#include <iostream>
#include "node.h"

Node::Node() {
    key = -1;
    date = "\0";
    text = "\0";
    next = NULL;
}

Node::~Node() {
    while(next != NULL)
        removeFront();
}

void Node::removeFront() {
    Node *temp;
    if(next != NULL) {
        temp = next;
        next = temp->next;
        temp->next = NULL;
        //delete temp;
    }
    return;
}

void Node::insertKey(int hash) {
    key = hash;
    return;
}

void Node::insertDate(std::string time) {
    date = time;
    return;
}

void Node::insertText(std::string tweet) {
    text = tweet;
    return;
}

int Node::getKey() {
    return key;
}

std::string Node::getDate() {
    return date;
}

std::string Node::getText() {
    return text;
}

Node * Node::getNext() {
    return next;
}

void Node::setNext(Node *ptr) {
    next = ptr;
}

