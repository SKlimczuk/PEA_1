//
//  Graph.cpp
//  PEA_PROJECT_1
//
//  Created by Szymon Klimczuk on 20/10/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Graph.hpp"

//prototypes of methods used only in this class
int** initializeMatrix(int **matrix, int limit);

Graph::Graph(string filename)
{
    ifstream file;
    file.open(filename.c_str());
    
    if(!file.good())
        cout << "INCORRECT FILE !" << endl;
    else
    {
        cout << "CORRECT FILE !" << endl;
        
        file >> this->cities;
        
        adjMatrix = new int*[cities];
        adjMatrix = initializeMatrix(adjMatrix, cities);
        
        int weight;
        for(int i = 0; i < cities; i++){
            for(int k = 0; k < cities; k++){
                file >> weight;
                adjMatrix[i][k] = weight;
            }
        }
        
        cout << "\nCITIES:" << cities << endl;
    }
}


int** initializeMatrix(int **matrix, int limit)
{
    for(int i = 0; i < limit; i++){
        matrix[i] = new int[limit];
        for(int k = 0; k < limit; k++)
            matrix[i][k] = 0;
    }
    
    return matrix;
}


