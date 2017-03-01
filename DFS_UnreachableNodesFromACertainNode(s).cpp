#include <iostream>
#include <vector>

using namespace std;

vector<int> ad[100007];
bool visited[100007];

   void dfs(int i){

          visited[i]=true;

          for(int a : ad[i]){
               if(!visited[a]){
                    dfs(a);
                    visited[a]=true;
                }
             }
          }

int main()
{
    int n,m;
    cin >> n >> m;

    int u,v,s,res=0;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
      }

        cin >> s;

        dfs(s);

        for(int i=1; i<=n; i++){
            if(visited[i]==false)
                res++;
           }

       cout << res;

    return 0;
}
