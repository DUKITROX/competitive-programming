#!/bin/zsh

# Assign the number of files to create
n=2  # Change this value to create more or fewer files

# Template content for the .cpp files
template="#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--) solve();
    return 0;
}"

# Create n .cpp files with names A.cpp, B.cpp, C.cpp, ...
for ((i=0; i<=n; i++)); do
    # Calculate the file name based on the ASCII value
    char=$(printf "%c" "$((65 + i))")
    file_name="${char}.cpp"
    
    # Create the file and write the template content to it
    echo -e "$template" > "$file_name"
done

echo "$((n+1)) .cpp files created successfully."