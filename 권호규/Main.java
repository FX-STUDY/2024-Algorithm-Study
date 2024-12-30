import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for(int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            for (int j = 0; j < M; j++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
            }
            System.out.println(N - 1);
        }
    }
}


//첫 번째 줄에는 국가의 수 N(2 ≤ N ≤ 1 000)과 비행기의 종류 M(1 ≤ M ≤ 10 000) 가 주어진다.
//이후 M개의 줄에 a와 b 쌍들이 입력된다. a와 b를 왕복하는 비행기가 있다는 것을 의미한다. (1 ≤ a, b ≤ n; a ≠ b)
//주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.

// 국가의 수: 노드
// 바행기 종류: 간선
// a와 b를 왕복하는 비행기: 양방향 간선
// 항상 연결 그래프를 이룬다.
// 이 조건을 이용하면 MST -> 최소의 가중치합으로 모든 노드를 연결하는 것
// 필요간선: 노드 - 1

