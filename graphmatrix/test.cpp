#include "graphmatrix.h"
#include <iostream>
using namespace std;

int main() {
    GraphMatrix<char, int>g;
    g.insert ( 'S' ); g.insert ( 'A' ); g.insert ( 'B' ); g.insert ( 'C' );
    g.insert ( 'D' ); g.insert ( 'E' ); g.insert ( 'F' ); g.insert ( 'G' );

    g.insert ( 0, 1, 0, 1 ); g.insert ( 0, 2, 0, 3 ); g.insert ( 0, 3, 0, 4 );
    g.insert ( 0, 4, 1, 3 ); g.insert ( 0, 5, 1, 5 );
    g.insert ( 0, 6, 3, 2 );
    g.insert ( 0, 7, 4, 2 );
    g.insert ( 0, 8, 5, 6 ); g.insert ( 0, 9, 5, 7 );
    g.insert ( 0, 10, 7, 6 ); g.insert ( 0, 11, 7, 2 );
    
    cout << "---------------------BFS---------------------" << endl;
    g.bfs(0);
    for ( int i = 0; i < g.n; i++ ) {
        cout << g.parent ( i ) << " ";
    }
    cout << endl << endl << endl;


    cout << "---------------------DFS---------------------" << endl;
    g.dfs(0);
    for ( int i = 0; i < g.n; i++ ) {
        cout << g.parent ( i ) << " ";
    }
    cout << endl << endl << endl;


    cout << "---------------------PRIM---------------------" << endl;
    g.prim(0);
    for ( int i = 0; i < g.n; i++ ) {
        cout << g.parent ( i ) << " ";
    }
    cout << endl << endl << endl;


    GraphMatrix<char, int>g2;
    g2.insert('A'); g2.insert('B'); g2.insert('C');
    g2.insert('D'); g2.insert('E'); g2.insert('F');

    g2.insert ( 0, 0, 0, 2 ); g2.insert ( 0, 0, 0, 3 );
    g2.insert ( 0, 0, 1, 2 );
    g2.insert ( 0, 0, 2, 3 ); g2.insert ( 0, 0, 2, 4 ); g2.insert ( 0, 0, 2, 5 );
    g2.insert ( 0, 0, 4, 5 );
    cout << "---------------------TSORT---------------------" << endl;
    stack<char>* S = g2.tsort(1);
    while ( ! S->empty() ) {
        cout << S->top() << " ";
        S->pop();
    }
    cout << endl << endl << endl;

    cout << "---------------------DIJKSTRA---------------------" << endl;
    GraphMatrix<char, int>g3;
    g3.insert ( 'S' ); g3.insert ( 'A' ); g3.insert ( 'B' ); g3.insert ( 'C' );
    g3.insert ( 'D' ); g3.insert ( 'E' ); g3.insert ( 'F' ); g3.insert ( 'G' );
    g3.insert ( 'H' );

    g3.insert ( 0, 4, 0, 1 ); g3.insert ( 0, 6, 0, 3 ); g3.insert ( 0, 7, 0, 6 );
    g3.insert ( 0, 4, 1, 0 ); g3.insert ( 0, 12, 1, 2 );
    g3.insert ( 0, 12, 2, 1 ); g3.insert ( 0, 9, 2, 3 ); g3.insert ( 0, 1, 2, 4 ); g3.insert ( 0, 2, 2, 5 ); g3.insert ( 0, 10, 2, 7 );
    g3.insert ( 0, 6, 3, 0 ); g3.insert ( 0, 9, 3, 2 ); g3.insert ( 0, 13, 3, 4 ); g3.insert ( 0, 2, 3, 6 );
    g3.insert ( 0, 1, 4, 2 ); g3.insert ( 0, 13, 4, 3 ); g3.insert ( 0, 5, 4, 5 ); g3.insert ( 0, 11, 4, 6 ); g3.insert ( 0, 8, 4, 7 );
    g3.insert ( 0, 2, 5, 2 ); g3.insert ( 0, 5, 5, 4 ); g3.insert ( 0, 7, 5, 7 );
    g3.insert ( 0, 2, 6, 3 ); g3.insert ( 0, 11, 6, 4 ); g3.insert ( 0, 14, 6, 7 );
    g3.insert ( 0, 10, 7, 2 ); g3.insert ( 0, 8, 7, 4 ); g3.insert ( 0, 7, 7, 5 ); g3.insert ( 0, 14, 7, 6 );
    g3.dijkstra( 0 );
    int parent = 4;
    while ( parent != 0 ) {
        parent = g3.parent ( parent );
        cout << parent << " ";
    }
    cout << endl << endl;


    cout << "---------------------BCC---------------------" << endl;
    GraphMatrix<char, int>g4;
    g4.insert ( 'A' ); g4.insert ( 'B' ); g4.insert ( 'C' );
    g4.insert ( 'D' ); g4.insert ( 'E' ); g4.insert ( 'F' ); g4.insert ( 'G' );
    g4.insert ( 'H' ); g4.insert ( 'I' ); g4.insert ( 'J' );

    g4.insert ( 0, 0, 0, 1 ); g4.insert ( 0, 0, 0, 7 ); g4.insert ( 0, 0, 0, 8 ); g4.insert ( 0, 0, 0, 9 );
    g4.insert ( 0, 0, 1, 0 ); g4.insert ( 0, 0, 1, 2 );
    g4.insert ( 0, 0, 2, 1 ); g4.insert ( 0, 0, 2, 3 ); g4.insert ( 0, 0, 2, 7 );
    g4.insert ( 0, 0, 3, 2 ); g4.insert ( 0, 0, 3, 4 ); g4.insert ( 0, 0, 3, 6 );
    g4.insert ( 0, 0, 4, 3 ); g4.insert ( 0, 0, 4, 6 );
    g4.insert ( 0, 0, 5, 6 );
    g4.insert ( 0, 0, 6, 3 ); g4.insert ( 0, 0, 6, 4 ); g4.insert ( 0, 0, 6, 5 );
    g4.insert ( 0, 0, 7, 0 ); g4.insert ( 0, 0, 7, 2 );
    g4.insert ( 0, 0, 8, 0 ); g4.insert ( 0, 0, 8, 9 );
    g4.insert ( 0, 0, 9, 0 ); g4.insert ( 0, 0, 9, 8 );
    g4.bcc ( 0 );
    system("pause");
    return 0;
}