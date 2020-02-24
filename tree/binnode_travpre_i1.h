#pragma once

template < typename VST, typename T >
void travPre_I1 ( VST& visit, BinNodePosi(T) x ) {
    stack< BinNodePosi(T) > S;
    S.push ( x );

    while ( ! S.empty() ) {
        x = S.top(); S.pop();
        visit ( x->data );
        if ( HasRChild( *(x) ) ) S.push ( x->rc );
        if ( HasLChild( *(x) ) ) S.push ( x->lc );
    }
}