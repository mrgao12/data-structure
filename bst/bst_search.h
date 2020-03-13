#pragma once

template < typename T >
static BinNodePosi(T) & searchIn ( BinNodePosi(T) & v, T const& e, BinNodePosi(T) & hot ) {
    if ( ! v || ( v->data == e ) ) return v;
    hot = v;
    return searchIn ( ( ( e < v->data ) ? v->lc : v->rc ), e, hot );
}

template < typename T >
BinNodePosi(T) & BST<T>::search ( T const& e ) {
    return searchIn ( BinTree<T>::_root, e, _hot );
}