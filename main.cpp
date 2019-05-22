#include "inicio.h"
#include <QApplication>
#include<bits/stdc++.h>
#include "astar.h"

using namespace std;

typedef pair<int, int> Pair;//nodos
typedef pair<double, pair<int, int>> pPair; //lista
// Driver program to test above function


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Inicio w;
    w.show();

    return a.exec();
}
