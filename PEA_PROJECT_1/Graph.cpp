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
        
        file.close();
        
        cout << "\nCITIES:" << cities << endl;
    }
}

Graph::Graph(int cities)
{
    this -> cities = cities;
    adjMatrix = new int*[cities];
    adjMatrix = initializeMatrix(adjMatrix, cities);
    
    for(int i = 0; i < cities; i++){
        for(int k = 0; k < cities; k++){
            if(i == k)
                adjMatrix[i][k] = 0;
            else
                adjMatrix[i][k] = rand()%100;
        }
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
    
    iterationsCounter = 0;
    
    auto start = chrono::system_clock::now();
    tspAlgorithm(cityNum);
    auto stop = chrono::system_clock::now();
    
    displayTspResult(resultArr, counter, minWeight);
    
    chrono::duration<double, milli> elapsed_miliseconds = stop-start;
    cout << "TIME : " << elapsed_miliseconds.count() << " [ms]" << endl;
    cout << "ITERATIONS : " << iterationsCounter << endl;
    
    delete[] resultArr;
    delete[] tempResultArr;
    delete[] visitedCitiesArr;
}

string Graph::simulationTSP()
{
    resultArr = new int[cities];
    tempResultArr = new int[cities];
    visitedCitiesArr = new bool[cities];
    
    minWeight = INT_MAX;
    startCityNum = 0;
    
    tempWeight = 0;
    counter = 0;
    tempCounter = 0;
    
    auto start = chrono::system_clock::now();
    tspAlgorithm(0);
    auto stop = chrono::system_clock::now();
    
    chrono::duration<double, milli> elapsed_miliseconds = stop-start;
    ostringstream outputTSPResult;
    outputTSPResult << "CITIES : " << cities << "\nTIME: " << elapsed_miliseconds.count() << " [ms]\n";
    
    delete[] resultArr;
    delete[] tempResultArr;
    delete[] visitedCitiesArr;
    
    string simulationResult = outputTSPResult.str();
    return simulationResult;
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
        iterationsCounter++;
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
