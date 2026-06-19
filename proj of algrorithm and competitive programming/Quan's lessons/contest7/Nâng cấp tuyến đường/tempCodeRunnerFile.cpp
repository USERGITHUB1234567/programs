pq.push({st,0,false});
    // for(int i=1; i<=n; ++i) d[0][i][t]=d[1][i][t]=inf;
    // while(!pq.empty()) {
    //     auto[u,cd,imp]=pq.top();pq.pop();
    //     if(cd>d[imp][u][t]) continue;
    //     for(auto[v,w]:adj[u]) {
    //         if(d[imp][v][t]>cd+w) {d[imp][v][t]=cd+w,pq.push({v,cd+w,imp});}
    //         if(!imp) {
    //             w=t;
    //             imp=true;
    //             if(d[imp][v][t]>cd+w) {d[imp][v][t]=cd+w,pq.push({v,cd+w,imp});}
    //         }
    //     }
    // }