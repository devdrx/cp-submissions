#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate the number of parity bits needed
int calculateParityBits(int m) {
    int r = 0;
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }
    return r;
}

// Function to insert parity bits into the data
vector<int> insertParityBits(vector<int>& data, int m, int r) {
    vector<int> hammingCode(m + r + 1, 0);
    int j = 0;

    for (int i = 1; i <= m + r; i++) {
        if ((i & (i - 1)) == 0) { // Check if the position is a power of 2
            hammingCode[i] = 0;  // Placeholder for parity bit
        } else {
            hammingCode[i] = data[j++];
        }
    }
    return hammingCode;
}

// Function to calculate the parity bits
void calculateParity(vector<int>& hammingCode, int m, int r) {
    for (int i = 0; i < r; i++) {
        int parityPos = pow(2, i);
        int count = 0;

        for (int j = 1; j < hammingCode.size(); j++) {
            if (j & parityPos) {
                count += hammingCode[j];
            }
        }
        hammingCode[parityPos] = count % 2;
    }
}

// Function to detect and correct errors
int detectAndCorrectError(vector<int>& hammingCode) {
    int errorPos = 0;
    int n = hammingCode.size();

    for (int i = 0; pow(2, i) < n; i++) {
        int parityPos = pow(2, i);
        int count = 0;

        for (int j = 1; j < n; j++) {
            if (j & parityPos) {
                count += hammingCode[j];
            }
        }
        if (count % 2 != 0) {
            errorPos += parityPos;
        }
    }

    return errorPos;
}

int main() {
    int m;
    cout << "Enter the number of data bits: ";
    cin >> m;

    vector<int> data(m);
    cout << "Enter the data bits (space-separated): ";
    for (int i = 0; i < m; i++) {
        cin >> data[i];
    }

    int r = calculateParityBits(m);
    cout << "Number of parity bits needed: " << r << endl;

    vector<int> hammingCode = insertParityBits(data, m, r);
    calculateParity(hammingCode, m, r);

    cout << "Hamming Code (with parity bits): ";
    for (int i = 1; i < hammingCode.size(); i++) {
        cout << hammingCode[i] << " ";
    }
    cout << endl;

    // Introduce an error for demonstration
    cout << "Enter position to introduce an error (1-based, or 0 for no error): ";
    int errorPos;
    cin >> errorPos;

    if (errorPos > 0 && errorPos < hammingCode.size()) {
        hammingCode[errorPos] ^= 1; // Flip the bit
        cout << "Hamming Code with error introduced: ";
        for (int i = 1; i < hammingCode.size(); i++) {
            cout << hammingCode[i] << " ";
        }
        cout << endl;
    }

    int detectedError = detectAndCorrectError(hammingCode);

    if (detectedError == 0) {
        cout << "No error detected." << endl;
    } else {
        cout << "Error detected at position: " << detectedError << endl;
        hammingCode[detectedError] ^= 1; // Correct the error
        cout << "Corrected Hamming Code: ";
        for (int i = 1; i < hammingCode.size(); i++) {
            cout << hammingCode[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
