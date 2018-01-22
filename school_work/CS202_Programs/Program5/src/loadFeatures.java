/*
Nick Grout
Program 5
*/
import com.sun.istack.internal.Nullable;

import java.io.IOException;

public class loadFeatures {
    String fileName = "AllFeatures.tsv";
    protected BufferedInput input = null;
    protected node head = null;

    public loadFeatures(){
        try {
            input = new BufferedInput(fileName);
            fill();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Nullable
    public featureBase pop(){
        if( head == null || head.Data == null ) return null;
        node temp = head;
        head = head.goNext();
        return temp.Data;
    }

    public boolean isEmpty(){
        return (head == null || head.Data == null);
    }

    private boolean fill(){
        String [] tempLine = null; //Clear the first row (It's just column names)
        featureBase tempFeature = null;
        if( head == null )
            head = new node();

        tempLine = input.parseLines();
        while( tempLine != null ){
            tempFeature = makeFeature(tempLine);
            //Then insert it into the array.
            if( !head.insert(tempFeature) ) return false;
            tempLine = input.parseLines();
        }
        return true;
    }

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
