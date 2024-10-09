
#include <iostream>
#include <fstream>
#include <string>

//the start 
int currentPosition = 5;

// Function to process movements and translate them 
void ProcessMovements(const std::string& movements) {
    for (char move : movements) {
        switch (move) {
            case 'U': 
                if (currentPosition > 3) currentPosition -= 3;
                break;
            case 'D': 
                if (currentPosition < 7) currentPosition += 3;
                break;
            case 'L': 
                if (currentPosition % 3 != 1) currentPosition -= 1;
                break;
            case 'R': 
                if (currentPosition % 3 != 0) currentPosition += 1;
                break;
        }
    }
}

int main() {
    std::string filename;
    std::cout << "Enter file to translate: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << filename << " does not exist..." << std::endl;
        return 1;
    }

    std::string line;
    std::string passcode = "";

    while (std::getline(file, line)) {
    if (line.empty()) {
        passcode += '5'; // Append 5 for empty line
    } else {
        ProcessMovements(line);
        passcode += std::to_string(currentPosition);  
    }
}

    file.close(); // Close the file
    std::cout << std::endl;
    std::cout << "Passcode: " << passcode << std::endl;

    return 0;
}


