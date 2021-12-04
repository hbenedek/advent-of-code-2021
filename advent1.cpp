#include<iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<int> readVector(string path)
{
    vector<int> vec;
    ifstream file(path);
    string str; 
    while (getline(file, str))
    {
        int num = stoi(str);
        vec.push_back(num);
    }
    return vec;
}

int countIncrease(vector<int> vec)
{
    int counter = 0;
    for (int i = 1; i < 2000; i++)
    {
        if (vec[i] > vec[i-1])
        {
            counter++;
        } 
    }
    return counter;
}

int main(){
    //read input
    vector<int> vec = readVector("inputs/advent1.txt");

    //part 1
    cout << countIncrease(vec) << endl;

    //part2
    int counter = 0;
    vector<int> window;
    for (int i = 0; i < 1998; i++){
        window.push_back(vec[i] + vec[i+1] + vec[i+2]);
    }

    cout << countIncrease(window) << endl;
    return 0;
}

