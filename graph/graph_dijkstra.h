#pragma once

template < typename Tv, typename Te >
void Graph< Tv, Te >::dijkstra ( int s ) {
    reset(); priority ( s ) = 0;
    for ( int i = 0; i < n; i++ ) {
        status ( s ) = VISITED;
        if ( -1 != parent ( s ) ) type ( parent ( s ), s ) = TREE;
        for ( int v = firstNbr ( s ); -1 < v; v = nextNbr ( s, v ) ) {
            if ( ( status ( v ) == UNDISCOVERED ) && ( priority ( v ) > priority ( s ) + weight ( s, v ) ) ) {
                priority ( v ) = priority ( s ) + weight ( s, v ); parent ( v ) = s;
            }
        }
        for ( int shortest = INT_MAX, j = 0; j < n; j++ ) {
            if ( ( status ( j ) == UNDISCOVERED ) && ( priority ( j ) < shortest ) ) {
                shortest = priority ( j ); s = j;
            }
        }
    }
}