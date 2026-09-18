class Solution {
    String s, t;

    void rev(StringBuilder num) {
        num.reverse();
    }

    String solve(int i) {
        StringBuilder res = new StringBuilder();
        int carry = 0;
        for (int j = t.length() - 1; j >= 0; j--) {
            int a = t.charAt(j) - '0';
            int b = s.charAt(i) - '0';
            int curr = a * b + carry;
            res.append((char) (curr % 10 + '0'));
            carry = curr / 10;
        }
        if (carry > 0)
            res.append((char) (carry + '0'));
        rev(res);
        res.append("0".repeat(s.length() - 1 - i));
        return res.toString();
    }

    String add(String a, String b) {
        StringBuilder res = new StringBuilder();

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a.charAt(i--) - '0';
            }
            if (j >= 0) {
                sum += b.charAt(j--) - '0';
            }
            res.append((char) (sum % 10 + '0'));
            carry = sum / 10;
        }
        return res.reverse().toString();
    }

    public String multiply(String s, String t) {
        this.s = s;
        this.t = t;
        if (s.equals("0") || t.equals("0"))
            return "0";
        String ans = "0";

        for (int i = s.length() - 1; i >= 0; i--) {
            ans = add(ans, solve(i));

        }
        return ans;
    }
}