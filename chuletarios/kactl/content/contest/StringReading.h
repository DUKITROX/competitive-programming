/**
 * Author: Daniel Bordeianu
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: After getline(cin, s); always do cin.ignore();
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
getline(cin,s); cin.ignore();
stringstream ss (s);
while(ss >> word)