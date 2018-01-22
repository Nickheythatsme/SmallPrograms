/*
Nicholas Grout
Program 5

We need this class for file input. This class allows us to safely load data from a file, and protects us if that file
does not exist. This class loads all data, then splits it based on the lines in the file.
 */

import java.io.*;

public class BufferedInput{
    private String FileName = null;
    private String FileContents = null;
    private String [] Lines = null;
    private int index = 0;
    static private String DELIM = "\t";


    BufferedInput(String newFileName) throws IOException {
        FileName = newFileName;
        this.readFile();
    }

    public static void main(String args[]){
        String [] temp;
        BufferedInput in = null;
        try {
            in = new BufferedInput("Features_Engines.csv");
        } catch (IOException e) {
            e.printStackTrace();
        }
        temp = in.parseLines();

        while(temp != null) {
            for (int i = 0; i < temp.length; ++i)
                System.out.print(temp[i] + " | ");
            System.out.print("\n");
            temp = in.parseLines();
        }
    }

    public String readFile()
    throws IOException {
        if( FileName == null ) return null;
        BufferedReader in = new BufferedReader(new FileReader(FileName));
        String s;
        StringBuilder sb = new StringBuilder();
        while ((s = in.readLine()) != null)
            sb.append(s + '\n');
        in.close();
        FileContents = new String(sb.toString());
        Lines = FileContents.split("\n",0);
        return FileContents;
    }

    public String[] parseLines(){
        if( index >= Lines.length ) return null;
        String [] splitLine = Lines[index].split(DELIM,0);
        ++index;
        return splitLine;
    }

}
