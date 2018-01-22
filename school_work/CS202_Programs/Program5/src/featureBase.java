/*
Nicholas Grout
Program 5

This is the base for every feature. If we wanted to add a new feature, we simply need to make another extension of this
class.
 */
abstract public class featureBase {

    private String Name = null;
    private String Descrip = null;
    private double Cost;
    private double Priority; //TODO might want to make this int

    featureBase(){
        Name     = null;
        Descrip  = null;
        Cost     = -1.0;
        Priority = -1.0;
    }

    featureBase(String newName, String newDescrip, double newCost, double newPriority){
        Name = new String(newName);
        Descrip = new String(newDescrip);
        Cost = newCost;
        Priority = newPriority;
    }

    featureBase(featureBase Obj){
        Name = new String(Obj.Name);
        Descrip = new String(Obj.Descrip);
        Cost = Obj.Cost;
        Priority = Obj.Priority;
    }

    public static void main(String args[]){
    }

    public String display(){
        StringBuilder returnStr = new StringBuilder();
        if( Name != null )
            returnStr.append("Name: " + Name + '\n');
        if( Descrip != null )
            returnStr.append("Descrip: " + Descrip + '\n');
        if( Cost > 0 )
            returnStr.append("Cost: " + Cost + '\n');
        if( Priority > 0 )
            returnStr.append("Priority: " + Priority + '\n');
        return returnStr.toString();
    }

    public String displayName(){
        return Name;
    }

    //Compare the name between two names.
    public boolean compareName(String toCompare){
        return toCompare.equals(Name);
    }

    //Compare the name between two features.
    public boolean compareName(final featureBase toCompare){
        return toCompare.Name.equals(Name);
    }

    //Return the cost
    protected double returnCost(){
        return Cost;
    }

    //Return the priority
    public double returnPriority(){
        return Priority;
    }

    //Return this's Cost minus the compare's cost.
    public double compareCost(final featureBase toCompare){
        return Cost - toCompare.Cost;
    }

    //Return this's Priority minus the compare's priority.
    public double comparePriority(final featureBase toCompare){
        return Priority - toCompare.Priority;
    }

    public void setPriority(double newPriority){
        Priority = newPriority;
        return;
    }

    public double incrementPriority(double incrementValue){
        Priority += incrementValue;
        return Priority;
    }

    public featureBase assign(final featureBase Obj){
        if( Obj.Name != null )
            Name = new String(Obj.Name);
        else
            Name = null;
        if( Obj.Descrip != null )
            Descrip = new String(Obj.Descrip);
        else
            Descrip = null;
        Cost = Obj.Cost;
        Priority = Obj.Priority;
        return this;
    }

    public boolean equals(final featureBase Obj){
        if( Name == Obj.Name &&
                Descrip == Obj.Descrip &&
                Cost == Obj.Cost &&
                Priority == Obj.Priority )
            return true;
        return false;
    }

    public void cleanup(){
        Name = null;
        Descrip = null;
        Cost = -1;
        Priority = -1;
        return;
    }
}
