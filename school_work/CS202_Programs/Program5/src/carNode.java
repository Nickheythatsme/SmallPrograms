/*
Nick Grout
Program 5
*/
import java.util.Random;

public class carNode extends car{
    //Color is index 0
    //Engine is index 1
    //Wheels is index 2
    protected carNode left = null;
    protected carNode right = null;

    carNode(car Obj){
        super(Obj);
        left = null;
        right = null;
    }

    carNode(carNode Obj){
        super(Obj);
        if( Obj.left != null )
            left = new carNode(Obj.left);
        else
            left = null;

        if( Obj.right != null )
            right = new carNode(Obj.right);
        else
            right = null;
    }

    public static void main(String [] args){
        Random randObj = new Random();
        car testCar = new car();
        featureBase tempBase = null;
        loadFeatures load = new loadFeatures();
        carNode testNode = null;
        carNode testNode2 = null;

        for(int j = 0; j < 3; ++j) {
            tempBase = load.pop();
            tempBase.incrementPriority( (double)randObj.nextInt(100) );
            testCar.insert(tempBase);
        }
        testNode = new carNode(testCar);

        for(int i = 0; i < 4; ++i ) {
            testCar = new car();

            for(int j = 0; j < 3; ++j) {
                tempBase = load.pop();
                tempBase.incrementPriority( (double)randObj.nextInt(100) );
                testCar.insert(tempBase);
            }
            testNode.insert( testCar );
        }

        testNode2 = new carNode(testNode);
        System.out.print(testNode2.display());
    }

    public String display(){
        int [] num = new int[1];
        num[0] = 1;
        return this.display(num);
    }

    private String display(int [] num){
        StringBuilder str = new StringBuilder();

        if( left != null ){
            str.append( left.display(num) );
            num[0]++;
        }

        str.append( String.format("\t %2d)", num[0]) );
        str.append( String.format( "%10.2f\t%.2f\t%s\n",
                super.returnPriority(), super.returnCost(), super.displayNames()) );

        if( right != null ){
            ++num[0];
            str.append( right.display(num) );
        }
        return str.toString();
    }

    public boolean insert(car Obj){
        if( super.compare(Obj) <= 0 )
            return this.insertLeft(Obj);
        return this.insertRight(Obj);
    }

    private boolean insertLeft(car Obj){
        if( left == null ) {
            left = new carNode(Obj);
            return true;
        }
        return left.insert(Obj);
    }

    private boolean insertRight(car Obj){
        if( right == null ) {
            right = new carNode(Obj);
            return true;
        }
        return right.insert(Obj);
    }
}

