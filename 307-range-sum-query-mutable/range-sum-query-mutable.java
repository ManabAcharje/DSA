class NumArray {

    int n;
    int [] seg;
    public NumArray(int[] nums) {
        n=nums.length;
        seg = new int[4*n];
        build(0,0,n-1,nums);
    }
    void build(int node , int l ,int r, int[] nums){
        if(l  == r ){
            seg[node] = nums[l] ;
            return ;
        }

        int mid = l + (r-l)/2;
        build(2*node+1,l,mid,nums);
        build(2*node+2 , mid+1, r, nums);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    
    void updateSeg(int node, int l , int r, int idx , int val) {
        if(l == r){
            seg[node] = val;
            return ;

        }
        int mid = l+ (r-l)/2;
        if(idx <=mid){
            updateSeg(2*node+1,l, mid, idx ,val);

        }
        else{
             updateSeg(2*node+ 2 , mid+1, r, idx, val);
        }
        seg[node]= seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    int query(int node , int l , int r, int ql, int qr){
        if(qr < l || r<ql)return 0;
        if(ql <= l && r<=qr){
            return seg[node];
        }
        int mid = l+(r-l)/2;
        return query(2*node +1 , l, mid, ql, qr)+ query(2*node + 2 ,mid+1,r,ql,qr);
    }
    public void update(int index, int val) {
        updateSeg(0,0,n-1,index,val);
    }
    
    public int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */