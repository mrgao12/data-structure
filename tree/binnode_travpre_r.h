#pragma once

template < typename T, typename VST >
void travPre_R ( VST& visit, BinNodePosi(T) x ) {
    if ( !x ) return;
    visit ( x->data );
    travPre_R ( visit, x->lc );
    travPre_R ( visit, x->rc );
}