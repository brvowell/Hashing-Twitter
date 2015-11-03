// Project 4: Hashing Twitter
// Node Class Header File
// Brandon Vowell

#ifndef NODE_H_
#define NODE_H_

#include <string>

class Node {

    public:
        Node();
        ~Node();
        void removeFront();
        void insertKey(int);
        void insertDate(std::string);
        void insertText(std::string);
        int getKey();
        std::string getDate();
        std::string getText();
        Node *getNext();
        void setNext(Node *);

    private:
        int key;
        std::string date;
        std::string text;
        Node *next;
};

#endif
