package College;

import java.util.ArrayList;   // Importing array list
import java.util.Objects;    // Importing Objects
import java.util.Scanner;   // Importing Scanner class

// Name - Mann Chandarana 
// Roll no - 20CS011

class MAPAnalyser
{
    private Record[] data;
    private int nrecords;

    public MAPAnalyser()
    {
        nrecords = 0;
        data = new Record[nrecords];
        loadFromTables();
    }
    public Record find(String id)
    {
        for (int i = 0; i < data.length; i++)
        {
            if (Objects.equals(id, data[i].getId()))
            {
                return data[i];
            }
        }
        return null;
    }
    public Record[] find(int map1,int map2)
    {
        ArrayList<Record> rs = new ArrayList<>();
        for (int i = 0; i < data.length; i++)
        {
            if(data[i].getMap() >= map1 && data[i].getMap() <= map2)
            {
                rs.add(data[i]);
            }
        }
        return rs.toArray(Record[]::new);
    }
    public int lowest()
    {
        int L = Integer.MAX_VALUE;
        for(Record record : data)
        {
            if(record.getMap() < L)
                L = record.getMap();
        }
        return L;
    }
    public int highest()
    {
        int H = Integer.MIN_VALUE;
        for(Record record : data){
            if(record.getMap() > H)
                H = record.getMap();
        }
        return H;
    }
    public int median()
    {
        return ((highest() + lowest()) / 2);
    }
    public int getMap(int sbp, int dbp)
    {
        int MAP = (int)(1.0/3.0 * sbp + 2.0/3.0 * dbp);
        return (MAP);
    }
    private void loadFromTables()
    {
        int len = Assignemnt2.id.length;
        data = new Record[len];
        for (int i = 0; i < len; i++)
        {
            String id = Assignemnt2.id[i];
            int sbp = Assignemnt2.sbp[i];
            int dsp = Assignemnt2.dsp[i];
            int map = getMap(sbp, dsp);
            data[i] = new Record(id, sbp, dsp, map, classify(map));
        }
    }
    private String classify(int map)
    {
        if(map > 100)
        {
            return "high";
        }
        if(map >= 70)
        {
            return "medium";
        }
        else
        {
            return "low";
        }
    }
}

class View
{
    private MAPAnalyser a;
    View(MAPAnalyser a)
    {
        this.a = a;
    }
    void commandLoop()
    {
        Scanner sc = new Scanner(System.in);

        int choice;
        do {
            System.out.println("The following commands are recognised");
            System.out.println("0) Display this message");
            System.out.println("1) Display a specific subject record");
            System.out.println("2) Display records for all subject records within a range");
            System.out.println("3) Display statistics (minimum, maximum and median)");
            System.out.println("9) Exit the application");

            choice = sc.nextInt();

            switch (choice)
            {
                case 0:
                    continue;
                case 1:
                    String id = sc.next();
                    Record record = a.find(id);
                    if(record != null)
                    {
                        System.out.println(record.toString());
                    }
                    else
                    {
                        System.out.println(id + " not found");
                    }
                    continue;
                case 2:
                    int map1 = sc.nextInt();
                    int map2 = sc.nextInt();
                    Record[] records = a.find(map1, map2);
                    if(records.length == 0)
                    {
                        System.out.println("No records in this range");
                    }
                    else
                    {
                        for(Record r : records)
                        {
                            System.out.println(r.toString());
                        }
                    }
                    continue;
                case 3:
                    sc.nextLine();
                    System.out.println("Lowest MAP is " + a.lowest());
                    System.out.println("Highest MAP is " + a.highest());
                    System.out.println("Median MAP is " + a.median());
                    continue;
                case 9:
                    System.exit(0);
            }

        }while (true);
    }
}
class Record
{
    private String id;
    private int sbp;
    private int dbp;
    private int map;
    String cateogory;

    Record(String id,int sbp,int dbp,int map,String cateogory)
    {
        this.id = id;
        this.sbp = sbp;
        this.dbp = dbp;
        this.map = map;
        this.cateogory = cateogory;
    }

    public String getId()
    {
        return id;
    }

    public void setId(String id)
    {
        this.id = id;
    }

    public int getSbp()
    {
        return sbp;
    }

    public void setSbp(int sbp)
    {
        this.sbp = sbp;
    }

    public int getDbp()
    {
        return dbp;
    }

    public void setDbp(int dbp)
    {
        this.dbp = dbp;
    }

    public int getMap()
    {
        return map;
    }

    public void setMap(int map)
    {
        this.map = map;
    }

    public String getCategory()
    {
        return cateogory;
    }

    public void setCateogory(String cateogory)
    {
        this.cateogory = cateogory;
    }

    public String toString()
    {
        return "Id: " + getId() + ", SBP: " + getSbp() + ", " + "DBP: " + getDbp() + ", MAP: " + getMap() + ", Category: " + getCategory();
    }
}

public class Assignemnt2
{
    public static String[] id = {"S01","S02","S03"};   // Creating array of id
    public static int[] sbp = {120, 130, 100};        // Creatinmg array for sbp
    public static int[] dsp = {81, 90, 95};          // Creating array for dsp

    public static void main(String[] args)
    {
        System.out.println("******** Name - Mann Chandarana***********");
        System.out.println("******** Rollno - 20CS011 ******************");
        MAPAnalyser a = new MAPAnalyser();              // Creating object name "a" of class MAPAnalyser
        View v = new View( a );                         // Creating object "v" of a class View
        v.commandLoop();                                // Calling method "commandLoop"
    }
}
