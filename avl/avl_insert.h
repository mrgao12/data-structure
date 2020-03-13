#pragma once

template < typename T >
BinNodePosi(T) AVL<T>::insert ( T const& e ) {
    BinNodePosi(T) & v = BST<T>::search ( e ); if ( v ) return v;
    BinNodePosi(T) x = v = new BinNode<T> ( e, BST<T>::_hot ); BinTree<T>::_size++;

    for ( BinNodePosi(T) g = BST<T>::_hot; g; g = g->parent ) {
        if ( ! AvlBalanced( *(g) ) ) {
            FromParentTo( g ) = BST<T>::rotateAt ( tallerChild( tallerChild( g ) ) );
            break;
        } else BinTree<T>::updateHeight( g );
    }
    return x;
}