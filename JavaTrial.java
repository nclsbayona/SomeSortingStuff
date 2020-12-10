import java.time.Duration;
import java.time.Instant;

public class JavaTrial {
    public static void main(String[] args) {
        int max = 25000000;
        double a = 0;
        for (int i = 0; i < max; ++i) {
            Instant start = Instant.now();
            Integer[] array = { 89, 144, 55, 1, 13, 21, 2, 34, 0, 1, 8, 5, 3 };
            PatienceSort<Integer> patienceSort = new PatienceSort<>(array);
            patienceSort.patienceSort();
            Instant finish = Instant.now();
            a += Duration.between(start, finish).toMillis();
            /*
             * patienceSort.addElement(233); patienceSort.patienceSort();
             */
        }
        a /= max;
        System.out.println(a);
    }
}
