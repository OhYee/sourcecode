//SPFA
void spfa(int s) {
    while(!Q.empty())
        Q.pop();
    for(int i = 1;i <= n;i++)
        dist[i] = INF;

    Q.push(s);
    dist[s] = 0;
    vis[s] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = false;

        for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
            int v = edge[*it].v;
            if(dist[v] > dist[u] + edge[*it].w) {
                dist[v] = dist[u] + edge[*it].w;
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}