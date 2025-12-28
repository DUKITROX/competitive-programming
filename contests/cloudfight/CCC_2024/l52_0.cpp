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
        
        for (int i = 0; i < y-3; i+=3)
        {
            if (x%2){
                for (int j = 0; j < x; j+=2)
                {
                    arr[i][j]='X';
                    arr[i+1][j]='X';
                }
                
            }
            else{
                for (int j = 0; j < x-3; j++)
                {
                    arr[i][j]='X';
                    arr[i+1][j]='X';
                }
                
            }
        }
        if (!(x%2)){
            for (int i = 0; i < y-3; i+=2)
            {
                arr[i][x-2]='X';
                arr[i][x-1]='X';
            }
            if ((y/3)%2){

                if (!(y%3)){
                    arr[y-3][x-2]='X';
                    arr[y-3][x-1]='X';
                }

                for (int j = 0; j < x-3; j++)
                {
                    arr[i][j]='X';
                    arr[i+1][j]='X';
                }
            }
            else{

            }
        
        }
        else{
            if ((y/3)%2){
                arr[y-1][x-2]='X';
                arr[y-1][x-1]='X';

                if (!(y%3)){
                    arr[y-3][x-2]='X';
                    arr[y-3][x-1]='X';
                }

                for (int j = 0; j < x-3; j+=2)
                {
                    arr[y-1][j]='X';
                    arr[y-2][j]='X';
                }
            }
            else {
                arr[y-1][0]='X';
                arr[y-1][x-1]='X';
                for (int j = 0; j < x; j++)
                {
                    arr[i][j]='X';
                    arr[i+1][j]='X';
                }
            }
        }
        
 
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