#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <iostream>

template <class T>
class MyList
{
public:
    MyList() : head(new Node) {
        size = 1;
        std::cout << "create first empty list" << std::endl;
    };
    MyList(T val_) : head(new Node{ val_ }) {
        size = 1;
        std::cout << "create first empty list with val argument" << std::endl;
    };
    void setHeadVal(T val_)
    {
        head->val = val_;
    }
    T getHeadVal()
    {
        return head->val;
    }
private:
    struct Node
    {
        T val;
        int numberNode = 0;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> secondLink;
        ~Node()
        {
            std::cout << "delete node" << std::endl;
        }
    };
    std::shared_ptr<Node> head;
    int size = 0;
};

#endif // LINKED_LIST_H
