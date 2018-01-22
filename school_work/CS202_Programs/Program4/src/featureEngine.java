/*
Nick Grout
Program 4

This class is an extension of FeatureBase. It handles all engine variations.

*/
public class featureEngine extends featureBase{
    private double MPG;
    private double HorsePower;


    featureEngine(String newName, String newDescrip, double newCost,
                  double newPriority, double newMPG, double newHorsePower) {
        super(newName, newDescrip, newCost, newPriority);
        MPG = newMPG;
        HorsePower = newHorsePower;
    }

    featureEngine(){
        super();
        MPG = -1.0;
        HorsePower = -1.0;
    }

    featureEngine(final featureBase Obj, double newMPG, double newHorsePower){
        super(Obj);
        MPG = newMPG;
        HorsePower = newHorsePower;
    }


    featureEngine(final featureEngine Obj){
        super(Obj);
        MPG = Obj.MPG;
        HorsePower = Obj.HorsePower;
    }

    public static void main(String args[]) {
        featureBase Engine = new featureEngine("Engine!",
                "This is an engine test!", 356.99,1.0, 24.5,1000.0);
        System.out.print(Engine.display());
    }

    public String display(){
        StringBuilder returnStr = new StringBuilder(super.display());
        if( MPG > 0 )
            returnStr.append("MPG: " + MPG + '\n');
        if( HorsePower > 0 )
            returnStr.append("Horse Power: " + HorsePower + '\n');
        return returnStr.toString();
    }

    public boolean equals(final featureEngine Obj){
        if( !super.equals(Obj) ) return false;
        return (MPG == Obj.MPG && HorsePower == Obj.HorsePower );
    }
}
