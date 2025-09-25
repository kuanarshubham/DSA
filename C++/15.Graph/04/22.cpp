// word ladder 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ladderLenght(vector<string>&wordList, string targetWord, string startWord){
    queue<pair<string, int>>q;
    unordered_set<string>st(wordList.begin(), wordList.end());

    q.push({startWord, 0});
    if(st.find(startWord)!=st.end()) st.erase(startWord);

    while(!q.empty()){
        string word = q.front().first;
        int step = q.front().second;

        q.pop();

        if(word==targetWord) return step;

        for(int i=0; i<word.size(); i++){
            char originalChar=word[i];

            for(char j='a'; j<='z'; j++){
                word[i]=j;

                if(st.find(word)!=st.end()){
                    q.push({word, step+1});
                    st.erase(word);
                }
            }
            
            word[i]=originalChar;
        }
    }

    return 0;
}

int main(){

}