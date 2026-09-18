class Solution {
    public String longestWord(String[] words) {

        Set<String> wordSet = new HashSet<>();

        for (String word : words) {
            wordSet.add(word);
        }

        Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {

                if (b.length() != a.length()) {
                    return b.length() - a.length();
                }

                return a.compareTo(b);
            }
        });

        for (String word : words) {

            boolean good = true;

            for (int k = 1; k < word.length(); ++k) {

                if (!wordSet.contains(word.substring(0, k))) {
                    good = false;
                    break;
                }
            }

            if (good) {
                return word;
            }
        }

        return "";
    }
}