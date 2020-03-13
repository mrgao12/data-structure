#pragma once

template < typename T >
bool BST<T>::remove ( T const& e ) {
    BinNodePosi(T) & x = search ( e );
    if ( ! x ) return false;

    removeAt ( x, _hot ); BinTree<T>::_size--;
    BinTree<T>::updateHeightAbove ( _hot );
    return true;
}