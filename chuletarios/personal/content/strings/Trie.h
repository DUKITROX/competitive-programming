/**
 * Author: ignacio
 * License: CC0
 * Description: 
 * except 
 * Time: O(m) for inserting and searching new words
 * Status: neither tested nor compiled
 */

#pragma once

#define MAXN 26

struct Trie{
	int prefixes, words;
	vector<*Trie> child;
	Trie() : prefixes(0), words(0), child(MAXN, nullptr) {}
	~Trie() {for(int i = 0; i < MAXN; i++) delete child[i];}
	void add(string const& s, int i = 0){
		prefixes++;
		if(i >= s.length()) words++;
		else (child[s[i]-'a'] == nullptr ? child[s[i]-'a'] = new Trie() : child[s[i]-'a'])->add(s, i+1);
	}
};

