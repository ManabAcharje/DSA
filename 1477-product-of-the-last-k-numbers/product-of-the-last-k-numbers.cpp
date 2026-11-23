class ProductOfNumbers {
public:
    vector<int>pref_product;
    int sz = 0;
    ProductOfNumbers() {
        pref_product = {1};
        sz  = 0;

    }
    
    void add(int num) {
        if(num==0){
            pref_product= {1};
            sz = 0;
            
        }else{
            pref_product.push_back(pref_product.back()*num);
            sz++;
        }
    }
    
    int getProduct(int k) {
        if(sz - k < 0 )return 0;
        return pref_product[sz]/pref_product[sz-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */