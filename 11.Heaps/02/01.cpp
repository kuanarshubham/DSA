// k-th smallest element

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthGreatestElementBetter(vector<int>&v, int k){
    //heapify the content
    priority_queue<int, vector<int>, greater<int>>pq(v.begin(), v.end());

    int i=1, ans;

    while(i<=k){
        ans = pq.top();
        pq.pop();
        i++;
    }

    return ans;
}

void heapify(vector<int>&v, int i, int n){
    int p=i, c1=2*i+1, c2=2*i+2;

    if(c2<n && v[p] < v[c2]) p=c2;
    if(c1<n && v[p] < v[c1]) p=c1;

    if(p != i){
        swap(v[p], v[i]);
        heapify(v, p, n);
    }

    return;
}

void deletion(vector<int>&v){
    int n = v.size();

    if(n == 0) return;
    if(n == 1){
        v.pop_back();
        return;
    }

    v[0] = v[n-1];

    int i=0;
    
    while(i<n){
        int c1 = 2 * i + 1;
        int c2 = 2 * i + 2;
        int largest = i;

        if (c1 < n && v[c1] > v[largest]) largest = c1;
        if (c2 < n && v[c2] > v[largest]) largest = c2;

        if (largest != i) {
            swap(v[i], v[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

int kthGreatestElementOptimal(vector<int>&v, int k){
    //builder fn
    int n = v.size();

    for(int i=(n/2)-1; i>=0; i++){
        heapify(v, i, n);
    }

    int times = 1, ans;

    while(times <= k){
        ans = v[times-1];
        times++;
    }

    return ans;
}

int main(){
    vector<int>v = {7, 10, 4, 20, 15};
    cout<<kthGreatestElementBetter(v, 3)<<" "<<kthGreatestElementOptimal(v, 3);
}