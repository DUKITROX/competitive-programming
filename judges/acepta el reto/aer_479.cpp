#include <iostream>
using namespace std;

string mapa[100];
int n, l, m;
string dir;
int filas, col;
int dist;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> filas >> col;
		if (filas == 0) break;

		for (int i = 0; i < filas; i++) cin >> mapa[i];

		cin >> n;
		for (int i = 0; i < n; i++) {
            dist = -1;
			cin >> l >> m >> dir;
			if (dir[0] == 'I') {
				for (int j = m - 2; j >= 0; j--) {
					if (mapa[l - 1][j] == 'X') {
                        dist = m - j - 1;
						break;
					}
				}
			}
			else if (dir[0] == 'D') {
				for (int j = m; j <= col - 1; j++) {
					if (mapa[l - 1][j] == 'X') {
                        dist = j - m + 1;
						break;
					}
				}
			}
			else if(dir[1] == 'R'){
				for (int j = l - 2; j >= 0; j--) {
					if (mapa[j][m - 1] == 'X') {
						dist = l - 1 - j;
						break;
					}
				}
			}
			else {
				for (int j = l; j <= filas - 1; j++) {
					if (mapa[j][m - 1] == 'X') {
						dist = j - l + 1;
						break;
					}
				}
			}
			if (dist == -1) cout << "NINGUNO\n";
			else cout << dist << "\n";
		}
		cout << "---\n";
	}
	return 0;
}