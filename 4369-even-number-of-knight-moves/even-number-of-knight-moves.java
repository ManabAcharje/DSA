class Solution {
    public boolean canReach(int[] start, int[] target) {
        // if color of both source and target are same then return true
        //else return false
        int x1 = start[0];
        int y1 = start[1];

        int x2 = target[0];
        int y2 = target[1];

        return ((x1+y1)%2 == (x2+y2)%2);

    }
}