while(true) {
        bool stop=true;
        vector<vector<int>>bucket(q+2);
        for(int i=1; i<=n; ++i) {
            if(l[i]<r[i]) {
                stop=false;
                bucket[(l[i]+r[i])>>1].pb(i);
            }
        }
        if(stop) break;
        fenwick_tree fen1(n),fen2(n);
        for(int year=1; year<=q; ++year) {
            auto[f,x,d]=queries[year];
            fen1.range_update(tin[f],tout[f],x-depth[f]*d);
            fen2.range_update(tin[f],tout[f],d);
            for(int i:bucket[year]) {
                long long sum=0;
                for(int j:fac[i]) {
                    sum+=fen1.query(tin[j])+fen2.query(tin[j]);
                    if(sum>=t[i]) break;
                }
                if(sum>=t[i]) l[i]=year;
                else r[i]=year-1;
            }
        }
    }