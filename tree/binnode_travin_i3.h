#pragma once

template < typename VST, typename T >
void travIn_I3 ( VST& visit, BinNodePosi(T) x ) {
    bool backtrack = false;

    while ( true ) {
        if ( HasLChild( *(x) ) && ! backtrack ) {
            x = x->lc;
        } else {
            visit ( x->data );

            if ( HasRChild( *(x) ) ) {
                x = x->rc;
                backtrack = false;
            } else {
                if ( ! ( x = x->succ() ) ) break;
                backtrack = true;
            }
        }
    }
}