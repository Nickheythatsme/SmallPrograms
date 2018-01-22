/*
Nick Grout
Program 4

This class is an extension of featureBase. It handles all the variation for the wheels.
*/
public class featureWheels extends featureBase{
    private double RimSize = -1.0;
    private String Style = null;

    featureWheels(){
        super();
    }

    featureWheels(final featureWheels Obj){
        super(Obj);
        Style = Obj.Style;
        RimSize = Obj.RimSize;
    }

    featureWheels(final featureBase Obj, String newStyle, double newRimSize){
        super(Obj);
        Style = new String(newStyle);
        RimSize = newRimSize;
    }

    featureWheels(String newName, String newDescrip, double newCost, double newPriority, String newStyle, double newRimeSize){
        super(newName,newDescrip,newCost,newPriority);
        RimSize = newRimeSize;
        Style = newStyle;
    }

    public static void main(String args[]){
        featureWheels Wheels = new featureWheels("Wheels",
                "This is a wheels test!", 359.9,1.0,"Somber", 21.0);
        System.out.print(Wheels.display());

    }

    public String display(){
        StringBuilder toReturn = new StringBuilder(super.display());
        if( Style != null )
            toReturn.append("Style: " + Style + '\n');
        if( RimSize > 0 )
            toReturn.append("Rim Size: " + RimSize + '\n');
        return toReturn.toString();
    }

    public void cleanup(){
        Style = null;
        RimSize = -1;
    }

    public boolean equals(final featureWheels Obj) {
        if (!super.equals(Obj)) return false;
        return Style == Obj.Style;
    }

}
