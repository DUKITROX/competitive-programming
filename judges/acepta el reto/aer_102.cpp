#include <iostream>
#include <string>
using namespace std;

bool isvocal(char & a);

int main() {
	string l = "";
	int desp, cont = -1;
	char c;
	while (l != "FIN") {
		if (cont != -1)
			cout << cont << "\n";
		cont = 0;
		c = getchar();
		while(c == '\n')
			c = getchar();
		getline(cin, l);
		desp = 'p' - c;
		for (int i = 0; i < l.length(); ++i) {
			if (isalpha(l[i])) {
				if (isupper(l[i])) {
					l[i] = (l[i] + desp);
					if (!isalpha(l[i]) || !isupper(l[i])) {
						if (desp > 0)
							l[i] -= 26;
						else
							l[i] += 26;
					}
					
						
					if (isvocal(l[i]))
						++cont;
				}
				else {
					l[i] = l[i] + desp;
					if (l[i] > 122 || l[i] < 97) {
						if (desp > 0)
							l[i] -= 26;
						else
							l[i] += 26;
					}
					if (isvocal(l[i]))
						++cont;
				}
				
			}
		}
		//cout << l << endl;
	}
	return 0;
}

bool isvocal(char & a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
		a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
		return true;
	else
		return false;
}