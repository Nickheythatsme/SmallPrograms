/*
Nick Grout
Program 5
*/
import java.util.Random;

public class car{
    private node head = null;
    private double TotalPriority;

    car(){

    }

    car(car Obj){
        if( Obj.head != null )
            head = new node(Obj.head);
        else
            head = null;
        TotalPriority = Obj.TotalPriority;
    }

    public static void main(String [] args){
        Random randObj = new Random();
        car testCar = new car();
        featureBase tempBase;
        loadFeatures load = new loadFeatures();

        for(int i = 0; i < 3; ++i) {
            tempBase = load.pop();
            tempBase.incrementPriority( (double)randObj.nextInt(100) );
            testCar.insert(tempBase);
        }


        System.out.print(testCar.display());
    }

    //Insert the features in sorted order based on their priority
    public boolean insert(featureBase Obj) {
        if( Obj == null ) return false;
        node newNode = new node(Obj);
        node temp;
        TotalPriority += Obj.returnPriority();

        if( head == null ) {
            head = newNode;
            return true;
        }

        if( Obj.returnPriority() > head.Data.returnPriority() ) {
            newNode.setNext(head);
            head = newNode;
            return true;
        }

        temp = head;
        while( temp.goNext() != null && temp.Next.Data.returnPriority() >= Obj.returnPriority() ){
            temp = temp.goNext();
        }
        temp.setNext(newNode);

        return true;
    }

    public String display() {
        if( head == null ) return null;
        String str = new String( head.display() + '\n' );
        return str;
    }

    public String displayNames(){
        if( head == null ) return null;
        return head.displayNames();
    }

    protected double compare(car Obj){
        return TotalPriority - Obj.TotalPriority;
    }

    protected double returnPriority(){
        double realTotal = 0.0;
        realTotal = TotalPriority / 30;
        return realTotal * 10;
    }

    protected double returnCost(){
        double total = 0;
        node temp = head;
        while( temp != null ){
            total += temp.Data.returnCost();
            temp = temp.goNext();
        }
        return total;
    }

}
