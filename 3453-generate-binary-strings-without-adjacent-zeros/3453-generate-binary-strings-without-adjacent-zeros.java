class Solution {
    public List<String> validStrings(int n) {
        ArrayList<String> answer = new ArrayList<String>();
        generateStringVariations("", n, answer);
        return answer;
    }

    void generateStringVariations(String s, int n, ArrayList<String> ans) {
        if (s.length() == n) {
            ans.add(s);
            return;
        }

        generateStringVariations(s + '1', n, ans);

        if (s.isEmpty() || !s.endsWith("0")) {
            generateStringVariations(s + '0', n, ans);
        }
    }
}