import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        String book = in.readLine();
        String keyword = in.readLine();

        int keywordLength = keyword.length();

        int keywordIndex = 0;
        for (int i = 0; i < book.length(); i++) {

            if (Character.isDigit(book.charAt(i))) {
                continue;
            }

            // book index 와 keyword 의 인덱스를 비교하고 맞다면 증가, 다른 문자라면 index 를 초기화
            if (book.charAt(i) == keyword.charAt(keywordIndex)) {
                keywordIndex = keywordIndex + 1;

                if (keywordIndex == keywordLength) {
                    out.write("1");
                    out.close();
                    return;
                }

            } else {
                // ababcabd
                // abc
                if (keywordIndex > 0) {
                    i = i - keywordIndex;
                }
                keywordIndex = 0;
            }
        }

        out.write("0");
        out.close();

    }

}
