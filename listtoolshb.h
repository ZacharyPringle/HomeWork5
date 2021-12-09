//
// Created by zpringle on 12/7/2021.
//

#ifndef LISTTOOLS_H
#define LISTTOOLS_H
#include <iostream>
using namespace std;

//node class used to hold contents of the members of MyList
template< class T >
class Node{
public:
    Node(const T& theData, Node<T>* theLink)
            : data(theData), link(theLink){}
    Node<T>* getLink( ) const { return link; }
    T& getData( ) { return data; }
    void setData(const T& theData) { data = theData; }
    void setLink(Node<T>* pointer) { link = pointer; }
private:
    T data;
    Node<T> *link;
};

//holds nodes in a list and performs the functions defined in the .cpp
template< class T >
class MyList{
public:
    MyList():head(NULL){}
    void insertHead(T theData);
    T deleteHead();
    void display ();
    bool search(T&target);
private:
    Node<T> *head;
};

#endif //LISTTOOLS_H