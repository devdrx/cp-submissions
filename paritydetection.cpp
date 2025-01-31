#include <iostream>
#include <vector>
#include <string>

int calculateParity(const std::string& data) {
    int count = 0;
    for (char bit : data) {
        if (bit == '1') count++;
    }
    return count % 2;
}

bool detectParityError(const std::string& receivedData) {
    std::string dataWithoutParity = receivedData.substr(0, receivedData.size() - 1);
    int receivedParity = receivedData.back() - '0';
    int calculatedParity = calculateParity(dataWithoutParity);
    return receivedParity != calculatedParity;
}

int main() {
    std::string data;
    std::cout << "Enter binary data (without parity bit): ";
    std::cin >> data;

    int parityBit = calculateParity(data);
    std::cout << "Calculated parity bit: " << parityBit << std::endl;

    std::string transmittedData = data + std::to_string(parityBit);
    std::cout << "Transmitted data (with parity bit): " << transmittedData << std::endl;

    std::string receivedData;
    std::cout << "Enter received data (with parity bit): ";
    std::cin >> receivedData;

    if (detectParityError(receivedData)) {
        std::cout << "Error detected in the received data!" << std::endl;
    } else {
        std::cout << "No error detected in the received data." << std::endl;
    }

    return 0;
}
