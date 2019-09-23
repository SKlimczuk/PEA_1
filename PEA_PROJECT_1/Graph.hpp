//
//  Graph.hpp
//  PEA_PROJECT_1
//
//  Created by Szymon Klimczuk on 20/10/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <sstream>

using namespace std;

class Graph {
    
private:
    //number of cities/vertexes
    int cities;
    
    //graph representation as adjency matrix
    int **adjMatrix;
    
    //arrays used in tsp algorithm
    int *resultArr;
    int *tempResultArr;
    bool *visitedCitiesArr;
    
    //variables used in tsp alghrithm
    int startCityNum;
    int minWeight;
    int tempWeight;
    int counter;
    int tempCounter;
    
    int iterationsCounter;
    
    void tspAlgorithm(int city);
    
public:
    Graph(string filename);
    Graph(int cities);
    ~Graph();
    void travellingSalesmanProblem();
    string simulationTSP();
};

#endif /* TSP_hpp */
