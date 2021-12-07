#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> readVector(string path);
int computeError(vector<int>& vec, int target);
int computeError2(vector<int>& vec, int target);

//loss function for part 1 (one observation): e(x-y) = abs(x-y), we can find the MLE by deriving wrt y. This yields the meadian of our observations.
//loss function for part 2 (one observation): e(x-y) = sum_{i=0}^x(i) = 1/2*(x*(x+1)), we are looking for the MLE, which is: mean/N +1/2, where N is the number of observations.

int main(){

    vector<int> vec = readVector("inputs/advent7.txt");
    sort(vec.begin(), vec.end());
    //int median = vec.at(vec.size() / 2);
    int estimator = (accumulate(vec.begin(), vec.end(), 0) / vec.size() + 0.5);
    int error1 = computeError2(vec, estimator); //the estimator is an integer in our case, but if it wasn't we should check its neigbours
    cout << error1 << endl;

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

int computeError(vector<int>& vec, int target)
{
    int error = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        error = error + (abs(vec[i] - target));
    }
    return error;
}

int computeError2(vector<int>& vec, int target)
{
    double error = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        double x = abs(vec[i] - target);
        double increment = 0.5 * x * (x + 1);
        cout << increment <<endl;
        error = error + increment;
    }
    return error;
}