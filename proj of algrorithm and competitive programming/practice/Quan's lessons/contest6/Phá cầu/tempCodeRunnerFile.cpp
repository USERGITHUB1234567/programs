bfs(p1);
        for(int i=1; i<=ncomp; ++i) {
            if(d[i]>mx) {
                p2=i;
                mx=d[i];
            }
        }