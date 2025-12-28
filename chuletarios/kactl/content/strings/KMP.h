/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: pi[x] computes the length of the longest prefix of s that ends at x,
 * other than s[0...x] itself (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */
#pragma once

const int MAX_N = 200010;

char T[MAX_N], P[MAX_N];
int n, m;
int b[MAX_N];

void kmpProcess(){
    int i=0, j=-1;
    b[0]=-1;
    while (i<m)
    {
        while ((j>=0) && (P[i]!=P[j])) j=b[j];
        ++i; ++j;
        b[i]=j;
    }
}

void kmpSearch(){
    int i=0, j=0;
    while (i<n)
    {
        while ((j>=0) && (T[i]!=P[j]))j=b[j];
        ++i; ++j;
        if (j==m){
            //encontramos una coincidencia
            j=b[j];
        }
    }
}