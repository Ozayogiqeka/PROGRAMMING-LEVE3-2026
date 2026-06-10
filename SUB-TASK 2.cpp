#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
string decToBin(int dec);
int binToDec(string bin);
string decToHex(int dec);
int hexToDec(string hex);
void showMenu();

int main() {
    int choice;
    int decNum;
    string binStr, hexStr;

    srand(time(0)); // for random numbers in Demo

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter decimal number: ";
            cin >> decNum;
            cout << "Binary: " << decToBin(decNum) << "\n\n";
        }
        else if (choice == 2) {
            cout << "Enter binary number: ";
            cin >> binStr;
            cout << "Decimal: " << binToDec(binStr) << "\n\n";
        }
        else if (choice == 3) {
            cout << "Enter decimal number: ";
            cin >> decNum;
            cout << "Hexadecimal: " << decToHex(decNum) << "\n\n";
        }
        else if (choice == 4) {
            cout << "Enter hexadecimal number: ";
            cin >> hexStr;
            cout << "Decimal: " << hexToDec(hexStr) << "\n\n";
        }
        else if (choice == 5) {
            cout << "Demo: 5 random numbers to binary\n";
            for (int i = 0; i < 5; i++) {
                int randNum = rand() % 100 + 1;
                cout << randNum << " -> " << decToBin(randNum) << endl;
            }
            cout << "\n";
        }
        else if (choice == 6) {
            cout << "Exiting program...";
        }
        else {
            cout << "INVALID choice\n";
        }

    } while (choice!= 6);

    return 0;
}

// Function 1: Decimal to Binary
string decToBin(int dec) {
    if (dec == 0) return "0";
    string bin = "";
    while (dec > 0) {
        bin = to_string(dec % 2) + bin;
        dec = dec / 2;
    }
    return bin;
}

// Function 2: Binary to Decimal
int binToDec(string bin) {
    int dec = 0;
    int power = 1;
    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += power;
        }
        power *= 2;
    }
    return dec;
}

// Function 3: Decimal to Hexadecimal
string decToHex(int dec) {
    if (dec == 0) return "0";
    string hex = "";
    char digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (dec > 0) {
        hex = digits[dec % 16] + hex;
        dec = dec / 16;
    }
    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexToDec(string hex) {
    int dec = 0;
    int power = 1;
    for (int i = hex.length() - 1; i >= 0; i--) {
        char c = hex[i];
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        }
        dec += value * power;
        power *= 16;
    }
    return dec;
}

// Menu function
void showMenu() {
    cout << "****************************\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Convert Binary to Decimal\n";
    cout << "3. Convert Decimal to Hexadecimal\n";
    cout << "4. Convert Hexadecimal to Decimal\n";
    cout << "5. Demo - Random to Binary\n";
    cout << "6. Exit\n";
    cout << "****************************\n";
}
