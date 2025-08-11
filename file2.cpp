#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFile(const string& filename) {
    ofstream outFile(filename);  // overwrite mode
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    cout << "Enter text to write to the file (end with a single line 'END'):\n";
    string line;
    while (getline(cin, line)) {
        if (line == "END") break;
        outFile << line << endl;
    }
    outFile.close();
    cout << "Data written successfully.\n";
}

void appendToFile(const string& filename) {
    ofstream outFile(filename, ios::app);  // append mode
    if (!outFile) {
        cerr << "Error opening file for appending.\n";
        return;
    }
    cout << "Enter text to append (end with a single line 'END'):\n";
    string line;
    while (getline(cin, line)) {
        if (line == "END") break;
        outFile << line << endl;
    }
    outFile.close();
    cout << "Data appended successfully.\n";
}

void readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File not found or error opening file.\n";
        return;
    }
    cout << "Contents of '" << filename << "':\n\n";
    string line;
    bool empty = true;
    while (getline(inFile, line)) {
        cout << line << endl;
        empty = false;
    }
    if (empty) cout << "[File is empty]\n";
    inFile.close();
}

int main() {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);

    int choice;
    do {
        cout << "\n--- File Management Tool ---\n";
        cout << "1. Write to file\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: writeToFile(filename); break;
            case 2: appendToFile(filename); break;
            case 3: readFromFile(filename); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
