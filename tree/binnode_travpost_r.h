#pragma once

template < typename VST, typename T >
void travPost_R ( VST& visit, BinNodePosi(T) x ) {
    if ( ! x ) return;
    if ( HasLChild ( *(x) ) ) travPost_R ( x->lc );
    if ( HasRChild ( *(x) ) ) travPost_R ( x->rc );
    visit ( x->data );
}