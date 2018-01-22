/*
Nick Grout
Program 5
*/
public class carLotNode extends carLot{
    protected carLotNode right;
    protected carLotNode left;

    carLotNode(String name){
        super(name);
        right = null;
        left = null;
    }

    carLotNode(carLot Obj){
        super(Obj);
        right = null;
        left = null;
    }

    public String display(){
        StringBuilder str = new StringBuilder();
        if( left != null )
            str.append( left.display() );
        str.append('\n');
        str.append( super.display() );
        if( right != null )
            str.append( right.display() );
        return str.toString();
    }

    public boolean insert(carLot Obj){
        if( super.compare(Obj) >= 0 )
            return insertLeft(Obj);
        return insertRight(Obj);
    }

    private boolean insertRight(carLot Obj){
        if( right == null ){
            right = new carLotNode(Obj);
            return true;
        }
        return right.insert(Obj);
    }

    private boolean insertLeft(carLot Obj){
        if( left == null ){
            left = new carLotNode(Obj);
            return true;
        }
        return left.insert(Obj);
    }

}
