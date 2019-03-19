import org.apache.commons.lang3.time.StopWatch;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.concurrent.TimeUnit;

public class  Main {
    public static void main(String[] args) {
        StopWatch SW = new StopWatch();
        BTreeSet<String> BTS = new BTreeSet<>(5);
        LinkedList<String> List = new LinkedList<>();
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(
                    "words_alpha.txt"));
            String line = reader.readLine();
                
            while (line != null) {
                BTS.add(line);
                List.add(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("\n**************** START WORD ****************");
        System.out.println("Time elapsed in microseconds: ");
        SW.reset();
        SW.start();
        List.contains("aahing");
        SW.stop();
        double listTimer = (double) SW.getTime(TimeUnit.MICROSECONDS);
        System.out.println("LIST: " + listTimer );
        SW.reset();

        SW.start();
        BTS.contains("aahing");
        SW.stop();
        double btreeTimer = (double) SW.getTime(TimeUnit.MICROSECONDS);
        System.out.println("BTREE: " + btreeTimer );
        SW.reset();

        double percentage = (listTimer/btreeTimer) * 100;
        System.out.printf("%.2f", percentage);
        System.out.print("% slower.\n");



        System.out.println("\n**************** MID WORD ****************");
        System.out.println("Time elapsed in microseconds: ");
        SW.reset();
        SW.start();
        List.contains("jackrolled");
        SW.stop();
        listTimer = (double) SW.getTime(TimeUnit.MICROSECONDS);
        System.out.println("LIST: " + listTimer );
        SW.reset();

        SW.start();
        BTS.contains("jackrolled");
        SW.stop();
        btreeTimer = (double) SW.getTime(TimeUnit.MICROSECONDS);
        System.out.println("BTREE: " + btreeTimer );
        SW.reset();

        percentage = (listTimer/btreeTimer) * 100;
        System.out.printf("%.2f", percentage);
        System.out.print("% faster.\n");




        System.out.println("\n**************** END WORD ****************");
        System.out.println("Time elapsed in microseconds: ");
        SW.reset();
        SW.start();
        List.contains("zwitterionic");
        SW.stop();
        listTimer = (double) SW.getTime(TimeUnit.MICROSECONDS);
        System.out.println("LIST: " + listTimer );
        SW.reset();

        SW.start();
        BTS.contains("zwitterionic");
        SW.stop();
        btreeTimer = (double) SW.getTime(TimeUnit.MICROSECONDS);
        System.out.println("BTREE: " + btreeTimer );
        SW.reset();

        percentage = (listTimer/btreeTimer) * 100;
        System.out.printf("%.2f", percentage);
        System.out.print("% faster.\n");
    }
}