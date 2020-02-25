#pragma once

template < typename T >
BinNodePosi(T) BinNode<T>::succ() {
    BinNodePosi(T) x = this;
    if ( rc ) {
        x = rc;
        while ( HasLChild( *(x) ) ) x = x->lc;
    } else {
        while ( IsRChild( *(x) ) ) x = x->parent;
        x = x->parent;
    }
    return x;
}