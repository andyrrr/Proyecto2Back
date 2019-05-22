#ifndef ASTAR_H
#define ASTAR_H
#include<bits/stdc++.h>
#include "list.h"
#define ROW 12
#define COL 12

using namespace std;


typedef pair<int, int> Pair;//nodos
typedef pair<double, pair<int, int>> pPair; //listas



class AStar
{
public:
    lista *finalPath = new lista();//lista para la interfaz
    AStar();
    struct cell
    {

        int parent_i, parent_j;
        double f, g, h;
    };
    bool isValid(int row, int col);
    bool isUnBlocked(int grid[][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    void tracePath(cell cellDetails[][COL], Pair dest);
    void blockCell(int grid[][COL],int row, int col);
    void aStarSearch(int grid[][COL], Pair src, Pair dest);

};

#endif // ASTAR_H
