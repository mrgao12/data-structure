#pragma once

template < typename Tv, typename Te >
void Graph< Tv, Te >::bcc ( int v ) {
    int clock = 0; int s = v;
    stack<int> S;
    do {
        if ( status ( v ) == UNDISCOVERED ) {
            BCC ( v, clock, S );
            S.pop();
        }
    } while ( s != ( v = ( ++v % n ) ) );
}

#define hca(x) (fTime(x))

template < typename Tv, typename Te >
void Graph< Tv, Te >::BCC ( int v, int& clock, stack<int>& S ) {
    dTime(v) = hca(v) = ++clock; status ( v ) = DISCOVERED; S.push ( v );
    for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) {
        switch ( status ( u ) ) {
            case UNDISCOVERED:
                type ( v, u ) = TREE; parent ( u ) = v;
                BCC ( u, clock, S );
                if ( hca(u) < dTime(v) ) hca(v) = min ( hca(v), hca(u) );
                else {
                    cout << vertex ( v ) << " ";
                    stack<int> temp;
                    while ( S.top() != v ) {
                        temp.push ( S.top() );
                        S.pop();
                    }
                    while ( ! temp.empty() ) {
                        cout << vertex ( temp.top() ) << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;
            case DISCOVERED:
                type( v, u ) = BACKWARD;
                if ( u != parent(v) ) hca (v) = min ( hca(v), dTime(u) );
                break;
            default:
                type( v, u ) = ( dTime(v) < dTime(u) ) ? FORWARD : CROSS;
        }
    }
    status(v) = VISITED;
}