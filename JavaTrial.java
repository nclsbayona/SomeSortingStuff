public class JavaTrial {
    public static void main(String[] args) {
        Integer[] array={89, 144, 55, 1, 13, 21, 2, 34, 0, 1, 8, 5, 3};
        PatienceSort<Integer> patienceSort=new PatienceSort<>(array);
        patienceSort.patienceSort();
    }
}
