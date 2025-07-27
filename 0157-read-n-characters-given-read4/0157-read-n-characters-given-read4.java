/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf4);
 */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        int count = 0;
        int copiedChars = 0;
        char[] internalBuf = new char[4];
        int readChars = read4(internalBuf);
        while(readChars > 0 && count < n) {
            for (int i = 0; i < readChars; ++i) {
                // if (copiedChars == n) return copiedChars;
                buf[copiedChars] = internalBuf[i];
                ++copiedChars;
            }
            count += readChars;
            readChars = read4(internalBuf);
        }
        
        return count > n ? n : count;
    }
}