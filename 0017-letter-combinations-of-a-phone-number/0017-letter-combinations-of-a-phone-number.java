class Solution {
    
    public static Map<Character, List<Character>> digitMapping = new HashMap<>();
    
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return new ArrayList<>();
        }

        digitMapping.put('2', List.of('a', 'b', 'c'));
        digitMapping.put('3', List.of('d', 'e', 'f'));
        digitMapping.put('4', List.of('g', 'h', 'i'));
        digitMapping.put('5', List.of('j', 'k', 'l'));
        digitMapping.put('6', List.of('m', 'n', 'o'));
        digitMapping.put('7', List.of('p', 'q', 'r', 's'));
        digitMapping.put('8', List.of('t', 'u', 'v'));
        digitMapping.put('9', List.of('w', 'x', 'y', 'z'));
        
        ArrayList<String> combinations = new ArrayList<>();
        combinations.add("");
        
        return recurse(digits, combinations);
    }
    
    public ArrayList<String> recurse(String digits, ArrayList<String> combinations) {
        if (digits.isEmpty()) {
            return combinations;
        }

        ArrayList<String> localCombinations = new ArrayList<>();
        for (String combination : combinations) {
            for (Character digit : digitMapping.get(digits.charAt(0))) {
                localCombinations.add(combination + digit); 
            }
        }

        return recurse(digits.substring(1), localCombinations);
    }
    
    public static List<String> getChars(char c) {
        switch (c) {
            
            default:
                throw new RuntimeException("Invald char: " + c);
        }
    }
}