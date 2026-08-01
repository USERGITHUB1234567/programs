tree mer(const tree& a, const tree& b) {
            tree ans;
            ans.sum = a.sum + b.sum;
            ans.l = max(a.l, a.sum + b.l);                  // Max Prefix sum
            ans.r = max(b.r, b.sum + a.r);                  // Max Suffix sum
            ans.mx = max({a.mx, b.mx, a.r + b.l});          // Max contiguous subarray sum
            return ans;
        }