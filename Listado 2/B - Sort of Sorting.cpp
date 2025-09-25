//IMPORTANTE
#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<string> v;


    while(n !=0) {

        v.clear();
        string apellido;
        for(int j = 0; j < n; j++){
        cin >> apellido;
        v.push_back(apellido);
        }

        //Forma de decirle como comparar. 
        stable_sort(v.begin(), v.end(), 
        [](const string &a, const string &b){
            string primeros_a = a.substr(0,2);
            string primeros_b = b.substr(0,2);
            return primeros_a < primeros_b;
        });

        for(string apellido : v){
            cout<<apellido<<"\n";
        }
        cout<<endl;
        cin >> n;
    }

}