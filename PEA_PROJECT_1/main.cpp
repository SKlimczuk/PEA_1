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
    
    string MAIN_MENU = "\nMENU\n1-read data from file\n2-TSP alghoritm\n0-exit\nCHOICE: ";
    string FILE_MENU = "\ninsert file name: ";
    int choice;
    
    bool menuFlowCondition = true;
    
    Graph *graph;
    
   
    do {
        cout << MAIN_MENU;
        cin >> choice;
        
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
            } break;
            case 0:
            {
                //exit
                menuFlowCondition = false;
            } break;
            default:
                break;
        }
    } while(menuFlowCondition);
    
    return 0;
}
