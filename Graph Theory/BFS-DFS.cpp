#include <bits/stdc++.h>
using namespace std;

bool allVisited(bool visit[], int V)
{
    for(int i=0; i<V; i++)
        if(!visit[i]) return false;

    return true;
}

void BFS(vector< set<int> > &adList, int V, int src)
{
    queue<int> q;
    bool visit[V];
    vector<int> path;

    for(int i=0; i<V; i++) visit[i]=false;
    int i=src;
    q.push(i);
    while(i<V)
    {
        visit[i]=true;
        set<int> :: iterator itr;

        for(itr=adList[i].begin(); itr!=adList[i].end(); itr++)
            if(!visit[*itr])
                q.push(*itr);

        if(count(path.begin(), path.end(), q.front())==0)
            path.push_back(q.front());

        q.pop();
        i = q.front();
        if(allVisited(visit, V)) break;
    }
    for(int i=0; i<path.size(); i++)
        cout<<path[i]<<" ";
}

void DFS(vector< set<int> > &adList, int V, int src)
{
    stack<int> s;
    vector<int> path;
    bool visit[V];

    for(int i=0; i<V; i++) visit[i]=false;
    int i=src;
    s.push(i);
    while(i<V)
    {
        int flag=0;
        visit[i]=true;
        if(count(path.begin(), path.end(), s.top())==0)
            path.push_back(s.top());

        set<int> :: iterator itr;
        for(itr=adList[i].begin(); itr!=adList[i].end(); itr++)
        {
            if(!visit[*itr])
            {
                s.push(*itr);
                flag=1;
                break;
            }
        }
        if(!flag) s.pop();
        i = s.top();
        if(allVisited(visit, V)) break;
    }
    for(int i=0; i<path.size(); i++)
        cout<<path[i]<<" ";
}


int main()
{
    int V, E, v1, v2, w;
    cout << "Enter no. of vertices: "; cin >> V;
    cout << "Enter no. of edges: "; cin >> E;

    vector< set<int> > adList(V);

    cout << "Enter edges in the form v1 -> v2\n";
    for(int i=0; i<E; i++)
    {
        cin >> v1 >> v2;
        adList[v1].insert(v2);
        adList[v2].insert(v1);
    }

    cout << "\nAdjacency List of required graph:\n";
    for(int i=0; i<V; i++)
    {
        cout << "Vertex[" << i << "]";
        set<int> :: iterator itr;
        for(itr=adList[i].begin(); itr!=adList[i].end(); itr++)
            cout << "--> " << *itr;

        cout << endl;
    }
    int src;
    cout<<"Enter start point: "; cin>>src;
    cout<<"\nBFS: ";
    BFS(adList, V, src);
    cout<<"\nDFS: ";
    DFS(adList, V, src);
}
