#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    vector<pair<int, int>> A;
    vector<int> B;
    vector<tuple<int, int, int>> result;
    cin >>n;
    while(n!=0){
        A.clear();
        B.clear();
        result.clear();

        for(int i = 0; i<n; i++){
            cin>>x;
            A.push_back({i,x});
        }
        for(int i = 0; i<n; i++){
            cin>>x;
            B.push_back(x);
        }

        sort(A.begin(), A.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        sort(B.begin(), B.end());

        for(int i = 0; i<n; i++){
            result.push_back({A.at(i).first, A.at(i).second, B.at(i) });
        }

        sort(result.begin(), result.end(), 
        [](const auto& a, const auto& b){
            return get<0>(a)< get<0>(b);
        });

        for(auto& p : result){
            cout<<get<2>(p)<<"\n";
        }
        cout<<endl;
        cin>>n;
    }

    return 0;
}