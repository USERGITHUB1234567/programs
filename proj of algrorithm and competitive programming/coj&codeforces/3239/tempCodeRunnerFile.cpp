while(true) {
    //     bool stop=true;
    //     vector<vector<int>>bucket(m+2);
    //     for(int i=1; i<=q; ++i) {
    //         if(l[i]<r[i]) {
    //             stop=false;
    //             int mid=(l[i]+r[i])>>1;
    //             bucket[mid].pb(i);
    //         }
    //     }
    //     if(stop) break;
    //     for(int e=0; e<=m; ++e) {
    //         if(e!=0) dsu.unite(edge[e].fi,edge[e].se);
    //         for(int i:bucket[e]) {
    //             auto[x,y,z]=queries[i];
    //             int s=dsu.size_query(x,y);
    //             if(s>=z) r[i]=e;
    //             else l[i]=e+1;
    //         }
    //     }
    // }