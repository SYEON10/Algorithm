#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int height, width;
    cin >> height >> width;

    vector<int> water(width, 0);
    vector<int> pillar(height + 1);

    for(int i = 0; i < width; i++){
        cin >> pillar[i];
    }

    int sum = 0;

    for(int h = 1; h <= height; h++){
        int before = -5;
        for(int w = 0; w < width; w++){
            if(pillar[w] >= h){
                if(before >= 0){
                    sum += w - before - 1;
                }
                before = w;
            }
        }
    }

    cout << sum;

    return 0;
}