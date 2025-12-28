#include <iostream>

using namespace std;

int main()
{
	int cases, result, num;
	string u;
	
	cin >> cases;
	
	while(cases--)
	{
		result = 0;
		while(cin >> num && num != 0)
		{
			cin >> u;
			
			switch(u.at(0))
			{
				case 'o':
					result += num;
					break;
				case 'd':
					result += (num * 10);
					break;
				case 'h':
					result += (num * 100);
					break;
				case 'k':
					result += (num * 1000);
					break;
				case 'M':
					result += (num * 1000000);
					break;
				case 'G':
					result += (num * 1000000000);
					break;
			}
		}
		
		if(result % 1000000000 == 0)
			cout << result / 1000000000 << " G" << endl;
		else if(result % 1000000 == 0)
			cout << result / 1000000 << " M" << endl;
		else if(result % 1000 == 0)
			cout << result / 1000 << " k" << endl;
		else if(result % 100 == 0)
			cout << result / 100 << " h" << endl;
		else if(result % 10 == 0)
			cout << result / 10 << " da" << endl;
		else
			cout << result << " o" << endl;
	}
	
	return 0;
}