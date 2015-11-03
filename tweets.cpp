// Project 4: Hashing Tweets
// Brandon Vowell
// Main function and global variables

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "node.h"
#include "hashmap.h"

int options();
void filter(char **);
int hashCode(const std::string&);
void fillNode(std::string, int, Node*);
void one(Node *);
void two();
void three();

const int hashSeed = 5381;
const int hashMultiplier = 33;
const int hashMask = unsigned(-1) >> 1;
const int num = 5438;
int a = 0;
Node twit[num];
Node value[num];
Node *ptr = &twit[0];
HashMap map;
std::string data;

int main(int argc, char *argv[])    {
    filter(argv);
    int count = 0;
    std::ifstream input1("filter.txt");
    getline(input1, data);
    while(!input1.eof()) {
        getline(input1, data);
        if(count % 4 != 3) {
            fillNode(data, count, ptr);
        }
        else {
            int index = map.getIndex(ptr->getKey());
            map.put(index, ptr->getKey());
            map.putNode(ptr, index);
            ptr = &twit[(count >> 2) + 1];
        }
        count++;
    }
    system ("rm -f filter.txt");
    int i = 0;
    while(i != 4)   {
        i = options();
        if(i == 1) {
            Node *ask = new Node;
            if(a >= num)
                std::cout << "Too many new nodes." << std::endl;
            ask = &value[a];
            one(ask);
            a++;
        }
        if(i == 2)
            two();
        if(i == 3) 
            three();
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////

int options()   {
    int i = 0;
        std::cout << "1.\tEnter new Tweet\n" << "2.\tDelete all tweets for a given screen_name\n"\
                  << "3.\tView Tweets\n" << "4.\tQuit\n" << std::endl;
        std::cin >> i;
        while(i > 4 || i < 1)   {
            std::cout << "Option not in range, try again.\n" << std::endl;
            std::cin >> i;
        }
    std::cout << std::endl;
    return i;
}

void filter(char **argv) {
    std::ifstream input(argv[1]);
    std::ofstream output("filter.txt");
    std::stringstream buffer;

    buffer << input.rdbuf();
    std::string s = buffer.str();
    int j = 0;
    while(s[j] != '\0') {
        if((s[j] == '"' && s[j-1] != '\\') || s[j] == '{' || s[j] == '}')
            s.erase(j, 1);
        else
            j++;
    }
    output << s;
    return;
}

int hashCode(const std::string &str) {
    unsigned hash = hashSeed;
    int nchars = str.length();
    for(int i = 0; i < nchars; i++) {
        hash = hashMultiplier * hash + str[i];
    }
    return (hash &hashMask);
}
  
void fillNode(std::string data, int count, Node *ptr) {
    if(data.find(':') != std::string::npos)
        data = data.substr(data.find(':') + 1);
    if(data[data.length() - 2] == ',') 
        data.erase(data.length() - 2, 2);
    if(count % 4 == 0)
        ptr->insertDate(data);
    if(count % 4 == 1)
        ptr->insertText(data);
    if(count % 4 == 2) {
        ptr->insertKey(hashCode(data));
    }
}

void one(Node *ptr) {
    std::string name, word;
    std::cout << "Enter a username: ";
    getline(std::cin, name); getline(std::cin, name);
    int code = hashCode(name);
    std::cout << "Enter a tweet: ";
    getline(std::cin, word);
    ptr->insertKey(code);
    ptr->insertText(word);
    map.put(map.getIndex(code), ptr->getKey());
    map.putNode(ptr, map.getIndex(code));
    std::cout << std::endl;
    return;
}

void two() {
    std::string name;
    std::cout << "Enter username in which to delete tweets: ";
    getline(std::cin, name); getline(std::cin, name);
    int code = hashCode(name);
    if(map.contains(code) == false) {
        std::cout << "This username does not exist in the table." << std::endl;
        std::cout << std::endl;
        return;
    }
    map.remove(code);
    return;
}

void three() {
    std::string name;
    std::cout << "Enter a username: ";
    getline(std::cin, name); getline(std::cin, name);
    int key = hashCode(name);
    if(map.contains(key) == false)
        std::cout << "This username does not exist in the table." << std::endl;
    else {
        map.get(map.findIndex(key));
    }
    std::cout << std::endl;
    return;
}

