import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj_1303 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static int n;
    private static int m;
    private static char[][] field;
    private static boolean[][] visited;
    //상하좌우
    private static final int[] dx = {0, 0, -1, 1};
    private static final int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());//가로(열?)
        m = Integer.parseInt(st.nextToken());//세로(행?)

        field = new char[m][n];
        visited = new boolean[m][n];

        for (int row = 0; row < m; row++) {
            String input = br.readLine();
            for (int col = 0; col < n; col++) {
                field[row][col] = input.charAt(col);
            }
        }

        int wPower = 0;
        int bPower = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col]) {
                    char team = field[row][col];
                    int power = bfs(row, col, team);
                    if (team == 'W') {
                        wPower += power * power;
                    } else {
                        bPower += power * power;
                    }
                }
            }
        }

        bw.write(wPower + " " + bPower + "\n");
        bw.flush();
        br.close();
        bw.close();
    }

    public static int bfs(int row, int col, char team) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row, col});
        visited[row][col] = true;
        int count = 1;

        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            int curRow = now[0];
            int curCol = now[1];

            for (int i = 0; i < 4; i++) {
                int newRow = curRow + dy[i];
                int newCol = curCol + dx[i];
                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n
                        && !visited[newRow][newCol] && field[newRow][newCol] == team) { //field 안에 있고 방문여부 & 같은팀인지 확인
                    visited[newRow][newCol] = true;
                    queue.add(new int[]{newRow, newCol});
                    count++;
                }
            }
        }

        return count;
    }
}
