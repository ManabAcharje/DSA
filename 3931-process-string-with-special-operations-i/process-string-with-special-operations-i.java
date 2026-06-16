class Solution {
    public String processStr(String s) {
        StringBuilder result = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch >= 'a' && ch <= 'z') {
                result.append(ch);
            } else if (ch == '*') {
                if (result.length() >= 1) {
                    result.deleteCharAt(result.length() - 1);
                }
            } else if (ch == '#') {
                if (result.length() >= 1) {
                    result.append(result);
                }

            } else {
                if (result.length() >= 1) {
                    result.reverse();
                }
            }
        }
        return result.toString();
    }
}