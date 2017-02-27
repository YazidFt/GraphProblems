#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> vec[100005];
bool visited[100005];
int level[100005]={1};


    void  bfs(int i){

          visited[i]=true;
          queue<int> q;
          q.push(i);

          while(!q.empty()){

              int f = q.front();
              q.pop();

          for(int k=0; k < vec[f].size(); k++){
              if(!visited[vec[f][k]]){
                   visited[vec[f][k]]=true;
                   level[vec[f][k]] = level[f] + 1;
                   q.push(vec[f][k]);
                  }
                }
              }

          }


int main()
{
    int n,s;
    cin >> n;

    int u,v,res=0;

    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
      }

      cin >> s;
      level[1]=1;

      for(int p=1; p<=n; p++){
           bfs(p);
         }
         
      for(int p=1; p<=n; p++){
           if(level[p]==s)res++;
        }


      cout << res;

    return 0;
}
