#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int arr[1003];
int siz[1002],tmp[1003];


int root(int i){
      if(arr[i] == i) return i;
      return arr[i] = root(arr[i]);
    }

void union_(int x,int y){
        int rootX = root(x);
        int rootY = root(y);

        if(rootX == rootY) return;//already Connected

        arr[rootX] =  rootY;
        siz[rootY] = siz[rootY] + siz[rootX];
        siz[rootX] = 0;
     }




int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> res;vector<int> vec(n+1);

    //initialize arrays
    for(int i=1; i<=n; i++){
           arr[i]=i;
           siz[i]=1;
      }

    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        union_(x,y);

        memcpy(&vec[0], siz, (n+1)*sizeof(int));
        res.push_back(vec);
      }


    for(auto& v : res){
       sort(v.begin(), v.end());
       for(int i=1; i<=n; i++){
          if(v[i]!=0){
               cout << v[i] << " ";
             }
          }
        cout << endl;
      }


    return 0;
}
