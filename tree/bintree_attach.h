#pragma once

template < typename T >
BinNodePosi(T) BinTree<T>::attachAsLC ( BinNodePosi(T) x, BinTree<T>* &S ) {
    if ( x->lc = S->_root ) x->lc->parent = x;
    _size += S->_size; updateHeightAbove ( x );
    S->_root = NULL; S->_size = 0; delete S; return x;
}

template < typename T >
BinNodePosi(T) BinTree<T>::attachAsRC ( BinNodePosi(T) x, BinTree<T>* &S ) {
    if ( x->rc = S->_root ) x->rc->parent = x;
    _size += S->_size; updateHeightAbove ( x );
    S->_root = NULL; S->_size = 0; delete S; return x;
}