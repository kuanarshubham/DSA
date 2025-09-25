// palindrome partitioning

// for partitioning: go via this -
// aa | bb -> that means left of '|' is apalindrome, nothing can be said about the right of '|'

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while(start<=end){
        if(s[start] != s[end]) return false;

        start++;
        end--;
    }

    return true;
}

void recc(int i, string s, vector<string> &temp, vector<vector<string>> &ans)
{
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int index = i; index < s.size(); index++)
    {
        if (isPalindrome(s, index, i))
        {
            temp.push_back(s.substr(index, index - i + 1));
            recc(index + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> palindromePart(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;

    recc(0, s, temp, ans);

    for(auto it: ans){
        for(auto it2: it) cout<<it2<<" ";
        cout<<endl;
    }

    return ans;
}

int main()
{
    string s = "aabb";
    palindromePart(s);

}

//wrong answer
