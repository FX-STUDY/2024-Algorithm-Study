import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj_6498 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        while (true) {
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            int homes = Integer.parseInt(st1.nextToken());
            int roads = Integer.parseInt(st1.nextToken());

            if (homes == 0 && roads == 0){
                break;
            }

            int[][] graph = new int[roads][3];
            int[] unions = new int[homes];
            int cost = 0, sum = 0;

            for (int i = 0; i < homes; i++) {
                unions[i] = i;
            }

            for (int i = 0; i < roads; i++) {
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                graph[i][0] = Integer.parseInt(st2.nextToken());
                graph[i][1] = Integer.parseInt(st2.nextToken());
                graph[i][2] = Integer.parseInt(st2.nextToken());
                sum += graph[i][2];
            }

            // 비용 오름차순 정렬
            Arrays.sort(graph, (o1, o2) -> {
                return o1[2] - o2[2];
            });

            for (int i = 0; i < roads; i++) {
                int firstHome = graph[i][0];
                int secondHome = graph[i][1];
                if (find(unions, firstHome) != find(unions, secondHome)) {
                    union(unions, firstHome, secondHome);
                    cost += graph[i][2];
                }
            }
            bw.write((sum - cost) + "\n"); 
        }
        bw.flush();
        bw.close();
        br.close();
    }

    private static int find(int[] unions, int x) {
        if (unions[x] != x) {
            unions[x] = find(unions, unions[x]); // 경로 압축
        }
        return unions[x];
    }

    private static void union(int[] unions, int a, int b) {
        int rootA = find(unions, a);
        int rootB = find(unions, b);
        if (rootA != rootB) {
            unions[rootB] = rootA; // 집합 병합
        }
    }
}
