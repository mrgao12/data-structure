#pragma once

template < typename VST, typename T >
void travIn_R ( VST& visit, BinNodePosi(T) x ) {
    if ( ! x ) return;
    travIn_R ( visit, x->lc );
    visit ( x->data );
    travIn_R ( visit, x->rc );
}