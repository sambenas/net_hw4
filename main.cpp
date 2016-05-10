/* 
 * File:   main.cpp
 * Author: samb
 *
 * Created on May 10, 2016, 4:03 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


int main(int argc, char** argv) {

    unsigned int num_vertex = 0;
    long last_vertex = -1;
    
    
    string line;
    ifstream input_file("input.txt");
    if(input_file.is_open() ){
        while( getline(input_file, line) ){
            if (isdigit(line[0])){
                
                int delim_pos = line.find("$", 0);
                string num = line.substr(0, delim_pos);
                
                if ( strtol(num.c_str(), NULL, 10) != last_vertex){
                    last_vertex = strtol(num.c_str(), NULL, 10);
                    num_vertex++;
                }
                    
            }
        }
    }
    
    cout << "There are " << num_vertex << " vertices" << endl;
  
    input_file.close();
    
    int matrix[num_vertex][num_vertex];
    for(int i = 0; i < num_vertex; i++){
        for(int j = 0; j < num_vertex; j++){
            matrix[i][j] = 0;
        }
    }
    
    
        
    
    input_file.open("input.txt", fstream::in);
    if(input_file.is_open() ){
        while( getline(input_file, line) ){
            if (isdigit(line[0])){
                
                int v1, v2, w;
                int delim_pos = line.find("$", 0);
                string num = line.substr(0, delim_pos);
                v1 = strtol(num.c_str(), NULL, 10);
                int prev_delim = delim_pos+1;
                delim_pos = line.find("$", delim_pos+1);
                num = line.substr(prev_delim, delim_pos);
                v2 = strtol(num.c_str(), NULL, 10);                
                prev_delim = delim_pos+1;
                num = line.substr(prev_delim, line.length());
                w = strtol(num.c_str(), NULL, 10);
                matrix[v1-1][v2-1] = w;
                
                
            }
                    
        }
    }
    
    cout << endl << "Adjacency matrix:" << endl;
    cout << "  1 2 3 4 5" << endl;
    for(int i = 0; i < num_vertex; i++){
        cout << i+1 << " ";
        for(int j = 0; j < num_vertex; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        
    
    


    input_file.close();
    
    return 0;
}

