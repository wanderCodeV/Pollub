public class BinarySystem {
    public String toBinary(int n) {
        String binary = Integer.toBinaryString(n);
        return binary;
    }
    public int maxSubStringZero(String num) {
        int cnt = 0, maxCnt = 0;
        for (int i = 0; i < num.length(); i++) {
            if (num.charAt(i) == '0')
                cnt++;
            else
            {
                if(cnt > maxCnt)
                    maxCnt = cnt;
                cnt = 0;
            }
        }
        return maxCnt;
    }
}
