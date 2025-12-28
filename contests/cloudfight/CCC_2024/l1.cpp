#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
using namespace std;
namespace fs = std::filesystem;

void solve(istream& is, ostream& os) {
    int n; is >> n;
    while(n--){
        int x,y; is >> x >> y; os << (x/3)*y << "\n";
    }
}

void processFile(const fs::path& inputFilePath) {
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        cerr << "Could not open the file: " << inputFilePath << endl;
        return;
    }

    string outputFilePath = inputFilePath.string();
    outputFilePath.replace(outputFilePath.find(".in"), 3, ".out");
    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Could not open the file: " << outputFilePath << endl;
        return;
    }

    solve(inputFile, outputFile);

    inputFile.close();
    outputFile.close();
}

int main() {
    string folderPath = "level1";
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".in") {
            processFile(entry.path());
        }
    }
    return 0;
}