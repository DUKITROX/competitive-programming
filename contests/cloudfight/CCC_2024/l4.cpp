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
        vector<vector<char> > arr(y, vector<char>(x,'.'));
        for(int i = 0; i < y; i+=2){
            for(int j = 0; j < x-2; j+=4){
                for(int k = j; k < j+3; k++)arr[i][k] = 'X';
            }
        }
        if (x%4==2 || x%4==1){
            for(int i = 0; i < y-2; i+=4){
                for(int k = 0; k < 3; k++)
                    arr[i+k][x-1]='X';

            }
        }

        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                os << arr[i][j] << (j==x-1?"":"");
            }
            os << "\n";
        }
        os << "\n";
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
    string folderPath = "level4";
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".in") {
            processFile(entry.path());
        }
    }
    return 0;
}