/*
Nick Grout
Program 4

This class is the main application for the program. It both helps read in the info and allows the user to make a
selection. It displays this selection at the end of the program.
 */
import com.sun.istack.internal.Nullable;

import java.io.*;

public class Application extends nodeArray{

    //This is the user's selection.
    private featureBase [] Selection = new featureBase[3];

    //The application program automatically calls this since we're not doing anything else.
    Application(){
        this.fill("AllFeatures.tsv");
    }

    /*
    ***Here is the main application program. Run this one!***
     */
    public static void main(String args[]){
        Application test = new Application();
        System.out.print("Array of features:\n" + test.display());

        //Select the wheels
        while( !test.selectWheels() );

        //Select the engine
        while( !test.selectEngine() );

        //Select the color
        while( !test.selectColor() );


        System.out.println("Final selection: ");
        for(int i = 2; i >= 0; --i ) {
            if( test.Selection[i] != null )
                System.out.println(test.Selection[i].display());
        }
        test.cleanup();
    }

    public String getSelection(String message){
        String input;
        System.out.print(message);
        try {
            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
            input = stdin.readLine();
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        return input;
    }

    private boolean selectColor(){
        String input = getSelection("Select color (name or number): ");
        if( input == null ) return false;
        if( Character.isAlphabetic(input.charAt(0)) )
             Selection[0] = super.findColor(input);
        else
            Selection[0] = super.findColor( Integer.parseInt(input));

        if( Selection[0] == null )
            return false;
        return true;
    }

    private boolean selectEngine(){
        String input = getSelection("Select engine (name or number): ");
        if( input == null ) return false;
        //Test if it's alphabetical. That means we got a name
        if( Character.isAlphabetic(input.charAt(0)) )
            Selection[1] = super.findEngine(input);
        //Test if it's a number
        else if( !Character.isAlphabetic(input.charAt(0)) )
            Selection[1] = super.findEngine( Integer.parseInt(input));

        if( Selection[1] == null )
            return false;
        return true;
    }

    private boolean selectWheels(){
        String input = getSelection("Select wheels (name or number): ");
        if( input == null ) return false;
        //Test if it's alphabetical. That means we got a name
        if( Character.isAlphabetic(input.charAt(0)) )
            Selection[2] = super.findWheels(input);
            //Test if it's a number
        else if( !Character.isAlphabetic(input.charAt(0)) )
            Selection[2] = super.findWheels( Integer.parseInt(input));

        if( Selection[2] == null )
            return false;
        return true;
    }

    //These next two functions insert data into the nodeArray class. We can easily identify what the next feature is by
    //inputing a keyword in our feature list file. This allows us to call the right constructors.
    private boolean fill(String fileName){
        BufferedInput in;
        String [] tempLine = null;
        featureBase tempFeature = null;

        try {
            in = new BufferedInput(fileName);
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        tempLine = in.parseLines();
        while( tempLine != null ){
            tempFeature = makeFeature(tempLine);
            //Then insert it into the array.
            if( !super.insert(tempFeature) ) return false;
            tempLine = in.parseLines();
        }
        return true;
    }

    @Nullable
    private featureBase makeFeature(String [] tempLine){
        switch(tempLine[0]){
            case "Color":
                return new featureColor(tempLine[1], tempLine[2],
                        Double.parseDouble(tempLine[3]), 0.0, tempLine[4]);
            case "Wheels":
                return new featureWheels(tempLine[1],
                        tempLine[2],                        //Description
                        Double.parseDouble(tempLine[3]),    //Cost
                        0.0,                     //Priority
                        tempLine[4],                        //Style
                        Double.parseDouble(tempLine[5]));
            case "Engine":
                return new featureEngine(tempLine[1], //Name
                        tempLine[2],                        //Description
                        Double.parseDouble(tempLine[3]),    //Cost
                        0.0,                     //Priority
                        Double.parseDouble(tempLine[4]),    //MPG
                        Double.parseDouble(tempLine[5]));   //HorsePower
            default:
                return null;
        }

    }
}

