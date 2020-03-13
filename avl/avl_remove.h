#pragma once

template < typename T >
bool AVL<T>::remove ( T const& e ) {
    BinNodePosi(T) & v = BST<T>::search ( e ); if ( ! v ) return false;
    removeAt ( v, BST<T>::_hot ); BinTree<T>::_size--;

    for ( BinNodePosi(T) g = BST<T>::_hot; g; g = g->parent ) {
        if ( ! AvlBalanced( *(g) ) ) g = FromParentTo( g ) = BST<T>::rotateAt ( tallerChild( tallerChild( g ) ) );
        BinTree<T>::updateHeight( g );
    }
    return true;
}