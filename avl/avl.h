#pragma once

#include "../bst/bst.h"

template < typename T >
class AVL : public BST<T> {
    public:
        BinNodePosi(T) insert ( T const& e );
        bool remove ( T const& e );
};

#include "avl_implementation.h"