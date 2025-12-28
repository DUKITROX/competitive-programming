#include <iostream>

using namespace std;

int main()
{
    string num;
    int result;
    
    do
    {
        cin >> num;
        
        if(num != "0")
        {
            result = 0;
            
            while(num != "")
            {
                result += stoi(num);
                num = num.substr(1);
            }
            
            cout << result << endl;
        }
    } while(num != "0");
    
    return 0;
}