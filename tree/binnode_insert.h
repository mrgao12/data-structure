#pragma once

template < typename T >
BinNodePosi(T) BinNode<T>::insertAsLC ( T const& e ) {
    return lc = new BinNode<T> ( e, this );
}

template < typename T >
BinNodePosi(T) BinNode<T>::insertAsRC ( T const& e ) {
    return rc = new BinNode<T> ( e, this );
}