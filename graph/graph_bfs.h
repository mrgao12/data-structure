#pragma once

#include <queue>
using namespace std;

template < typename Tv, typename Te >
void Graph< Tv, Te >::bfs ( int v ) {
    int clock = 0, s = v;
    do {
        if ( status ( v ) == UNDISCOVERED ) BFS ( v, clock );
    } while ( s != ( v = ( ++v % n ) ) );
}

template < typename Tv, typename Te >
void Graph< Tv, Te >::BFS ( int v, int& clock ) {
    queue<int> Q; Q.push ( v );
    while ( ! Q.empty() ) {
        v = Q.front(); Q.pop();
        status ( v ) = DISCOVERED; dTime ( v ) = ++clock;
        for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) {
            if ( status ( u ) == UNDISCOVERED ) {
                status ( u ) = DISCOVERED; Q.push ( u );
                parent ( u ) = v; type ( v, u ) = TREE;
            } else type ( v, u ) = CROSS;
        }
        status ( v ) = VISITED;
    }
    
}