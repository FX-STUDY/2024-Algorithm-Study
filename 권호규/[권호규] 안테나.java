import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int[] arr = new int[N];
        for(int i=0;i<N;i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);


        // 중앙값 중 작은 값 선택 (짝수일 경우 arr[N/2 - 1])
        int mid = (N % 2 == 0) ? (N / 2 - 1) : (N / 2);


        System.out.printf("%d", arr[mid]);
    }

}