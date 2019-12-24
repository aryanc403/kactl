struct palindromic_tree {
  vector<vector<int>> next;
  vector<int> suf, len;
  int new_node() {
    next.push_back(vector<int>(256,-1));
    suf.push_back(0);
    len.push_back(0);
    return next.size() - 1;
  }
  palindromic_tree(char *s) {
    len[new_node()] = -1;
    len[new_node()] = 0;
    int t = 1;
    for (int i = 0; s[i]; ++i) {
      int p = t;
      for (; i-1-len[p] < 0 || s[i-1-len
          [p]] != s[i]; p = suf[p]);
      if ((t = next[p][s[i]]) >= 0)
        continue;
      t = new_node();
      len[t] = len[p] + 2;
      next[p][s[i]] = t;
      if (len[t] == 1) {
        suf[t] = 1; // EMPTY
      } else {
        p = suf[p];
        for (; i-1-len[p] < 0 || s[i-1-
            len[p]] != s[i]; p = suf[p]);
        suf[t] = next[p][s[i]];
      }
    }
  }
  void display() {
    vector<char> buf;
    function<void (int)> rec = [&](int p
        ) {
      if (len[p] > 0) {
        for (int i = buf.size()-1; i >=
            0; --i) cout << buf[i];
        for (int i = len[p] % 2; i < buf
            .size(); ++i) cout << buf[i];
        cout << endl;
      }
      for (int a = 0; a < 256; ++a) {
        if (next[p][a] >= 0) {
          buf.push_back(a);
          rec(next[p][a]);
          buf.pop_back();
        }
      }
    };
    rec(0); rec(1);
  }
};
char s[100000];
int main() {
  int k; 
  cin>>k>>s;
  palindromic_tree T(s);
  T.display();
}

