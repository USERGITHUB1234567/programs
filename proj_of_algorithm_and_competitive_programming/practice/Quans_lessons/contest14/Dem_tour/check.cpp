long long solve(int u) {
    dfs_sz(u,0);
    int root=centroid(u,0,sz[u]);
    long long ans=0;
    del[root]=true;
    vector<pair<int,long long>>all;
    all.push_back({0,cnt[root]});
    vector<vector<pair<int,long long>>>parts;
    for(int v:g[root]) {
        if(!del[v]) {
            vector<pair<int,long long>>tmp;
            collect(v,0,1,tmp);
            all.insert(all.end(),tmp.begin(),tmp.end());
            parts.push_back(move(tmp));
        }
    }
    auto count_pairs=[](vector<pair<int,long long>>&a)->long long {
        sort(a.begin(),a.end());
        int n=a.size(), l=0, r=n-1;
        vector<long long>pref(n+1,0);
        for(int i=0; i<n; ++i) pref[i+1]=pref[i]+a[i].second;
        long long res=0;
        while(l<r) {
            if(a[l].first+a[r].first>=k) {
                res+=a[r].second*(pref[r]-pref[l]);
                --r;
            } else {
                ++l;
            }
        }
        return res;
    };
    ans=count_pairs(all);
    for(auto &part:parts) ans-=count_pairs(part);
    for(int v:g[root]) {
        if(!del[v]) ans+=solve(v);
    }
    return ans;
}