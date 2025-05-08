#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>
#include <algorithm>


using namespace std;

// Function to convert string IP to vector of ints
vector<int> parseIP(const string& ip) {
    vector<int> result;
    stringstream ss(ip);
    string token;
    while (getline(ss, token, '.')) {
        result.push_back(stoi(token));
    }
    return result;
}

// Function to convert vector of ints to binary string
string toBinary(const vector<int>& ip) {
    string binary = "";
    for (int octet : ip) {
        binary += bitset<8>(octet).to_string();
    }
    return binary;
}

// Function to get class of IP
char getIPClass(int firstOctet) {
    if (firstOctet >= 0 && firstOctet <= 127) return 'A';
    if (firstOctet >= 128 && firstOctet <= 191) return 'B';
    if (firstOctet >= 192 && firstOctet <= 223) return 'C';
    if (firstOctet >= 224 && firstOctet <= 239) return 'D';
    return 'E';
}

// Convert binary string to dotted decimal format
string binaryToDottedDecimal(const string& binary) {
    string dotted = "";
    for (int i = 0; i < 32; i += 8) {
        string byte = binary.substr(i, 8);
        dotted += to_string(stoi(byte, nullptr, 2));
        if (i < 24) dotted += ".";
    }
    return dotted;
}

// Function to calculate broadcast address
string getBroadcastAddress(const string& networkBinary, int subnetBits) {
    string broadcast = networkBinary.substr(0, subnetBits);
    broadcast += string(32 - subnetBits, '1');
    return broadcast;
}

int main() {
    string ipStr, netmaskStr, subnetmaskStr;
    cout << "Enter IP Address (e.g. 192.168.1.10): ";
    cin >> ipStr;
    cout << "Enter Network Mask (e.g. 255.255.255.0): ";
    cin >> netmaskStr;
    cout << "Enter Subnet Mask (e.g. 255.255.255.192): ";
    cin >> subnetmaskStr;

    vector<int> ip = parseIP(ipStr);
    vector<int> netmask = parseIP(netmaskStr);
    vector<int> subnetmask = parseIP(subnetmaskStr);

    string ipBinary = toBinary(ip);
    string netmaskBinary = toBinary(netmask);
    string subnetmaskBinary = toBinary(subnetmask);

    // Class
    char ipClass = getIPClass(ip[0]);

    // Network ID
    string networkIDBinary = "";
    for (int i = 0; i < 32; i++) {
        networkIDBinary += (ipBinary[i] == '1' && netmaskBinary[i] == '1') ? '1' : '0';
    }

    // Host ID
    string hostIDBinary = "";
    for (int i = 0; i < 32; i++) {
        hostIDBinary += (ipBinary[i] == '1' && netmaskBinary[i] == '0') ? '1' : '0';
    }

    // Subnet ID
    string subnetIDBinary = "";
    for (int i = 0; i < 32; i++) {
        subnetIDBinary += (ipBinary[i] == '1' && subnetmaskBinary[i] == '1') ? '1' : '0';
    }

    // Subnet bits
    int subnetBits = count(subnetmaskBinary.begin(), subnetmaskBinary.end(), '1');

    // Broadcast Address
    string broadcastBinary = getBroadcastAddress(subnetIDBinary, subnetBits);

    // Output
    cout << "\n===== IP Address Analysis =====\n";
    cout << "IP Class: " << ipClass << endl;
    cout << "Network ID: " << binaryToDottedDecimal(networkIDBinary) << endl;
    cout << "Host ID: " << binaryToDottedDecimal(hostIDBinary) << endl;
    cout << "Subnet ID: " << binaryToDottedDecimal(subnetIDBinary) << endl;
    cout << "Network Address: " << binaryToDottedDecimal(subnetIDBinary) << endl;
    cout << "Broadcast Address: " << binaryToDottedDecimal(broadcastBinary) << endl;

    return 0;
}
