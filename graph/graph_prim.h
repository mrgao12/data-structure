#pragma once

template < typename Tv, typename Te >
void Graph< Tv, Te >::prim ( int v ) {
    reset(); priority ( v ) = 0;
    for ( int i = 0; i < n; i++ ) {
        status ( v ) = VISITED;
        if ( -1 != parent ( v ) ) type ( parent(v), v ) = TREE;
        for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) {
            if ( ( status ( u ) == UNDISCOVERED ) && ( priority ( u ) > weight ( v, u ) ) ) {
                priority ( u ) = weight ( v, u ); parent ( u ) = v;
            }
        }
        for ( int shortest = INT_MAX, i = 0; i < n; i++ ) {
            if ( ( status ( i ) == UNDISCOVERED ) && ( shortest > priority ( i ) ) ) {
                shortest = priority ( i ); v = i;
            }
        }
    }
}