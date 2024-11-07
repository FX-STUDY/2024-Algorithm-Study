import java.io.*;
import java.util.*;

class Boj10709_1 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        String[] inputs = br.readLine().split(" ");
        int H = Integer.parseInt(inputs[0]);
        int W = Integer.parseInt(inputs[1]);


        // O( H * W )
        for (int i = 0; i < H; i++) {    
            String inputStr = br.readLine().replace('c', '0');

            // 합산 0이면 전부 -1
                

            // Java 11 ~ 
            // long outCnt = inputStr.chars().filter(c -> c == '-').count(); // "-"의 개수를 세기
            // if(outCnt == W) {
            //     bw.write("-1 ".repeat(W).trim()+"\n");
            //     continue;
            // }
        
            int lastIndex = -1;
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < W; j++) {
                char targetChar = inputStr.charAt(j);
                if(targetChar == '0') {
                    lastIndex = j;
                    sb.append("0 ");
                    continue;
                }

                if(targetChar == '.' && lastIndex == -1) {
                    sb.append("-1 ");
                } else if(targetChar == '.' && lastIndex != -1) {
                    sb.append((j - lastIndex) + " ");
                }
            }
            bw.write(sb.toString().trim()+"\n");

        }
        bw.flush();
        bw.close();


    }
}
