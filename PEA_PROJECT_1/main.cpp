//
//  main.cpp
//  PEA_PROJECT_1
//
//  Created by Szymon Klimczuk on 20/10/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>

#include "Graph.hpp"

using namespace std;

void simulation(string filename);
void simulation(string filename, int cities);
vector<string> initVectorWithSimulationFiles();

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
            case 3:
            {
                string output_filename = "simulation_result.cpp";
//                simulation(output_filename,6);
//                simulation(output_filename,10);
//                simulation(output_filename,12);
//                simulation(output_filename,13);
//                simulation(output_filename,14);
//                simulation(output_filename,15);
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

void simulation(string filename)
{
    ofstream file;
    file.open(filename);
    
    Graph *graph;
    
    if(file.good() == true)
    {
        cout << "\nCORRECT OUTPUT FILE" << endl;
        vector<string> simulationFiles = initVectorWithSimulationFiles();
        
        file << "--------------------------------";
        file << "\nBEGIN OF SIMULATION" << endl;
        file << "--------------------------------" << endl;
        
        for(int i = 0; i < simulationFiles.size(); i++)
        {
            graph = new Graph(simulationFiles[i]);
            string output =  graph -> simulationTSP();
            file << output;
            graph -> ~Graph();
        }
        
        file << "--------------------------------";
        file << "\nEND OF SIMULATION" << endl;
        file << "--------------------------------" << endl;
        
        file.close();
    }
    else
        cout << "\nERROR WITH OUTPUT FILE" << endl;
    
}

void simulation(string filename, int cities)
{
    ofstream file;
    file.open(filename);
    
    Graph *graph;
    
    if(file.good() == true)
    {
        cout << "\nCORRECT OUTPUT FILE" << endl;
        vector<string> simulationFiles = initVectorWithSimulationFiles();
        
        file << "--------------------------------";
        file << "\nBEGIN OF SIMULATION" << endl;
        file << "--------------------------------" << endl;
        
//        for(int i = 0; i < 10; i++)
//        {
            graph = new Graph(cities);
            string output =  graph -> simulationTSP();
            file << output;
            graph -> ~Graph();
//        }
        
        file << "--------------------------------";
        file << "\nEND OF SIMULATION" << endl;
        file << "--------------------------------" << endl;
        
        file.close();
    }
    else
        cout << "\nERROR WITH OUTPUT FILE" << endl;
    
}

vector<string> initVectorWithSimulationFiles()
{
    vector<string> vector;
    vector.push_back("tsp_6_1.txt");
    vector.push_back("tsp_6_2.txt");
    vector.push_back("tsp_10.txt");
    vector.push_back("tsp_12.txt");
    vector.push_back("tsp_13.txt");
    vector.push_back("tsp_14.txt");
    vector.push_back("tsp_15.txt");
    
    return vector;
}
