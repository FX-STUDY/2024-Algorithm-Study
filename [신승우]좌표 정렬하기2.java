import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Point {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


    static void swap(List<int[]> arr, int low, int high) {
        int temp = arr.get(low)[0];
        arr.get(low)[0] = arr.get(high)[0];
        arr.get(high)[0] = temp;

        temp = arr.get(low)[1];
        arr.get(low)[1] = arr.get(high)[1];
        arr.get(high)[1] = temp;
    }

    static int partition(List<int[]> arr, int p, int end) {
        int low = p + 1;
        int high = end;
        int pivotX = arr.get(p)[0];
        int pivotY = arr.get(p)[1];

        while (low <= high) {
            while (low <= end && (pivotY > arr.get(low)[1] || (pivotY == arr.get(low)[1] && pivotX >= arr.get(low)[0]))) low++;
            while (p < high && (pivotY < arr.get(high)[1] || (pivotY == arr.get(high)[1] && pivotX <= arr.get(high)[0]))) high--;

            if (low <= high) {
                swap(arr, low, high);
                low++;
                high--;
            }
        }
        swap(arr, p, high);
        return high;
    }

    static void quickSort(List<int[]> arr, int left, int right) {
        if (left < right) {
            int pivot = partition(arr, left, right);
            quickSort(arr, left, pivot - 1); //왼쪽 정렬
            quickSort(arr, pivot + 1, right); //오른쪽 정렬
        }
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<int[]> arr = new ArrayList<int[]>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            arr.add(new int[]{Integer.parseInt(input[0]), Integer.parseInt(input[1])});
        }
        quickSort(arr, 0, n - 1);
        for (int[] a : arr) {
            for(int i : a){
                bw.write(i + " ");
            }
            bw.newLine();
        }

        bw.flush();
        br.close();
        bw.close();
    }
}


