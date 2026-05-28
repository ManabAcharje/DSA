class Solution {
public:
    vector<int>rank,parent;
    int find(int  x) {

        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int  x, int  y){
        int px=find(x);
        int py=find(y);
        if(px==py)return ;
        if(px < py )
        {
            parent[py]=px;
        }
        else
        
        {
            parent[px]=py;
        }

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();


        // rank.resize(26,0);
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a')+'a';
        }
        return baseStr;
    }
};