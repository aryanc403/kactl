/*Description:
  It finds the centroid tree for given tree.
  par[x] denotes centroid parent of x.
  Initialize global variables correctly before using.
  */
vector<int> adj[maxN+1];
vi sz, par;
vector<bool> block;
int nn;
void dfs0(int x, int p) {
  nn++;
  sz[x] = 1;
  for(auto v: adj[x]) {
    if(v!=p && !block[v]) {
      dfs0(v,x);
      sz[x] += sz[v];
    }
  }
}
int dfs1(int x, int p) {
  for(auto v: adj[x]) {
    if(v!=p && !block[v] && sz[v]>nn/2)
      return dfs1(v, x);
  }
  return x;
}
// Parent of root is parent only
void decompose(int root, int p) {
  nn=0;
  dfs0(root, root); 
  int centroid = dfs1(root, root);
  if(p==-1) p = centroid;
  par[centroid] = p;
  block[centroid] = true;
  for(auto v: adj[centroid]) {
    if(!block[v])
      decompose(v, centroid);
  }
}
