class Solution {
    public String convertDateToBinary(String date) {
        int firstHyphen = date.indexOf("-");
        String year = date.substring(0, firstHyphen);
        System.out.println(year);

        int secondHyphen = date.indexOf("-", firstHyphen + 1);
        String month = date.substring(firstHyphen + 1, secondHyphen);
        System.out.println(month);

        String day = date.substring(secondHyphen + 1);
        System.out.println(day);

        return Integer.toBinaryString(Integer.valueOf(year)) + "-" +
                Integer.toBinaryString(Integer.valueOf(month)) + "-" +
                Integer.toBinaryString(Integer.valueOf(day));
    }
}