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
void solve_10_1(vector<string> vec);
string isCorrupted(string line);
long long calculateScore(string correction);
string reverseStack(stack<char> checker);

int main()
{
    vector<string> vec = readVector("./inputs/advent10.txt");
    vector<long long> results;

    for (int i = 0; i < vec.size(); i++)
    {
        string correction = isCorrupted(vec[i]);
        if (correction != "")
        {
            results.push_back(calculateScore(correction));
        }
        
    }
    
    sort(results.begin(), results.end());
    long long m = (results.size()) / 2;
    cout << results[m]<<endl;

     

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

string isCorrupted(string line)
{
    stack<char> checker;
    map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
    map<char, int> closes = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};

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
                return ""; 
            }
            else
            {
                checker.push(line[i]);
            }
            
        }
       
    }    
    return reverseStack(checker);
}

string reverseStack(stack<char> checker)
{
    string result;
    map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
    while (!checker.empty())
    {
        string str(1, pairs[checker.top()]); 
        result.insert(0, str);
        checker.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}


void solve_10_1(vector<string> vec)
{
    vector<int> results;

    for (int i = 0; i < vec.size(); i++)
    {
        results.push_back(checkLine(vec[i]));
    }
    cout << accumulate(results.begin(), results.end(), 0); 
}

long long calculateScore(string correction)
{
    map<char, long long> scoreTable = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};
    long long score = 0;
    for (int i = 0; i < correction.size(); i++)
    {
        score = score * 5 + scoreTable[correction[i]];
    }
    return score;
    
}

