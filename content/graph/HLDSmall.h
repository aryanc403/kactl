/**
 * Author: adamant
 * Source: CF blog
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 *  edges such that the path from any leaf to the root contains at most log(n)
 *  light edges. The function of the HLD can be changed by modifying T, LOW and
 *  f. f is assumed to be associative and commutative.
 *  isAncestor(u,v) returns true if u exists in path between root and v.
 *  Global declarations -
 *  sz denotes size of subtree.
 *  par denotes parent of vertex.
 *  g denotes adj list of graph. Note it removes parent from it.
 *  tin, tout are in out time of vertex. Uses t variable.
 */
// usage: dfs_sz(root,-1); head[root] = root; dfs\_hld(root)
// queryPath(x,y) modify path $[x,....y]$ in segment or fenwick tree.
vector<vi>g;
vi tin,tout,sz,par,head;
int t;
void dfs_sz(int v, int p) {
    sz[v] = 1;
    par[v]=p;
    auto it = find(all(g[v]), p);
	if (it != g[v].end())
		g[v].erase(it);
    for(auto &u: g[v]) {
        dfs_sz(u,v);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]])
            swap(u, g[v][0]);
    }
}
void dfs_hld(int v ) {
    tin[v] = t++;
    for(auto u: g[v]) {
        head[u] = (u == g[v][0] ? head[v] : u);
        dfs_hld(u);
    }
    tout[v] = t;
}
ll query(int u,int v) {
    ll ans=0;
    while(!isAncestor(head[u],v)) {
        ans=max(ans,queryPath(tin[head[u]],tin[u]));
        u=par[head[u]];
    }
    while(head[u]!=head[v]) {
        ans=max(ans,queryPath(tin[head[v]],tin[v]));
        v=par[head[v]];
    }
    ans=max(ans,queryPath(min(tin[v],tin[u]),max(tin[v],tin[u])));
    return ans;
}
