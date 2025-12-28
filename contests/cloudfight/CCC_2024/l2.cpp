#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
using namespace std;
namespace fs = std::filesystem;

void solve(istream& is, ostream& os) {
    int t; is >> t; while(t--){
        int x,y,c; is >> x >> y >> c;
        int c1=1,c2=0;
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                os << c1 << " ";
                ++c2 %= 3;
                if(!c2)c1++;
            }
            os << "\n";
        }
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
    string folderPath = "level2-2";
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".in") {
            processFile(entry.path());
        }
    }
    return 0;
}