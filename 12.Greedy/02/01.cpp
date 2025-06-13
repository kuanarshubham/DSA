// n meetng n one oom
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Meet{
    public:
        int start, end;

        Meet(int s, int e){
            this->start = s;
            this->end = e;
        }
};

bool compare(Meet* m1, Meet* m2){
    return m1->end < m2->end;
}

int numeOfMeetsPossible(vector<Meet*>&v){
    int n=v.size();
    
    sort(v.begin(), v.end(), compare);

    int count=1, freeTime=v[0]->end;

    for(int i=1; i<n; i++){
        if(freeTime <= v[i]->start){
            count++;
            freeTime = v[i]->end;
        }
    }

    return count;
}

int main(){
    vector<Meet*>v = {
        new Meet(0, 5),
        new Meet(3, 4),
        new Meet(1, 2),
        new Meet(5, 9),
        new Meet(5, 7),
        new Meet(8, 9)
    };

    cout<<numeOfMeetsPossible(v);
}
