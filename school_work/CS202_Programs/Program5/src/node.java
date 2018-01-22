/*
Nick Grout
Program 5

This is the node class. It handles a LLL of nodes and has featureBase pointers as its data ("Has a" relationship).
*/
public class node {
    protected featureBase Data = null;
    protected node Next = null;

    node(){
    }

    node(node Obj){
        if( Obj.Data != null )
            Data = Obj.Data;
        else
            Data = null;

        if( Obj.Next != null )
            Next = new node(Obj.Next);
        else
            Next = null;
    }

    node(featureBase Obj) {
        Data = Obj;
    }

    public static void main(String args[]){
        featureBase Engine = new featureEngine("Engine!",
                "This is an engine test!", 356.99,1.0, 24.5,1000.0);

        featureBase Wheels = new featureWheels("Wheels",
                "This is a wheels test!", 359.9,1.0,"Somber", 21.0);

        featureBase Color = new featureColor("Test part!",
                "This is a test part cool huh?",364.99,1.0,"Stylish");


        node testNode = new node(Engine);
        node testNode2 = new node(Wheels);
        node testNode3 = new node(Color);

        testNode.insert(testNode2);
        testNode.insert(testNode3);

        System.out.print(testNode.display());
    }

    //This function uses dynamic binding to call the right display method.
    private String displayNumbered(int num){
        StringBuilder str = new StringBuilder("("+ num + ")\n");
        if( Data != null )
            str.append(Data.display());
        if( Next != null )
            str.append('\n' + Next.displayNumbered(++num));
        return str.toString();
    }

    public String displayNumbered(){
        return this.displayNumbered(1);
    }

    public String displayNames(){
        if( Data == null ) return null;
        StringBuilder str = new StringBuilder();
        str.append( Data.displayName() );
        if( Next != null )
            str.append( ", " + Next.displayNames() );
        return str.toString();
    }

    public String display(){
        StringBuilder str = new StringBuilder();
        if( Data != null )
            str.append(Data.display());
        if( Next != null )
            str.append("\n\n" + Next.display());
        return str.toString();
    }


    public node goNext(){
        if( Next == null ) return null;
        return Next;
    }

    public boolean insert(node Obj) {
        if( Obj == null ) return false;
        node temp = this;

        if( Data == null ){
            Data = Obj.Data;
            return true;
        }

        while( temp.Next != null )
            temp = temp.Next;
        temp.Next = Obj;
        return true;
    }

    public boolean insert(featureBase Obj){
        node temp = new node(Obj);
        return insert(temp);
    }

    public boolean setNext(node Obj){
        if( Next == null ) {
            Next = Obj;
        }

        else if(Obj != null){
            Obj.Next = Next;
            Next = Obj;
        }
        else
            Next = Obj;

        return true;
    }

    //Return data by ref based on the object's name
    public featureBase find(final String test){
        if( Data.compareName(test) ) {
            return Data;
        }
        if( Next != null )
            return Next.find(test);
        return null;
    }

    //return data by ref based on object's place in the LLL
    public featureBase find(int toFind){
        if( toFind <= 0 )
            return null;
        return this.findNum(--toFind, 0);
    }

    //Recursively traverse and find based on number in LLL
    private featureBase findNum(int toFind, int current){
        if( current == toFind )
            return this.Data;
        if( Next != null )
            return Next.findNum(toFind, ++current);
        return null;
    }

    //Clean up function to (hopefully) clean up the LLL on one garbageCollect pass.
    public void cleanup(){
        if( Data != null )
            Data.cleanup();
        if( Next != null )
            Next.cleanup();
        Next = null;
        return;
    }
}
