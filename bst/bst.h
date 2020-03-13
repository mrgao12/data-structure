#pragma once

#include "../tree/bintree.h"
#include <iostream>
using namespace std;

template < typename T >
class BST : public BinTree<T> {
    protected:
        BinNodePosi(T) _hot;
        BinNodePosi(T) connect34 (
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T)
        );
        BinNodePosi(T) rotateAt ( BinNodePosi(T) x );
    public:
        virtual BinNodePosi(T) & search ( T const& e );
        virtual BinNodePosi(T) insert ( T const& e );
        virtual bool remove ( T const& e );
};

#include "bst_implementation.h"