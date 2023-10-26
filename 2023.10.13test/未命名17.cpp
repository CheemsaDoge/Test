const int N = 1;
struct BIT{
    int bit[2][N], a[N], sum[N], n;
    #define lowbit(x) ((x)&(-(x)))
    inline void build(){
        for(int i = 1; i <= n; ++ i){
        	sum[i] = sum[i-1] + a[i];
        }
    }
    inline void add(int k, int node, int v){
        while(node <= n) bit[k][node] += v, node += lowbit(node);
    }
    inline int prefix(int k, int r){
        int ans = 0;
        while(r) ans += bit[k][r], r -= lowbit(r);
        return ans;
    }
    inline void Add(int l, int r, int x){
    	add(0, l, x), add(0, r + 1, -x);
    	add(1, l, l * x), add(1, r + 1, - (r + 1) * x);
	}
	inline int Query(int l, int r){
		int rr = sum[r] + (r + 1) * prefix(0, r) - prefix(1, r);
		int ll = sum[l-1] + l * prefix(0, l - 1) - prefix(1, l - 1);
		return rr - ll;
	}
};
