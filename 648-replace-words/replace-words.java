class Solution {
    class TrieNode{
        TrieNode[] child;
        boolean isEnd;

        TrieNode(){
            child =new TrieNode[26];
            isEnd=false;
        }
    }
    TrieNode root=new TrieNode();

    void buildTrie(List <String> dictionary){
        for(String word: dictionary){
            
            TrieNode curr= root;
            for(char ch:word.toCharArray()){
                int idx=ch-'a';
                if(curr.child[idx]==null){
                    curr.child[idx]= new TrieNode();
                }
                curr=curr.child[idx];
            }
            curr.isEnd=true;
        }
    }
    String search(String word){
        TrieNode curr= root;
        StringBuilder temp= new StringBuilder();

        for(char ch: word.toCharArray()){
            int idx=ch-'a';

            if(curr.child[idx]==null){
                return word;
            }
            temp.append(ch);
            curr=curr.child[idx];
            if(curr.isEnd){
                return temp.toString();
            }

        }
        return word;
    }
    public String replaceWords(List<String> dictionary, String sentence) {
        buildTrie(dictionary);
        String[] words= sentence.split(" ");
        StringBuilder ans= new StringBuilder();
        boolean first = true;
        for(String word  : words){
            if(!first){
                ans.append(" ");
                
            }
            ans.append(search(word));
            first =false;
        }
        return ans.toString();
        
    }
}