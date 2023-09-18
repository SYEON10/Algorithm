#include <iostream>
#include <map>
#include <string>

using namespace std;

//확장자 몇개, 확장자 사전 순 정렬

int main(){

    int n, index;
    string temp, extension;
    map<string, int> files; //확장자, 파일 수

    cin >> n;

    //. 이후를 잘라서 map 에 넣음
    while(n--){
        cin >> temp;

        //확장자 : extension
        index = temp.find('.');
        for(int i = index + 1; i < temp.size(); i++){
            extension += temp[i];
        }

        //확장자가 map에 있으면
        if(files.find(extension) != files.end()){
            files[extension] += 1;
        }
        else{ //확장자가 map에 없으면
            files.insert({extension, 1});

        }
        extension = "";
    }

    for(auto file : files){
        cout << file.first << ' ' << file.second << '\n';
    }

    return 0;
}