/*
Nick Grout
Program 4

This class handles the input/display/selection for the application program. It really acts as a wrapper for 3 different
nodes.
*/
public class nodeArray{

    //Color is index 0
    //Engine is index 1
    //Wheels is index 2
    private String [] Names = new String[3];
    //TODO change back to private
    public node [] Array = new node[3];

    nodeArray(){
        //These names are shown between each type of feature. That's how we know we're at the next feature.
        Names[0] = "COLORS:  ";
        Names[1] = "ENGINES: ";
        Names[2] = "WHEELS:  ";
        //You can just add another to Names and node here for more features.
    }

    public static void main(String args[]){
        //Constructing objects to test the array.
        featureBase Engine = new featureEngine("Engine!",
                "This is an engine test!", 356.99,1.0, 24.5,1000.0);

        featureBase Wheels = new featureWheels("Wheels",
                "This is a wheels test!", 359.9,1.0,"Somber", 21.0);

        featureBase Color = new featureColor("Test part!",
                "This is a test part cool huh?",364.99,1.0,"Stylish");

        //Constructing a new nodeArray
        nodeArray test = new nodeArray();

        //inserting the objects into the array (Duplicate to test the LLL as well)
        test.insert(Wheels);
        test.insert(Engine);
        test.insert(Color);

        System.out.print(test.display());
    }

    //The next three functions insert an object based on it's type. Since we don't want to add a reference to an object,
    //we literally want to create a new object, we need to have specific functions or do RTTI which is not something
    //I had time to learn for this assignment.
    public boolean insert(featureBase Obj){
        int index = -1;

        //Determine which array index this should go into.
        switch( Obj.getClass().getName() ) {

            case "featureWheels":
                index = 2;
                break;
            case "featureEngine":
                index = 1;
                break;
            case "featureColor":
                index = 0;
                break;
            default:
                return false;
        }

        if( Array[index] == null ) {
            Array[index] = new node(Obj);
            return true;
        }
        return Array[index].insert(Obj);
    }

    //This displays all the
    public String display(){
        StringBuilder str = new StringBuilder();

        for(int i = 0; i < 3; ++i){
            if( Array[i] != null ) {
                str.append('\n' + Names[i] + '\n');
                str.append(Array[i].display());
            }
        }
        return str.toString();
    }

    //Clean up function to (hopefully) clean up the LLL
    public void cleanup(){
        for(int i = 0; i < 3 && Array != null; ++i){
            if( Array[i] != null ) {
                Array[i].cleanup();
                Array[i] = null;
            }
            Array = null;
        }
    }

    //Color is index 0
    //Engine is index 1
    //Wheels is index 2
    /*
    These functions find and return data by reference in the LLL.
     */
    public featureBase findWheels(int num){
        return Array[2].findNum(num);
    }

    public featureBase findWheels(String name){
        return Array[2].findName(name);
    }

    public featureBase findEngine(int num){
        return Array[1].findNum(num);
    }

    public featureBase findEngine(String name){
        return Array[1].findName(name);
    }

    public featureBase findColor(int num){
        return Array[0].findNum(num);
    }

    public featureBase findColor(String name){
        return Array[0].findName(name);
    }

}
