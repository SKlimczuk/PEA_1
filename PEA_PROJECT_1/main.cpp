//
//  main.cpp
//  PEA_PROJECT_1
//
//  Created by Szymon Klimczuk on 20/10/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>

#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string MAIN_MENU = "\n-----MENU-----\n1-read data from file\n2-TSP alghoritm\n0-exit\nCHOICE: ";
    string FILE_MENU = "\ninsert file name: ";
    string TSP_MENU = "\ninsert start city number: ";
    string TSP_FAIL = "\ngraph is not initialized !\n";
    int choice;
    
    bool menuFlowCondition = true;
    
    Graph *graph;
    
   
    do {
        
        do {
            cout << MAIN_MENU;
            cin >> choice;
        } while(0 > choice || choice > 3 );
            
        switch (choice) {
            case 1:
            {
                //read data from file
                string filename;
                cout << FILE_MENU;
                cin >> filename;
                graph = new Graph(filename);
            } break;
            case 2:
            {
                //begin TSP alghoritm
                if(graph)
                {
                    int cityNum;
                    do {
                        cout << TSP_MENU;
                        cin >> cityNum;
                    } while (cityNum < 0);
                    graph -> travellingSalesmanProblem(cityNum);
                }
                else
                    cout << TSP_FAIL;
            } break;
            case 0:
            {
                //exit
                if(graph)
                    graph -> ~Graph();
                 menuFlowCondition = false;
            } break;
            default:
                break;
        }
    } while(menuFlowCondition);
    
    return 0;
}
