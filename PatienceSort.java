import java.util.ArrayList;
public class PatienceSort<T extends Comparable<T>> {
    private ArrayList<T> vector;

    public PatienceSort(T[] elements) {
        this.vector = new ArrayList<T>();
        for (T element : elements)
            this.vector.add(element);
    }

    public ArrayList<T> getVector() {
        return this.vector;
    }

    public void addElement(T element) {
        this.vector.add(element);
    }

    public void patienceSort() {
        ArrayList<ArrayList<T>> vecStacks = new ArrayList<>();
        int size = this.vector.size();
        for (T element : this.vector) {
            boolean inserted = false;
            for (int i = 0; i < vecStacks.size() && !inserted; ++i) {
                ArrayList<T> stack = vecStacks.get(i);
                if (stack.get(stack.size() - 1).compareTo(element) >= 0) {
                    inserted = true;
                    stack.add(element);
                }
            }
            if (!inserted) {
                ArrayList<T> stack = new ArrayList<>();
                stack.add(element);
                vecStacks.add(stack);
            }
        }
        this.vector.clear();
        for (int i = 0; i < size; ++i)
            getLowest(vecStacks);
        //System.out.println(this.vector);
    }

    private void getLowest(ArrayList<ArrayList<T>> vecStacks) {
        T lowest = null;
        int index = -1;
        for (int i = 0; i < vecStacks.size() && !vecStacks.isEmpty(); ++i) {
            ArrayList<T> stack = vecStacks.get(i);
            if (lowest == null || lowest.compareTo(stack.get(stack.size() - 1)) > 0) {
                index = i;
                lowest = stack.get(stack.size() - 1);
            }
        }
        if (index != -1) {
            vecStacks.get(index).remove(lowest);
            if (vecStacks.get(index).isEmpty())
                vecStacks.remove(index);
            this.vector.add(lowest);
        }
    };
}