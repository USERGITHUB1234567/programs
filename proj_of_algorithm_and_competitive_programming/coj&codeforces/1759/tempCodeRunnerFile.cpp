for(int j=1; j<=17; j++) {
        for(int i=1; i<=n; i++) par[i][j]=par[par[i][j-1]][j-1];
    }