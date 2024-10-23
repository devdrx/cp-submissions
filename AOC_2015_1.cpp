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

            int area1 = 2*l*b + 2*b*h + 2*h*l;
            int area2 = min(l*b, min(b*h, h*l));
            tot += area1 + area2;
        }
        file.close(); 
        cout << tot << endl;
    } else {
        std::cerr << "Unable to open the file" << std::endl;
    }

    return 0;
}