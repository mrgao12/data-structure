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
    system("pause");
    return 0;
}