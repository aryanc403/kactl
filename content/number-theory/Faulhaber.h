/**
 * Author: Chandnani
 * Description: It computes $ \sum_{i = 1}^{i = n}i^p $
 * It assumes C[n][k], inv[n] and pow(a, x)($a^x$ \% mod) are defined.
 * Time: O(p)
 */
void pre(){
  B[0] = 1;
  B[1] = -(mod+1)/2; //Bernoulli Nos
  for(int i = 2;i<51;i+=2){
    rep(k,i){
      B[i]+=(C[i+1][k]*B[k])%mod;
    }
    B[i]%=mod;
    B[i] = ((-B[i]*inv[i+1])%mod+mod)%mod;
  }
}
ll Faul(ll n,int p){
  ll ans = 0;
  repA(i,1,p+1){
    ll cur = B[p+1-i]*modpow(n,i)%mod;
    cur = cur*C[p+1][i]%mod;
    if(i==p) ans-=cur;
    else ans+=cur;
  }
  return ((ans%mod+mod)%mod)*modpow(p+1,mod-2)%mod;
}
