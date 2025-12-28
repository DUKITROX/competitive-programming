/**
 * Author: Simon Lindholm
 * Date: 2019-05-22
 * License: CC0
 * Description: 
 * Time: $\log(n)$
 * Status: Works
 */
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}