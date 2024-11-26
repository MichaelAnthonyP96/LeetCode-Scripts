class Solution {
    public String convertDateToBinary(String date) {
        String year = date.substring(0, 4);
        System.out.println(year);

        String month = date.substring(5, 7);
        System.out.println(month);

        String day = date.substring(8);
        System.out.println(day);

        return Integer.toBinaryString(Integer.valueOf(year)) + "-" +
                Integer.toBinaryString(Integer.valueOf(month)) + "-" +
                Integer.toBinaryString(Integer.valueOf(day));
    }
}