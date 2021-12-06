#include<iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<string> readVector(string path)
{
    vector<string> vec;
    ifstream file(path);
    string str; 
    while (getline(file, str))
    {
        //int num = stoi(str);
        vec.push_back(str);
    }
    return vec;
}


vector<int> parseString(string line){
    string delimiter = " -> ";
    string token1 = line.substr(0, line.find(delimiter)); 
    string token2 = line.erase(0, line.find(delimiter) + delimiter.length());

    delimiter = ",";
    int x1 = stoi(token1.substr(0, token1.find(delimiter)));
    int y1 = stoi(token1.erase(0, token1.find(delimiter) + delimiter.length()));
    int x2 = stoi(token2.substr(0, token2.find(delimiter)));
    int y2 = stoi(token2.erase(0, token2.find(delimiter) + delimiter.length()));
    vector<int> coord = {x1, y1, x2, y2};
    return coord;
}

void updateTable(vector<vector<int>>& table, int x1, int y1, int x2, int y2){
    if (x1 == x2)
    {
        if (y2 <= y1)
        {
            int tempy = y1;
            y1 = y2;
            y2 = tempy;
        }
        
        for (int i = y1; i < y2 + 1; i++)
        {
            table[i][x1] = table[i][x1] + 1;
        }
        
    }
    if (y1 == y2)
    {
        if (x2 <= x1)
        {
            int tempx = x1;
            x1 = x2;
            x2 = tempx;
        }
        
       for (int i = x1; i < x2 + 1; i++)
       {
           table[y1][i] = table[y1][i] + 1;
       }
        
    } 
}

void printTable(vector<vector<int>> table){
    for (int i = 0; i < table.size(); ++i){
        for (int j = 0; j < table[i].size(); ++j){
            cout << table[i][j];
        }
        cout << endl;
    }
    
}

int countCovers(vector<vector<int>> table){
    int counter = 0;
    for (int i = 0; i < table.size(); ++i){
        for (int j = 0; j < table[i].size(); ++j){
            if (table[i][j] > 1)
            {
                counter = counter + 1;
            } 
        }
    }
    return counter;
}

int main(){
    vector<vector<int>> table;
    table.resize(1000, vector<int>(1000, 0));

    vector<string> vec = readVector("inputs/advent5.txt");
    
    for (int i = 0; i < vec.size(); i++)
    {
        vector<int> coord = parseString(vec[i]);
        updateTable(table, coord[0], coord[1], coord[2], coord[3]);
    }
    
    int result = countCovers(table);
    //printTable(table);
    cout << result;
}