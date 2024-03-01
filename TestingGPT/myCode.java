package TestingGPT;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class myCode
{
    static ArrayList<String> splitWords(String range, String input){
        ArrayList<String> words = new ArrayList<String>();
        int dash = range.indexOf('-');
        int FirstLength, SecondLength;
        int iterator = 0;
        String addedWord = "";
        String inputCopy = input;
        input = input.trim();
        FirstLength = Integer.parseInt(range.substring(0, dash)); 
        SecondLength = Integer.parseInt(range.substring(dash + 1, range.length())); 
        while(inputCopy.length() > 0)
        {
            iterator++;
            if(inputCopy.length() < FirstLength)
            {
                FirstLength = inputCopy.length();
                
            }
            if(inputCopy.length() < SecondLength)
            {
                SecondLength = inputCopy.length();
            }
            if(iterator % 2 != 0){
                addedWord = inputCopy.substring(0, FirstLength);
                words.add(addedWord);
                inputCopy = inputCopy.substring(FirstLength, inputCopy.length());
                
                
            }
            else if (iterator %2 == 0){
                addedWord = inputCopy.substring(0, SecondLength);
                words.add(addedWord);
                inputCopy = inputCopy.substring(SecondLength, inputCopy.length());
                
            }
            
        }

    
        return words;
    }
    static ArrayList<String> sort(ArrayList<String> splitArray){
        int arrSize = splitArray.size(); 
        String temp = "";
        // One by one move boundary of unsorted subarray 
        for (int i = 0; i < arrSize - 1; i++) 
        { 
            // Find the minimum element in unsorted array 
            for (int j = i+1; j < arrSize; j++) 
                if (splitArray.get(j).charAt(0) < splitArray.get(i).charAt(0)) 
                {
                    temp = splitArray.get(j);
                    splitArray.set(j, splitArray.get(i));
                    splitArray.set(i,temp);
                }
            
            
        } 
        return splitArray;
    }
    public static void main(String[] args)
    {
        
        String input = "abcdEfghijklmnoPqrsTuvwxyz";
        String input2 = "hellomywonderfulfriend2000";
        String str3 = "abcd abcddd abcd aaabcd aabc abbbcd abcd aaabcd";

        String range = "4-6";
        ArrayList<String> test = new ArrayList<String>();

        System.out.println(sort(splitWords(range, str3)));
        System.out.println(sort(splitWords("1-5", input2)));
        // Collections.sort(splitWords("1-5", input2));
        // System.out.println(Collections.sort(splitWords("1-5", input2)));

        // System.out.println("h".charAt(0));
        
    }
}