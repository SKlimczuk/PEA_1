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

using namespace std;

class Graph {
    
private:
    int cities;
    int **adjMatrix;
    
public:
    Graph(string filename);
    void travellingSalesmanProblem();
};


#endif /* TSP_hpp */
