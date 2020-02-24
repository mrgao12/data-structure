#pragma once

template < typename T >
BinTree<T>* BinTree<T>::secede ( BinNodePosi(T) x ) {
    FromParentTo ( x ) = NULL;
    updateHeightAbove ( x->parent );
    BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL;
    S->_size = x->size(); _size -= S->_size; return S;
}