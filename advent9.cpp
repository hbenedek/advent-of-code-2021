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
void  solve_91(vector<vector<int>> vec);
void solve_92(vector<vector<int>> vec);
int getBasin(int i, int j, vector<vector<int>>& isBasin, vector<vector<int>>& vec);

int main()
{
    //read input
    vector<vector<int>> vec = readVector("inputs/advent9.txt");
    //printMatrix(vec);
    //solve_91(vec);
    solve_92(vec);
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

void solve_91(vector<vector<int>> vec)
{
    vector<int> results;
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
}

int getBasin(int i, int j, vector<vector<int>>& isBasin, vector<vector<int>>& vec)
{
    int currentSize = 0;
    vector<tuple<int,int>> notProcessed;
    notProcessed.push_back({i, j});
  
    while (notProcessed.size() > 0)
    {

        tuple<int,int> temp = notProcessed[0];
        int i = get<0>(temp);
        int j = get<1>(temp);
        notProcessed.erase(notProcessed.begin());
        if (isBasin[i][j] == 0)
        {    
            isBasin[i][j] = 1;
            currentSize = currentSize + 1;

            if (vec[i + 1][j] != 9 && isBasin[i + 1][j] == 0)
            {
                notProcessed.push_back({i + 1, j});
            }
            if (vec[i - 1][j] != 9 && isBasin[i - 1][j] == 0)
            {
                notProcessed.push_back({i - 1, j});
            }
            if (vec[i][j - 1] != 9 && isBasin[i][j - 1] == 0)
            {
                notProcessed.push_back({i, j - 1});
            }
            if (vec[i][j + 1] != 9 && isBasin[i][j + 1] == 0)
            {
                notProcessed.push_back({i, j + 1});
            }    
        }
    }
    return currentSize;
}

void solve_92(vector<vector<int>> vec)
{
    vector<int> allBasin;
    vector<vector<int> > isBasin(vec.size(),vector<int>(vec[0].size(), 0));
    
    for (int i = 1; i < vec.size() - 1; i++)
    {
        for (int j = 1; j < vec[i].size() - 1; j++)
        {
            if (isBasin[i][j] == 0 && vec[i][j] != 9)
            {
                allBasin.push_back(getBasin(i, j, isBasin, vec));
            }
        }
        
    }
    sort(allBasin.rbegin(), allBasin.rend());

    int result = allBasin[0] * allBasin[1] * allBasin[2];
    cout << result;
}