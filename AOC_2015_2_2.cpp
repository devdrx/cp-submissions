#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    std::ifstream file("input.txt");  
    std::string line;
    int tot = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
          string d1, d2, d3;
            int i = 0;
            for (i = 0; i < line.size(); i++)
            {
                if (line[i] == 'x'){
                    i++;
                    break;
                }
                else{
                    d1 += line[i];
                }
            }
            for (; i < line.size(); i++)
            {
                if (line[i] == 'x'){
                    i++;
                    break;
                }
                else{
                    d2 += line[i];
                }
            }
            for (; i < line.size(); i++)
            {
                d3 += line[i];
            }
            int l = stoi(d1), b = stoi(d2), h = stoi(d3);

            int mx = max(l, max(b, h));
            int ribbon1 = 2*l + 2*b + 2*h - 2*mx;
            int ribbon2 = l*b*h;
            tot += ribbon1 + ribbon2; 
           
        }
        file.close(); 
        cout << tot << endl;
    } else {
        std::cerr << "Unable to open the file" << std::endl;
    }

    return 0;
}