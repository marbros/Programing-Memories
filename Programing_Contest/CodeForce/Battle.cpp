#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int nods,arcs,val[500],best,adj[500][500],fr,to;
int main (void)
{
    while(cin>>nods>>arcs)
    {
        best = 0;
        memset(val,0,sizeof(val));
        memset(adj,0,sizeof(adj));
        for(int i=0;i<nods;i++)
        {
            cin>>val[i];
            if(best<val[i])
                best = val[i];
        }
        for(int i=0;i<arcs;i++)
        {
            cin>>fr>>to;
            adj[fr-1][to-1]=1;
            adj[to-1][fr-1]=1;
            if(val[fr-1]+val[to-1]>best)
                best = val[fr-1]+val[to-1];
        }
        for(int i=0;i<nods;i++)
        {
            for(int j=i+1;j<nods;j++)
            {
                if(!adj[i][j])
                    continue;
                for(int k=j+1;k<nods;k++)
                {
                    if((!adj[i][k])||(!adj[j][k]))
                        continue;
                    if(val [i]+val[j]+val[k] > best)
                        best = val[i]+val [j]+val[k];

                }
            }
        }
        for(int i=0;i<nods;i++)
        {
            for(int j=i+1;j<nods;j++)
            {
                if(!adj[i][j])
                    continue;
                for(int k=j+1;k<nods;k++)
                {
                    if((!adj[i][k])||(!adj[j][k]))
                        continue;
                    for(int l=k+1;l<nods;l++)
                    {
                        if((!adj[i][l])||(!adj[j][l])||(!adj[k][l]))
                            continue;
                        if(val [i]+val[j]+val[k]+val[l] > best)
                            best = val[i]+val [j]+val[k]+val[l];
                    }

                }
            }
        }
        cout<<best<<endl;
    }
    return 0;
}
