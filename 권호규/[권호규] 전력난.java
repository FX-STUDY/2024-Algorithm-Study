import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge> {
    int start;
    int end;
    int weight;

    Edge(int start, int end, int weight) {
        this.start = start;
        this.end = end;
        this.weight = weight;
    }
    

    @Override
    public int compareTo(Edge other) {
        return this.weight - other.weight;
    }
}

public class Main {

    static int[] parent;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken()); // 정점의 개수
            int N = Integer.parseInt(st.nextToken()); // 간선의 개수

            if (M == 0 && N == 0) {
                break; // 종료 조건
            }

            List<Edge> edgeList = new ArrayList<>();
            int totalCost = 0;

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());

                edgeList.add(new Edge(x, y, z));
                totalCost += z; // 전체 비용 계산
            }

            Collections.sort(edgeList); // 가중치 오름차순 정렬

            parent = new int[M];
            for (int i = 0; i < M; i++) {
                parent[i] = i;
            }

            int minCost = 0;
            for (Edge edge : edgeList) {
                if (find(edge.start) != find(edge.end)) { // 사이클이 생성되지 않을 때
                    union(edge.start, edge.end);
                    minCost += edge.weight; // MST 비용에 추가
                }
            }

            System.out.println(totalCost - minCost); // 절약된 비용 출력
        }
    }

    // 유니온-파인드에서 루트 노드 찾기
    public static int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }


    // 두 노드를 합치기
    public static void union(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            parent[y] = x;
        }
    }
}