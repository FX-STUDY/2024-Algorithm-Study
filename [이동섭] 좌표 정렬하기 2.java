import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class BOJ11651 {

    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(in.readLine());

        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] xy = in.readLine().split(" ");

            arr[i][0] = Integer.parseInt(xy[0]);
            arr[i][1] = Integer.parseInt(xy[1]);

        }

        Arrays.sort(arr, (arr1, arr2) -> {
            if (arr1[1] == arr2[1]) {
                return arr1[0] - arr2[0];
            }
            return arr1[1] - arr2[1];
        });

        for (int i = 0; i < n; i++) {
            out.write(arr[i][0] + " " + arr[i][1] + "\n");
        }
        out.close();
    }

}
