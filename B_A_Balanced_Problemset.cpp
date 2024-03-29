#include <iostream>
#include <vector>

std::vector<int> generatePrimeFactors(int num) {
    std::vector<int> primeFactors;
    int divisor = 2;

    while (num > 1) {
        while (num % divisor == 0) {
            primeFactors.push_back(divisor);
            num /= divisor;
        }
        divisor++;
    }

    return primeFactors;
}

int main() {
    int num;
    while(num--){

    std::vector<int> primeFactors = generatePrimeFactors(num);

    for (int factor : primeFactors) {
        std::cout << factor << " ";
    }
    }



    return 0;
}
