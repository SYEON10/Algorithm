#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int count = 0;
    
    cin >> n;
    
    vector<int> lines(n);
    
    for(int i = 0; i < n; i++){
        cin >> lines[i];
    }
    
    sort(lines.begin(), lines.end());
    
    for(int i = 0; i < n; i++){
        count += lines[i] * (n - i);
    }
    
    cout << count;

    return 0;
}