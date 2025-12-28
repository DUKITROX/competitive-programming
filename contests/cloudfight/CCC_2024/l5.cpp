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
        vector<vector<char> > arr(y, vector<char>(x,'.'));
        
        for(int i = 0; i < y; i+=2){
            if(y%2 == 0 && i >= y-2) break;
            
            for(int j = 0; j < x-1; j+=3){
                if(x%3 == 0 && j >= x-3) break;
                for(int k = j; k < j+2; k++) arr[i][k] = 'X';
            }
        }
        //---------------
        if(y%2 == 1){
            for(int i = 0; i < y-1; i+=3){ // 3 magico
                if(x%3 == 0 || x%3 == 1) arr[i][x-1] = arr[i+1][x-1] = 'X';
                if(x%3 == 0) arr[i][x-3] = arr[i+1][x-3] = 'X';
            }
        }
        //--------------
        if(y%2 == 0){
            for(int i = 0; i < y-4; i+=3){ // 3 magico
                if(x%3 == 0 || x%3 == 1) arr[i][x-1] = arr[i+1][x-1] = 'X';
                if(x%3 == 0) arr[i][x-3] = arr[i+1][x-3] = 'X';
            }
            for(int j = 0; j < x-3; j += 2){
                arr[y-1][j] = arr[y-2][j] = 'X';
            }
        }
        //--------------
        if(y%2 == 0){
            if(x%3 == 2 || x%3 == 1){
                for(int j = 0; j < x; j += 2){
                    arr[y-1][j] = arr[y-2][j] = 'X';
                }
            }else{
                if(arr[y-1][x-3] != 'X' && arr[y-2][x-3] != 'X' && arr[y-2][x-1] != 'X' && arr[y-2][x-2] != 'X')
                    arr[y-1][x-1] = arr[y-1][x-2] = 'X';

                if(arr[y-2][x-3] != 'X' && arr[y-2][x-1] != 'X' && arr[y-2][x-2] != 'X' && 
                arr[y-4][x-3] != 'X' && arr[y-4][x-1] != 'X' && arr[y-4][x-2] != 'X' &&
                arr[y-3][x-3] != 'X')
                    arr[y-3][x-1] = arr[y-3][x-2] = 'X';
            }
        }
        
        //---------------
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                os << arr[i][j];
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
    string folderPath = "level5";
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".in") {
            processFile(entry.path());
        }
    }
    return 0;
}