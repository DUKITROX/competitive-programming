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
        //if(x%3 > y%3){swap(x,y);}
        int c1 = 1, c2=0;
        vector<vector<int> > arr(y, vector<int>(x,0));
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x - x%3; j++){
                if(c1<=c) arr[i][j] = c1;
                if(!((++c2)%=3))c1++;
            }
        }
        for(int j = x - x%3; j < x; j++){
            for(int i = 0; i < y - y%3; i++){
                arr[i][j] = c1;
                if(!((++c2)%=3))c1++;
            }
        }
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                os << arr[i][j] << (j==x-1?"":" ");
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
    string folderPath = "level3";
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".in") {
            processFile(entry.path());
        }
    }
    return 0;
}