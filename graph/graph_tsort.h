#pragma once

template < typename Tv, typename Te >
stack<Tv>* Graph< Tv, Te >::tsort ( int v ) {
    int s = v, clock = 0;
    stack< Tv >* S = new stack< Tv >;
    do {
        if ( status ( v ) == UNDISCOVERED ) {
            if ( ! TSort ( v, clock, S ) ) {
                while ( ! S->empty() ) {
                    S->pop(); break;
                }
            }
        }
    } while ( s != ( v = ( ++v % n ) ) );
    return S;
}

template < typename Tv, typename Te >
bool Graph< Tv, Te >::TSort ( int v, int& clock, stack< Tv >* S ) {
    status ( v ) = DISCOVERED; dTime ( v ) = ++clock; 

    for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) {
        switch ( status ( u ) ) {
        case UNDISCOVERED:
            parent ( u ) = v; type ( v, u ) = TREE;
            if ( ! TSort ( u, clock, S ) ) return false;
            break;
        case DISCOVERED:
            type ( v, u ) = BACKWARD;
            return false;
        default:
            type ( v, u ) = ( dTime ( v ) < dTime ( u ) ) ? FORWARD : CROSS;
            break;
        }
    }
    status ( v ) = VISITED; S.push_back ( vertex( v ) );
    return true;
}