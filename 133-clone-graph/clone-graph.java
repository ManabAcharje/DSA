/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null)return null;
        HashMap<Node , Node> mp = new HashMap<>();
        Queue<Node > q = new LinkedList<>();
        mp.put(node , new Node(node.val));
        q.offer(node);

        while(!q.isEmpty()){
            Node curr = q.poll();
            for(Node ngbr : curr.neighbors){
                if(!mp.containsKey(ngbr)){
                    mp.put(ngbr,new Node(ngbr.val));
                    q.offer(ngbr);
                }
                mp.get(curr).neighbors.add(mp.get(ngbr));
            }
        }
        return mp.get(node);
    }
}