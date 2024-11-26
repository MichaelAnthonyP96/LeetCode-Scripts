class Solution {
    public String convertDateToBinary(String date) {
        String year = date.substring(0, 4);

        String month = date.substring(5, 7);

        String day = date.substring(8);

        return Integer.toBinaryString(Integer.valueOf(year)) + "-" +
                Integer.toBinaryString(Integer.valueOf(month)) + "-" +
                Integer.toBinaryString(Integer.valueOf(day));
    }
}