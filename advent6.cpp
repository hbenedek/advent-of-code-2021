#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;


vector<int> readVector(string path);
void evolve(vector<int>& vec);
map<int,long long int> vecToMap(vector<int> vec);
void evolveMap(map<int,long long int>& fishMap);
void sumFish(map<int, long long int>& fishMap);
void printResults(vector<int> vec, int i);


int main()
{
    vector<int> vec = readVector("inputs/advent6.txt");
    map<int,long long int> fishMap = vecToMap(vec);
    int days = 256;

    for (int i = 0; i < days; i++)
    {

        evolveMap(fishMap);
        //printResults(vec, i)
        
    }

    sumFish(fishMap);
    
    return 0;
}


vector<int> readVector(string path)
{
    vector<int> vect;
    ifstream file(path);
    string str;
    getline(file, str);
    stringstream ss(str);

    for (int i; ss >> i;) 
    {
        vect.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}


map<int,long long int> vecToMap(vector<int> vec)
{
    map<int,long long int> fishMap;
    for (int i = 0; i < 9; i++)
    {
        fishMap[i] = 0;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        fishMap[vec[i]] = fishMap[vec[i]] + 1;
    }
    return fishMap;
    
}

void evolveMap(map<int,long long int>& fishMap){
    long long int newFish = fishMap[0];
    for (int i = 0; i < 8; i++)
    {
        fishMap[i] = fishMap[i+1];
    }
    fishMap[6] = fishMap[6] + newFish;
    fishMap[8] = newFish;
}

void sumFish(map<int,long long int>& fishMap){
    long long int result = 0;
    for (int i = 0; i < 9; i++)
    {
        result = result + fishMap[i];
    }
    cout << result;
}

void evolve(vector<int>& vec)
{
    vector<int> newFish;
    for (int i = 0; i < vec.size(); i++)
    {   
        if (vec[i] == 0){
            newFish.push_back(8);
            vec[i] = 6;
        }
        else{
            vec[i] = vec[i] - 1;
        }      
    }
    vec.insert(vec.end(), newFish.begin(), newFish.end());
}

void printResults(vector<int> vec, int i){
    cout << "generation " << i << " size "<< vec.size()<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout <<endl;
}