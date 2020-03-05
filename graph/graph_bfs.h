#pragma once

#include <queue>
using namespace std;

template < typename Tv, typename Te >
void Graph<Tv, Te>::bfs ( int v ) {
    reset(); int clock = 0; int s = v;
    do {
        if ( status ( v ) == UNDISCOVERED ) BFS ( v, clock );
    } while ( s != ( v = ( ++v % n ) ) );
}

template < typename Tv, typename Te >
void Graph<Tv, Te>::BFS ( int v, int& clock ) {
    queue<int> Q; status ( v ) = DISCOVERED; Q.push ( v );
    while ( ! Q.empty() ) {
        v = Q.front(); Q.pop();
        dTime ( v ) = ++clock;
        for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) {
            if ( status ( u ) == UNDISCOVERED ) {
                parent ( u ) = v; type ( v, u ) = TREE;
                status ( u ) = DISCOVERED; Q.push ( u );
            } else type ( v, u ) = CROSS;
        }
        status ( v ) = VISITED;
    }
}