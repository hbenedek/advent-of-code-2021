#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;


vector<string> readVector(string path);
string splitLine_end(string line);
string splitLine_begin(string line);
bool findElement(int array[4], int element);
void countUnique(string words, int& counter);
void find_0(string words);
void find_1(string words);
void find_2(string words);
void find_3(string words);
void find_4(string words);
void find_5(string words);
void find_6(string words);
void find_7(string words);
void find_8(string words);
void find_9(string words);

int main(){
    vector<string> vec = readVector("inputs/advent8.txt");

    vector<int> results;
    int counter = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        map<string, int> decoder;
        string end = splitLine_end(vec[i]);
        string begin = splitLine_end(vec[i]);
        find_0(begin);
        find_1(begin);
        find_2(begin);
        find_3(begin);
        find_4(begin);
        find_5(begin);
        find_6(begin);
        find_7(begin);
        find_8(begin);
        find_9(begin);
        int signal = decodeSignal(end, decoder);

        results.push_back(signal)
        //countUnique(end, counter);

    }
    cout << counter;
    
    return 0;
}

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

string splitLine_end(string line)
{
    string delimiter = " | ";
    string token2 = line.erase(0, line.find(delimiter) + delimiter.length());
    return token2;
}

string splitLine_begin(string line)
{
    string delimiter = " | ";
    string token = line.substr(0, line.find(delimiter)); 
    return token;
}

bool findElement(int array[4], int element)
{
    for(int i = 0; i < 4; i++){
        if(array[i] == element)
        {
            return true;
        }
    }
    return false;
}

void countUnique(string words, int& counter)
{
    string buf;                
    stringstream ss(words);  
    vector<string> tokens; // Create vector to hold our words
    int unique[4] = {2, 3, 4, 7};
    while (ss >> buf)
        {   
            //tokens.push_back(buf);
            for(int i = 0; i < 4; i++)
            {
                if(unique[i] == buf.size())
                {
                    counter = counter + 1;
                }
            }
        }
}