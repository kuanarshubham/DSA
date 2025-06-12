// jobb seq array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
        int id;
        float profit;
        int deadline;

        Job(int id, float profit, int deadline){
            this->id = id;
            this->profit = profit;
            this->deadline = deadline;
        }
};

bool compare(Job *j1, Job *j2){
    return j1->profit > j2->profit;
}

pair<int, int>jobSeqProb(vector<Job*>&jobs){
    int n=jobs.size(), maxDays=0, count=0, total=0;

    sort(jobs.begin(), jobs.end(), compare);

    for(int i=0; i<n; i++){
        maxDays = max(maxDays, jobs[i]->deadline);
    }

    cout<<maxDays;

    int days[maxDays+1] = {-1};

    for(int i=0; i<n; i++){
        for(int j=jobs[i]->deadline; j>=0; j--){
            if(days[j] != -1){
                count++;
                total += jobs[i]->profit;
                days[j] = jobs[i]->id;
                break;
            }
        }
    }

    for(auto it: days) cout<<it<<" ";
    cout<<endl;

    cout<<count<<" "<<total<<endl;

    return {count, total};
}



int main(){
    vector<Job*>jobs = {
        new Job(1, 4, 20),
        new Job(2, 5, 60),
        new Job(3, 6, 70),
        new Job(4, 6, 65),
        new Job(5, 4, 25),
        new Job(6, 2, 80),
        new Job(7, 2, 10),
        new Job(8, 2, 22)
    };

    jobSeqProb(jobs);
}