#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++){
        string s1, s2;
        cin >> s1 >> s2;

        char c1, c2, c3;
        int n1, n2, n3;

        c1 = s1[0];
        c2 = s2[0];

        if((c1 == 'D' || c2 == 'D') && (c1 == 'T' || c2 == 'T')){
            if(c1 == 'D'){
                n1 = stoi(s1.substr(2,s1.length()));
                n2 = stoi(s2.substr(2, s2.length()));

                n3 = n1 / n2;
            }else{
                n1 = stoi(s1.substr(2,s1.length()));
                n2 = stoi(s2.substr(2, s2.length()));

                n3 = n2 / n1;
            }
            c3 = 'V';
        }else if((c1 == 'D' || c2 == 'D') && (c1 == 'V' || c2 == 'V')){
            if(c1 == 'D'){
                n1 = stoi(s1.substr(2,s1.length()));
                n2 = stoi(s2.substr(2, s2.length()));

                n3 = n1 / n2;
            }else{
                n1 = stoi(s1.substr(2,s1.length()));
                n2 = stoi(s2.substr(2, s2.length()));

                n3 = n2 / n1;
            }
            c3 = 'T';
        }else{
            n1 = stoi(s1.substr(2,s1.length()));
            n2 = stoi(s2.substr(2, s2.length()));

            n3 = n1*n2;
            c3 = 'D';
        }
        cout << c3 << "=" << n3 << endl;
    }
    return 0;
}