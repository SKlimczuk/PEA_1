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
void displayTspResult(int *resultArr, int counter, int totalWeight);

Graph::Graph(string filename)
{
    ifstream file;
    file.open(filename.c_str());
    
    if(!file.good())
        cout << endl << "INCORRECT FILE !" << endl;
    else
    {
        cout << endl << "CORRECT FILE !" << endl;
        
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

Graph::~Graph()
{
    for(int i = 0; i < cities; i++)
    {
        delete[] adjMatrix[i];
    }
    
    delete[] adjMatrix;
}

void Graph::travellingSalesmanProblem(int cityNum)
{
    resultArr = new int[cities];
    tempResultArr = new int[cities];
    visitedCitiesArr = new bool[cities];

    minWeight = INT_MAX;
    startCityNum = cityNum;
    
    tempWeight = 0;
    counter = 0;
    tempCounter = 0;
    
    tspAlgorithm(cityNum);
    
    displayTspResult(resultArr, counter, minWeight);
    
    delete[] resultArr;
    delete[] tempResultArr;
    delete[] visitedCitiesArr;
}

void Graph::tspAlgorithm(int cityNum)
{
    tempResultArr[tempCounter++] = cityNum;
    
    if(tempCounter < cities)
    {
        visitedCitiesArr[cityNum] = true;
        for(int i = 0; i < cities; i++)
        {
            if(adjMatrix[cityNum][i] > 0 && !visitedCitiesArr[i])
            {
                tempWeight += adjMatrix[cityNum][i];
                tspAlgorithm(i);
                tempWeight -= adjMatrix[cityNum][i];
            }
        }
        visitedCitiesArr[cityNum] = false;
    }
    else if(adjMatrix[startCityNum][cityNum] != 0)
    {
        tempWeight += adjMatrix[cityNum][startCityNum];
        if(tempWeight < minWeight)
        {
            minWeight = tempWeight;
            for(int i = 0; i < tempCounter; i++)
                resultArr[i] = tempResultArr[i];
            counter = tempCounter;
        }
        tempWeight -= adjMatrix[cityNum][startCityNum];
    }
    tempCounter--;
}

//----------------------------------------------class methods
int** initializeMatrix(int **matrix, int limit)
{
    for(int i = 0; i < limit; i++){
        matrix[i] = new int[limit];
        for(int k = 0; k < limit; k++)
            matrix[i][k] = 0;
    }
    
    return matrix;
}

void displayTspResult(int *resultArr, int counter, int totalWeight)
{
    if(counter)
    {
        for(int i = 0; i < counter; i++)
            cout << resultArr[i] << " ";
        cout << resultArr[0] << endl;
        cout << "WEIGHT = " << totalWeight << endl;
    }
    else
        cout << "\nERROR" << endl;
}
