#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H
#include "node_iterator.h"
class NullIterator:public NodeIterator{
    public:
        void first(){

        }
        bool isDone(){
            return true;
        }
        void next(){

        }
        Node * currentItem(){
            return nullptr;
        } 
};
#endif