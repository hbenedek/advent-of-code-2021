#include <vector>
#include <stack>  
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

vector<string> readVector(string path);
int checkLine(string line);

int main()
{
    vector<string> vec = readVector("./inputs/advent10.txt");
    vector<int> results;

    for (int i = 0; i < vec.size(); i++)
    {
        results.push_back(checkLine(vec[i]));
    }
    cout << accumulate(results.begin(), results.end(), 0); 

    return 0;
}

vector<string> readVector(string path)
{
    vector<string> vec;
    ifstream file(path);
    string str; 

    while (getline(file, str))
    {
       vec.push_back(str);
    }
    return vec;
}

int checkLine(string line)
{
    stack<char> checker;
    map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
    map<char, int> closes = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};

    for (int i = 0; i < line.size(); i++)
    {
        if (checker.empty())
        {
            checker.push(line[i]);
        } 
        else
        {
            if (pairs[checker.top()] == line[i])
            {
                checker.pop();
            }
            else if (closes.count(line[i]) == 1)
            {
                return closes[line[i]]; 
            }
            else
            {
                checker.push(line[i]);
            }
            
        }
       
    }
    return 0;
}

