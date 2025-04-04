/* File Encryption and Decryption Tool */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt a file
void encryptFile(const string &filename, int key) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    string encryptedFilename = filename + ".enc";
    ofstream outputFile(encryptedFilename, ios::binary);
    if (!outputFile) {
        cerr << "Error: Unable to create encrypted file!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        ch += key;  // Shift the character by the key
        outputFile.put(ch);
    }

    cout << "File encrypted successfully to: " << encryptedFilename << endl;

    inputFile.close();
    outputFile.close();
}

// Function to decrypt a file
void decryptFile(const string &filename, int key) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    string decryptedFilename = filename.substr(0, filename.find(".enc"));
    ofstream outputFile(decryptedFilename, ios::binary);
    if (!outputFile) {
        cerr << "Error: Unable to create decrypted file!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        ch -= key;  // Reverse the shift by the key
        outputFile.put(ch);
    }

    cout << "File decrypted successfully to: " << decryptedFilename << endl;

    inputFile.close();
    outputFile.close();
}

int main() {
    int choice, key;
    string filename;

    cout << "File Encryption/Decryption Tool" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    cout << "Enter the filename: ";
    cin >> filename;

    cout << "Enter the encryption key (shift value): ";
    cin >> key;

    if (choice == 1) {
        encryptFile(filename, key);
    } else if (choice == 2) {
        decryptFile(filename, key);
    } else {
        cerr << "Invalid choice!" << endl;
    }

    return 0;
}
