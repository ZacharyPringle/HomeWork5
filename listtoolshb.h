//
// Created by zpringle on 12/7/2021.
//

#ifndef LISTTOOLS_H
#define LISTTOOLS_H
template< class T >
class Node{
public:
    Node(const T& theData, Node<T>* theLink)
            : data(theData), link(theLink){}
    Node<T>* getLink( ) const { return link; }
    const T& getData( ) const { return data; }
    void setData(const T& theData) { data = theData; }
    void setLink(Node<T>* pointer) { link = pointer; }
private:
    T data;
    Node<T> *link;
};

template< class T >
class MyList: public Node<T>{
public:
    MyList();
    void insertHead(T theData, Node<T>* head);
    void insert(Node<T>* afterMe, const T& theData);
    void deleteNode(Node<T>* before);
    void deleteFirstNode(Node<T>*& head);
    void display (Node<T>* head);
private:
    Node<T> *head;
};

template<class T> Node<T>* search(Node<T>* head, const T& target);


#endif //LISTTOOLS_H