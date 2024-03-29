#include<bits/stdc++.h>
using namespace std;

int sumInPowersofTen(int num, int a[]) 
{
	if (num < 10) return (num * (num + 1) / 2); 
	int digits = (int)(log10(num)); 
	int p = (int)(ceil(pow(10, digits))); 
	int mostsignificantdigit = num / p; 
	
	return (mostsignificantdigit * a[digits] + (mostsignificantdigit * (mostsignificantdigit - 1) / 2) * p + mostsignificantdigit * (1 + num % p) + sumInPowersofTen(num % p, a)); 
} 
int sumFunction(int number) 
{ 
	int digits = (int)(log10(number)); 
	int a[digits + 1]; 
	a[0] = 0; 
    a[1] = 45;
	
	for(int i = 2; i <= digits; i++) 
		a[i] = a[i - 1] * 10 + 45 * (int)(ceil(pow(10, i - 1))); 

	return sumInPowersofTen(number, a); 
}

int main() 
{   
    int t;
    cin >>t;
    while(t--){
	    int n;
        cin >> n;
	cout << sumFunction(n) <<endl; 
    }
} 
