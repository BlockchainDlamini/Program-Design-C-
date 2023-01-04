#include "matrix.h"

#include <iostream>

using namespace std;

int main() {

    Matrix m = Matrix(0, 0);
    m.displayMatrix();

    cout << endl;

    Matrix m2 = Matrix(6, 6);
    m2.displayMatrix();

    cout << endl;

    Matrix m3 = Matrix(3, 3);
    m3.setMatrix();
    m3.displayMatrix();

    cout << endl;

    m3.resizeRows(-1);
    m3.resizeColumns(-1);

    return 0;

}

/* Expected Output
1 1 1
1 1 1
1 1 1

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

1
2
3
4
5
6
7
8
9
1 2 3
4 5 6
7 8 9

Error: cannot have less than 1 row
Error: cannot have less than 1 column

 */