import java.util.*;
import java.io.*;

class Boj11651_optimization_1 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final List<Pair> coordinatesList;

    static {
    	coordinatesList = new ArrayList<>();
    }

    // Pair 클래스에 Comparable 구현
    private static class Pair implements Comparable<Pair> {
        private int x;
        private int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return this.x;
        }

        public int getY() {
            return this.y;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.y != other.y) {
                return Integer.compare(this.y, other.y); // y값 기준 오름차순
            }
            return Integer.compare(this.x, other.x); // y값이 같으면 x값 기준 오름차순
        }
   }

    public static void main(String[] args) throws IOException {
        solution();
    }

    private static void solution() throws IOException {
        // n 값을 읽음
        int n = Integer.parseInt(br.readLine());

        // n 만큼 입력
        for (int i = 0; i < n; i++) {
            String[] strArr = br.readLine().split(" ");
            int x = Integer.parseInt(strArr[0]);
            int y = Integer.parseInt(strArr[1]);
            coordinatesList.add(new Pair(x, y));
        }

      
        Collections.sort(coordinatesList); // Tim Sort


        // 결과 출력
        for (Pair pair : coordinatesList) {	
            bw.write(pair.getX() + " " + pair.getY() + "\n");	
        }

        // flush 는 모든 데이터를 다 작성한 뒤에 한 번에 출력하는게 효율적이다.
        bw.flush();
    }
}
