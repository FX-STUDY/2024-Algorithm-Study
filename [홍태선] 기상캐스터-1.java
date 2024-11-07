import java.io.*;
import java.util.*;

class Boj10709 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        String[] inputs = br.readLine().split(" ");
        int H = Integer.parseInt(inputs[0]);
        int W = Integer.parseInt(inputs[1]);


        // O( H * W )
        for (int i = 0; i < H; i++) {    
            String inputStr = br.readLine().replace('c', '0');
            Queue<Integer> dotPose = new LinkedList<>();
            StringBuilder sb = new StringBuilder();

            for (int j = W - 1; j >= 0; j--) {
                if (inputStr.charAt(j) == '.') {
                    dotPose.add(j);
                    continue;
                }

                if (inputStr.charAt(j) == '0') {
                	// 최악의 경우 여기서 n 번만큼 가지고 와야 할 수도
                    while (!dotPose.isEmpty()) {
                        int diff = dotPose.peek() - j;
                        sb.insert(0, diff + " ");
                        dotPose.poll();
                    }
                    sb.insert(0, "0 ");
                }
            }

            // 큐에 남아 있는거 . -1 처리
            while (!dotPose.isEmpty()) {
                sb.insert(0, "-1 ");
                dotPose.poll();
            }

            // 마지막 공백 제거 후 출력 (trim)
            bw.write(sb.toString().trim()+"\n");
        }
        bw.flush();
        bw.close();
    }
}
