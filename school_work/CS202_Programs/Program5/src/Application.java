/*
Nick Grout
Program 5
*/
import java.io.IOException;
import java.util.Scanner;

public class Application extends nodeArray{
    BufferedInput input;
    carLotNode head;

    Application(nodeArray Obj){
        super(Obj);
        head = null;
        try {
            input = new BufferedInput("CarLots.tsv");
            fill();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String [] args){
        Scanner Input = new Scanner(System.in);
        getSelection newApp = new getSelection();
        System.out.print("Press any key to view all choices:\n");
        Input.nextLine();
        System.out.print(newApp.display());
        newApp.selectFeatures();
        Application testLots = new Application(newApp);
        System.out.print(testLots.display());
    }

    private boolean fill() {
        car tempCar;
        carLot tempCarLot = null;
        String[] tempLine = null;


        tempLine = input.parseLines();
        while( tempLine != null ) {
            if( tempLine[0].equals("Name") ){
                if( tempCarLot != null )
                    insert( tempCarLot );
                tempCarLot = new carLotNode( tempLine[1] );
                tempLine = input.parseLines();
            }

            tempCar = new car();
            if( !tempCar.insert( super.findColor(tempLine[0]) ))
                System.out.println( tempLine[0] );
            tempCar.insert( super.findEngine(tempLine[1]) );
            tempCar.insert( super.findWheels(tempLine[2]) );
            tempCarLot.insert( new carNode(tempCar) );
            tempLine = input.parseLines();
        }
        if( tempCarLot != null )
            insert( tempCarLot );

        return true;
    }

    private boolean insert( carLot Obj ){
        if( head == null ){
            head = new carLotNode(Obj);
            return true;
        }
        //return true;
        return head.insert( Obj );
    }

    public String display(){
        if( head == null )
            return null;
        StringBuilder str = new StringBuilder("\tCar #\tFeature Match\tPrice\tList of features");
        return str.append(head.display()).toString();
    }
}
