#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> vec[10005];
bool visited[10005];
int level[10005]={0};

    int bfs(int i,int n){

            queue<int> q;

            q.push(i);
            visited[i] = true;

            while(!q.empty()){

                 int f = q.front();
                 q.pop();

                 for(int k=0; k < vec[f].size(); k++){
                       if(!visited[vec[f][k]]){
                           visited[vec[f][k]] = true;
                           level[vec[f][k]] = level[f]+1;
                           q.push(vec[f][k]);

                           if(vec[f][k]==n)
                                  {return level[vec[f][k]];}
                           }
                        }
                   }
              }

int main()
{
     int t;
     cin >> t;

     while(t--){

          memset(visited, 0, sizeof(visited));
          memset(level, 0, sizeof(level));
          memset(vec, 0, sizeof(vec));

          int n,m,res;
          cin >> n >> m;

          int u,v;
          for(int i=0;i<m;i++){
               cin >> u >> v;
               vec[u].push_back(v);
               vec[v].push_back(u);
             }

          level[1]=0;
          res = bfs(1,n);

          cout << res <<endl;
        }

    return 0;
}
