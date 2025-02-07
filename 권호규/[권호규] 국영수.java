import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        List<Student> students = new ArrayList<Student>();

        String name;
        int koreanScore;
        int englishScore;
        int mathScore;

        // 학생 정보 입력
        for (int i = 0; i < n; i++) {
            name = sc.next();
            koreanScore = sc.nextInt();
            englishScore = sc.nextInt();
            mathScore = sc.nextInt();
            sc.nextLine();

            students.add(new Student(name, koreanScore, englishScore, mathScore));
        }

        // 정렬 수행
        Collections.sort(students);

        // 정렬된 학생 정보 출력
        for (Student student : students) {
            System.out.println(student.getName());
        }

        sc.close();
    }
}

class Student implements Comparable<Student> {
    private String name;
    private int koreanScore;
    private int englishScore;
    private int mathScore;

    public Student(String name, int koreanScore, int englishScore, int mathScore) {
        this.name = name;
        this.koreanScore = koreanScore;
        this.englishScore = englishScore;
        this.mathScore = mathScore;
    }

    public String getName() {
        return name;
    }

    // 정렬 기준 구현
    @Override
    public int compareTo(Student other) {
        // 1. 국어 점수가 높은 순서로 정렬
        if (this.koreanScore != other.koreanScore) {
            return other.koreanScore - this.koreanScore;
        }

        // 2. 국어 점수가 같다면, 영어 점수가 낮은 순서로 정렬
        if (this.englishScore != other.englishScore) {
            return this.englishScore - other.englishScore;
        }

        // 3. 국어와 영어 점수가 같다면, 수학 점수가 높은 순서로 정렬
        if (this.mathScore != other.mathScore) {
            return other.mathScore - this.mathScore;
        }

        // 4. 모든 점수가 같다면, 이름을 사전순으로 정렬
        return this.name.compareTo(other.name);
    }
}