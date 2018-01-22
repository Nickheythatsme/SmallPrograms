/*
Nick Grout
Program 5

This class is the main application for the program. It both helps read in the info and allows the user to make a
selection. It displays this selection at the end of the program.
*/
import com.sun.istack.internal.Nullable;
import java.util.Scanner;
import java.io.*;

public class getSelection extends nodeArray{

    //This is the user's selection.
    car Selection = new car();
    protected Scanner input = new Scanner(System.in);
    protected loadFeatures AllFeatures = new loadFeatures();

    //The application program automatically calls this since we're not doing anything else.
    getSelection(){
        super();
        this.fill("AllFeatures.tsv");
    }

    /*
    ***Here is the main application program. Run this one!***
     */
    public static void main(String args[]){
        getSelection test = new getSelection();
        test.selectFeatures();
        test.cleanup();
    }

    public boolean selectFeatures(){
        //Select the wheels
        while( !selectWheels() )
            System.out.print("Selection not found...\n");

        //Select the engine
        while( !selectEngine() )
            System.out.print("Selection not found...\n");

        //Select the color
        while( !selectColor() )
            System.out.print("Selection not found...\n");

        System.out.println("Final selection: ");
        System.out.println(Selection.display());
        return true;
    }

    public String getSelection(String message){
        String answer;
        System.out.print(message);
        answer = input.nextLine();
        return answer;
    }

    public double getPrority(){
        System.out.print("Input priority from 0 - 10 (0=low, 10=high): ");
        return Double.parseDouble( input.nextLine() );
    }

    private boolean selectColor(){
        featureBase found = null;
        String input = getSelection("Select color (name or number): ");

        if( input == null ) return false;
        //Test if it's alphabetical. That means we got a name
        else if( Character.isAlphabetic(input.charAt(0)) )
            found = super.findColor(input);
        //Test if it's a number
        else
            found = findColor( Integer.parseInt(input) );
        if( found == null ){
            return false;
        }
        found.incrementPriority( getPrority() );
        return Selection.insert( found );
    }

    private boolean selectEngine(){
        featureBase found = null;
        String input = getSelection("Select engine (name or number): ");

        if( input == null ) return false;
        //Test if it's alphabetical. That means we got a name
        else if( Character.isAlphabetic(input.charAt(0)) )
            found = super.findEngine(input);
            //Test if it's a number
        else
            found = findEngine( Integer.parseInt(input) );
        if( found == null ){
            return false;
        }
        found.incrementPriority( getPrority() );
        return Selection.insert( found );
    }

    private boolean selectWheels() {
        featureBase found = null;
        String input = getSelection("Select wheels (name or number): ");

        if( input == null ) return false;
            //Test if it's alphabetical. That means we got a name
        else if( Character.isAlphabetic(input.charAt(0)) )
            found = super.findWheels(input);
            //Test if it's a number
        else
            found = findWheels( Integer.parseInt(input) );
        if( found == null ){
            return false;
        }
        found.incrementPriority( getPrority() );
        return Selection.insert( found );
    }

    //These next two functions insert data into the nodeArray class. We can easily identify what the next feature is by
    //inputing a keyword in our feature list file. This allows us to call the right constructors.
    private boolean fill(String fileName){
        while( !AllFeatures.isEmpty() )
            super.insert( AllFeatures.pop() );
        return true;
    }
}

