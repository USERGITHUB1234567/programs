sort(node.begin(),node.end(),[&](int a, int b) {return tin[a]<tin[b];});
        // for(int i=1; i<node.size(); ++i) {
        //     node.push_back(lca(node[i-1],node[i]));
        // }
        // sort(node.begin(),node.end(),[&](int a, int b) {return tin[a]<tin[b];});
        // for(int i=1; i<node.size(); ++i) {
        //     add_edge(node[i],lca(node[i],node[i-1]));
        // }