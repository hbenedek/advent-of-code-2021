#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

vector<vector<int>> readVector(string path);
void printMatrix(vector<vector<int>> vec);
bool isLocalMin(vector<vector<int>> vec, int i, int j);

int main()
{
    //read input
    vector<vector<int>> vec = readVector("inputs/advent9.txt");
    vector<int> results;
    //printMatrix(vec);

    for (int i = 1; i < vec.size() - 1; i++)
    {
        for (int j = 1; j < vec[i].size() - 1; j++)
        {
            if (isLocalMin(vec, i, j))
            {
                results.push_back(vec[i][j] + 1);
            }
            
        }
        
    }
    cout << accumulate(results.begin(), results.end(), 0); 
    
    return 0;
}

vector<vector<int>> readVector(string path)
{
    vector<vector<int>> vec;
    vector<int> pad;
    ifstream file(path);
    string str; 
    bool flag = true;
    while (getline(file, str))
    {
        vector<int> row;
        row.push_back(9);
        for (int i = 0; i < str.size(); i++)
        {
            if (flag)
            {
                for (int j = 0; j < str.size() + 2; j++)
                {
                    pad.push_back(9);
                }
                vec.push_back(pad);
                flag = false;
            }
            
            int temp = str[i] - '0'; 
            row.push_back(temp);   
        }
        row.push_back(9);
        vec.push_back(row);
    }
    vec.push_back(pad);
    return vec;
}

void printMatrix(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j];
            }
            cout <<endl;
        }
}

bool isLocalMin(vector<vector<int>> vec, int i, int j)
{
    int target = vec[i][j];
    if (target < vec[i + 1][j] && target < vec[i - 1][j] && target < vec[i][j + 1] && target < vec[i][j - 1])
    {
        return true;
    }
    else
    {
        return false;
    }
}