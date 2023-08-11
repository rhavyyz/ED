#pragma once

// #include <string>
#include <iostream>
#include <malloc.h>

struct Node
{
    Node * next;
    int key, value;
};

// it is meant to be used just inside my hash classes
class LinkedList
{
    public:
    Node * root = 0; 
    int size = 0;

    void freeList(Node * node)
    {
        if(!node)
            return;

        freeList(node->next);
        free(node);
    }

    public:
    int findValue(int key)
    {
        Node * aux = root;

        while(aux)
        {
            if(aux->key == key)
                return aux->value;

            aux = aux->next;
        }

        return -1;
    }

    void addElement(int key, int value)
    {
        Node * newNode = (Node*) malloc(sizeof(Node));

        *newNode = {root, key, value};

        root = newNode;

        size++;
    }

    ~LinkedList()
    {
        freeList(root);
    }


    int getSize()
    {
        return size;
    }

    std::string toString()
    {
        std::string str = "";
        auto aux = root;
        while(aux)
        {
            str += std::to_string(aux->key) + " " + std::to_string(aux->value) + " | ";
            aux = aux->next;
        }
        str += "\n";
        return str;    
    }

};
