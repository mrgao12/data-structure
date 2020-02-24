#pragma once

template < typename Tv, typename Te >
void Graph< Tv, Te >::dfs ( int v ) {
    int clock = 0, s = v;
    do {
        if ( status ( v ) == UNDISCOVERED ) DFS ( v, clock );
    } while ( s != ( v = ( ++v % n ) ) );
}

template < typename Tv, typename Te >
void Graph< Tv, Te >::DFS ( int v, int& clock ) {
    status ( v ) = DISCOVERED; dTime ( v ) = ++clock;

    for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) {
        switch ( status ( u ) ) {
            case UNDISCOVERED:
                status ( u ) = DISCOVERED; type ( v, u ) = TREE;
                parent ( u ) = v; DFS ( u, clock ); break;
            case DISCOVERED:
                type ( v, u ) = FORWARD; break;
            default:
                type ( v, u ) = ( dTime ( v ) < dTime ( u ) ? FORWARD : CROSS );
        }
    }

    status ( v ) = VISITED; fTime ( v ) = ++clock;
}