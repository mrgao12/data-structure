#pragma once

template < typename T >
BinNodePosi(T) attachAsLC ( BinNodePosi(T) x, BinTree<T>* &t ) {
    if ( x->lc = S->root ) x->lc->parent = x;
    _size += S->_size; updateHeightAbove ( x );
    S->_root = NULL; S->_size = 0; delete S; return x;
}

template < typename T >
BinNodePosi(T) attachAsRC ( BinNodePosi(T) x, BinTree<T>* &t ) {
    if ( x->rc = S->root ) x->rc->parent = x;
    _size += S->_size; updateHeightAbove ( x );
    S->_root = NULL; S->_size = 0; delete S; return x;
}