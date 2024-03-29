//A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
// Your task is to create a Gray code for a given length n.
#include <bits/stdc++.h>
using namespace std;

vector<string> init (vector<string> grey){
    grey.push_back("0");
    grey.push_back("1");
    return grey;
}

vector<string> doublyreverse (vector<string> grey)
{
    int n = grey.size();
    for (int i = n - 1; i >= 0; i--)
    {
        grey.push_back(grey[i]);
    }
    return grey;
}

vector<string> inserter (vector<string> grey)
{
    int n = grey.size();
    for (int i = 0; i < n/2; i++)
    {
        grey[i] = "0" + grey[i];
    }
    for (int i = n/2; i < n; i++)
    {
        grey[i] = "1" + grey[i];
    }
    return grey;
}

int main(){
    int n;
    cin >> n;
    vector<string> gray;
    gray = init(gray);


    for(int i = 0; i<n-1; i++){
        gray = doublyreverse(gray);
        gray = inserter(gray);
    }
    for (auto& str : gray) {
        cout << str << endl;
    }
    
    // ...


}

