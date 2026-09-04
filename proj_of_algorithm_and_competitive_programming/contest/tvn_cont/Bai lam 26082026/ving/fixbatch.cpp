namespace souptrau{
    long long f[maxn];
    long long suf[maxn]; // Dùng mảng hậu tố thay cho tiền tố
    
    void implement() {
        // Tính mảng hậu tố cho F (hệ số chi phí)
        suf[n + 1] = 0;
        for(int i = n; i >= 1; --i) {
            suf[i] = suf[i + 1] + batch[i].second;
            f[i] = 1e18; // Khởi tạo DP bằng vô cực
        }
        f[0] = 0; // Trạng thái cơ sở: 0 công việc tốn chi phí 0
        
        for(int i = 1; i <= n; ++i) {
            long long sumT = 0; 
            for(int j = i - 1; j >= 0; --j) {
                // Thêm T của công việc j+1 vào khối hiện tại
                sumT += batch[j + 1].first; 
                
                // Khối từ j+1 đến i gây trễ cho tất cả công việc từ j+1 đến N
                long long sumF = suf[j + 1]; 
                
                if(f[i] > f[j] + (s + sumT) * sumF) {
                    f[i] = f[j] + (s + sumT) * sumF;
                }
            }
        }
        cout << f[n] << '\n';
    }
}