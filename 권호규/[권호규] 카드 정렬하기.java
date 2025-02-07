import java.io.*;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Long> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            pq.add(Long.parseLong(br.readLine()));
        }

        long sum = 0;

        // ❗ pq의 크기가 2 이상일 때만 실행해야 함
        while (pq.size() > 1) {
            long a = pq.poll();
            long b = pq.poll();

            long tempSum = a + b;
            sum += tempSum;

            pq.add(tempSum);  // 새로운 합산 값 삽입
        }

        System.out.println(sum);
    }
}