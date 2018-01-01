import java.io.FileReader;
import java.io.IOError;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class test {
    HashMap<String, HashMap<String, Integer>> wordPathHm; // <word, <docID/path, number of instances>>

    public test(){
        wordPathHm = new HashMap<>();
    }

    public void buildIndex(String path) throws IOException{
        Scanner doc = new Scanner(new FileReader(path));
        while(doc.hasNextLine()){
            String line = doc.nextLine();
            String[] words = line.split("\\s+");
            for(String word: words){
                if(wordPathHm.containsKey(word)) {
                    // if the word exists, update the hashmap
                    HashMap<String, Integer> oldlist = wordPathHm.get(word);
                    Integer currCnt = oldlist.get(path);
                    oldlist.put(path, currCnt+1);
                } else {
                    // if the word does not exist, add a new entry
                    HashMap<String, Integer> newlist = new HashMap<>();
                    newlist.put(path, 1);
                    wordPathHm.put(word, newlist);
                }
            }
        }
        doc.close();
    }

    public int getDocInstanceNum(String word, String docPath) {
        if(wordPathHm.containsKey(word)){
            HashMap<String, Integer>
        }
    }
}
