/**
 * Author: Chandnani
 * Description: Find inverse of polynomial h(x) mod $x^{ll}$.
 * Time: O(nlogn)
 */
vl inv(vl& h,int ll){
    assert((ll&(ll-1))==0);
    if(sz(h)<ll) h.resize(ll,0);
    vl ans;
    ans.pb(modpow(h[0],mod-2));
    for(int l = 2;l<=ll;l*=2){
        vl a = ans;
        vl h0 = vl(h.begin(),h.begin()+l/2);
        vl h1 = vl(h.begin()+l/2,h.begin()+l);
        vl c = conv(a,h0);
        if(sz(c)<l/2+1) c.resize(l/2+1,0);
        c = vl(c.begin()+l/2,c.end());
        vl tem = add(c,conv(a,h1));
        tem.resize(l/2,0);
        vl b = conv(a,tem);
        b.resize(l/2,0);
        trav(i,b) ans.pb(-i);
    }
    // while(sz(ans)>1&&ans.back()==0) ans.pop_back();
    while(sz(h)>1&&h.back()==0) h.pop_back();
    return ans;
}

