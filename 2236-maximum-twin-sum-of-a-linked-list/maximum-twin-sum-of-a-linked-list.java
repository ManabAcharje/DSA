/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int pairSum(ListNode head) {
        List<Integer> nums= new ArrayList<>();
        while(head!=null){
            nums.add(head.val);
            head=head.next;

        }
        int ans=0;
        int n=nums.size();
        for(int i=0; i<(n/2);i++){
            ans= Math.max(ans,nums.get(i)+nums.get(n-1-i));
        }
        return ans;
    }
}