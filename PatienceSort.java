import java.util.ArrayList;

public class PatienceSort<T extends Comparable<T>> {
    private ArrayList<T> vector;

    public PatienceSort(T[] elements) {
        this.vector = new ArrayList<T>();
        for (T element : elements)
            this.vector.add(element);
    }

    public void patienceSort(){
        ArrayList<ArrayList<T>> vecStacks=new ArrayList<>();
        for (T element:this.vector){
            boolean inserted=false;
            for (int i=0;i<vecStacks.size()&&!inserted;++i){
                ArrayList<T> stack=vecStacks.get(i);
                if (stack.get(stack.size()-1).compareTo(element)>=0){
                    inserted=true;
                    stack.add(element);
                }
            }
            if (!inserted){
                ArrayList<T> stack=new ArrayList<>();
                stack.add(element);
                vecStacks.add(stack);
            }
        }
        for (ArrayList<T> arrayList:vecStacks){

        }
    }
}