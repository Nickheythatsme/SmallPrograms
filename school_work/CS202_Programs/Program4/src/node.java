/*
Nick Grout
Program 4

This is the node class. It handles a LLL of nodes and has featureBase pointers as its data ("Has a" relationship).
*/
public class node {
    featureBase Data = null;
    node Next = null;

    node(){
    }

    node(node Obj){
        Data = null;
        Next = null;

        if( Obj.Data != null )
            Data = Obj.Data;
        if( Obj.Next != null )
            Next = new node(Obj.Next);
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
    public String display(int num){
        StringBuilder str = new StringBuilder("("+ num + ")\n");
        if( Data != null )
            str.append(Data.display());
        if( Next != null )
            str.append('\n' + Next.display(++num));
        return str.toString();
    }

    public String display(){
        return this.display(1);
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

    //Return data by ref based on the object's name
    public featureBase findName(final String test){
        if( Data.compareName(test) ) {
            return Data;
        }
        if( Next != null )
            return Next.findName(test);
        return null;
    }

    //return data by ref based on object's place in the LLL
    public featureBase findNum(int toFind){
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
