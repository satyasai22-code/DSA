#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

class SegmentTree{
    public:
    
        SegmentTree(vector<ll>& arr){
            size = arr.size();
            segTree.resize(4*(size), 0);
            build(0, size - 1, 0, arr);
        }
        
        void build(vector<ll>& arr){
            build(0, arr.size() - 1, 0, arr);
        }
        
        void print(){
            for(int i = 0;i< 4 * (size);i++) cout<<segTree[i]<<" ";
            cout<<"\n";
        }
        
        void bfsPrint(){
            queue<pair<ll, int>> q;
            q.push({segTree[0], 0});
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                     auto front = q.front();
                     q.pop();
                     int sec = front.second;
                     cout<<front.first<<" ";
                     if(2*sec + 1 < size) q.push({segTree[2*sec + 1], 2*sec + 1});
                     if(2*sec + 2 < size) q.push({segTree[2*sec + 2], 2*sec + 2});
                }
               cout<<"\n";
            }
        }
        
        void update(int ind, int val){
            update(0, size - 1, 0, ind, val);
        }
        
        ll query(int l, int r){
            return query(0, size - 1, l, r, 0);
        }

    private:
        vector<ll> segTree;
        int size;
        
        ll query(int s, int e, int l, int r, int index){
            if(l<=s and r>=e) return segTree[index];
            if(l>e or r<s) return 0;
            int mid = (s + e)/2;
            ll q1 = query(s, mid, l, r, 2*index + 1);
            ll q2 = query(mid + 1, e, l, r, 2*index + 2);
            return q1 + q2;
        }
        
        void build(int s, int e, int index, vector<ll>& arr){
            if(s == e){
                segTree[index] = arr[s];
                return;
            }
            int mid =  (e + s)/2;
            build(s, mid, 2*index + 1, arr);
            build(mid+1, e, 2*index + 2, arr);
            segTree[index] = segTree[2*index + 1] + segTree[2*index + 2]; 
        }
        
        void update(int s, int e, int index, int ind, int val){
            if(s>ind or e<ind) return;
            if(s == e) { 
                segTree[index] = val;
                return;
            }
            int mid =  (e + s)/2;
            update(s, mid, 2*index + 1, ind, val);
            update(mid+1, e, 2*index + 2, ind, val);
            segTree[index] = segTree[2*index + 1] + segTree[2*index + 2]; 
        }
};

int main(){
    vector<ll> arr{1, 2, 3, 4, 5, 6, 8};
    SegmentTree *s = new SegmentTree(arr);
    // s->print();
    s->update(6, 7);
    s->update(1, 3);
    s->bfsPrint();
    s->update(1, 2);
    // cout<<s->query(2, 3)<<" "<<s->query(0, 6)<<" "<<s->query(1, 1)<<" "<<s->query(0, 0);
    
}
