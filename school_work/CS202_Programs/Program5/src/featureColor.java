/*
Nick Grout
Program 5

This class is an extension of featureBase. It handles all color variations for the cars.
*/

public class featureColor extends featureBase{
    //Color name is handled by featureBase
    private String Mood = null;

    featureColor(String newName, String newDescrip, double newCost, double newPriority, String newMood){
        super(newName, newDescrip, newCost, newPriority);
        Mood = newMood;
    }

    featureColor(final featureBase Obj, String newMood){
        super(Obj);
        Mood = new String(newMood);
    }

    featureColor(){
        super();
    }

    featureColor(final featureColor Obj){
        super(Obj);
        if( Obj.Mood != null )
            Mood = new String(Obj.Mood);
    }

    public static void main(String args[]){
        featureBase test = new featureColor("Test part!","This is a test part cool huh?",364.99,1.0,"Stylish");
        System.out.print(test.display());
    }

    public String display(){
        StringBuilder returnStr = new StringBuilder(super.display());
        if( Mood != null )
            returnStr.append("Mood: " + Mood + '\n');
        return returnStr.toString();
    }

    public void cleanup(){
        super.cleanup();
        Mood = null;
    }

    public boolean equals(final featureColor Obj){
        if( !super.equals(Obj) ) return false;
        return Mood == Obj.Mood;
    }
}
