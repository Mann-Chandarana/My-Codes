# insert , update , delete

import mysql.connector

try:
    con = mysql.connector.connect(host="localhost",port=3306,users="root",passwd="root",database="mydb")
    curs = con.cursor()   ### Creating the cursor
    curs.execute("select * from student")  ### Execute query through cursor

    for row in curs:
        print(row[0],row[1],row[2])
    
    con.close()   ### Close connection
except:
    print("Connection unsuccessful")

con.close()

print("Finished....")
