/*
Nick Grout
Program 5
*/
public class carLot {
    protected carNode head = null;
    protected int count = 0;
    protected String Name = null;

    carLot(String newName){
        Name = newName;
        head = null;
        count = 0;
    }

    carLot(carLot Obj){
        Name = Obj.Name;
        if( Obj.head != null )
            head = new carNode( Obj.head );
        else
            head = null;
    }

    public static void main(String [] args){
        carLot testLot = new carLot("This is a lot!");
        System.out.print( testLot.display() );
    }

    public boolean insert(car Obj){
        ++count;
        if( head == null ){
            head = new carNode(Obj);
            return true;
        }
        return head.insert(Obj);
    }

    public String display(){
        StringBuilder str = new StringBuilder("Car Lot Name: " + Name + "\n");
        if( head != null )
            str.append( head.display() );
        else
            str.append("No cars on this lot!");
        return str.toString();
    }

    public int compare(carLot toCompare){
        return Name.compareTo(toCompare.Name);
    }

}
