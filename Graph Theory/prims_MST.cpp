#include <bits/stdc++.h>
using namespace std;
vector<int> edge;
int mstVal=0;
int getMinNode(vector<bool> &visit, vector< vector< pair<int, int> > > &g, int n)
{
    int minVal = INT_MAX, minInd=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            if(visit[i] && !visit[g[i][j].second] && g[i][j].first < minVal)
            {
                minVal = g[i][j].first;
                minInd = g[i][j].second;
            }
        }
    }
    edge.push_back(minVal);
    mstVal += minVal;
    return minInd;
}

int main()
{
    int n, e;
    cout<<"Enter vertices and edges: ";
    cin>>n>>e;
    vector< vector< pair<int, int> > > g(n);

    cout<<"Enter edges with weights:\n";
    for(int i=0; i<e; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        g[a-1].push_back(make_pair(w, b-1));
        g[b-1].push_back(make_pair(w, a-1));
    }

    for(int i=0; i<n; i++)
        sort(g[i].begin(), g[i].end());

    for(int i=0; i<n; i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<g[i].size(); j++)
            cout<<g[i][j].first<<"."<<g[i][j].second<<" ";
        cout<<endl;
    }
    cout<<endl;
    vector<bool> visit(n, false);
    int src, i;
    cout<<"Enter start point: "; cin>>src;
    i=src-1;
    for(int c=0; c<n-1; c++)
    {
        visit[i] = true;
        i = getMinNode(visit, g, n);
    }
    for(int i=0; i<edge.size(); i++) cout<<edge[i]<<" ";
    cout<<endl;
    cout<<mstVal<<endl;
}
