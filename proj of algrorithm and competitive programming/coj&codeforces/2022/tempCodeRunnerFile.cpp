while (t--) {
        long long n;
        cin >> n;
        n++;
        if(n<=2) {cout << 1 << '\n';continue;}
        matrix r=power(m,n-2);
        cout << (r.a[1][0]+r.a[1][1])%mod << '\n';
    }