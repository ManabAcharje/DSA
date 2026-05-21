class Solution {
    public boolean possibleBipartition(int n, int[][] arr) {
        HashMap<Integer,ArrayList<Integer>>map=new HashMap();
        for(int i=0;i<n;i++){
            map.put(i,new ArrayList<>());

        }
        for(int i=0;i<arr.length;i++){
            int u=arr[i][0];
            int v=arr[i][1];
            map.get(u-1).add(v-1);
            map.get(v-1).add(u-1);
        }
        int[]  color=new int[n];
        Arrays.fill(color,-1);
        for(int i=0;i<n;i++){
            if(color[i]!=-1){
                continue;
            }
            Queue <Integer>q=new LinkedList();
            q.add(i);
            color[i]=0;
            while(!q.isEmpty()){
                int curr=q.poll();
                for(int ngbrs: map.get(curr)){
                    if(color[ngbrs]==-1){
                        color[ngbrs]=1-color[curr];
                        q.add(ngbrs);
                    }
                    else if(color[ngbrs]==color[curr]){
                        return false;
                    }
                }
            }

        }
        return true;
    }
}