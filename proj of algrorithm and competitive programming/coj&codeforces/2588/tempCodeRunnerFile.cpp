while(r<=n) {
        int i=r+1;
        now=f(cur);
        ans=max(ans,now);
        cout << r << ' ' << ans << '\n';
        if(now<0 && mk[i].m<abs(now)) {
            while(r<mk[i].r) add(++r,cur);
            while(l<mk[i].l && r-l-1>=k) rem(l++,cur);
        }else {
            add(++r,cur);
        }
    }
    cout << ans;