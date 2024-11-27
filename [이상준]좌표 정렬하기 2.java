import java.io.*;
import java.util.ArrayList;


public class Boj_11651_2 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        ArrayList<int[]> points = new ArrayList<>();

        for(int i = 0 ; i < n; i++){
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            int[] point = {x, y};
            points.add(point);
        }

        points.sort((a, b) -> {
            if (a[1] == b[1]){
                return a[0] - b[0];
            }else{
                return a[1] - b[1];
            }
        });

        for (int[] point : points) {
            bw.write(point[0] + " " + point[1] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

}
