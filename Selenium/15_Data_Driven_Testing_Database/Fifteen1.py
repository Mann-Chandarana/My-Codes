# insert , update , delete

import mysql.connector
insert_query = 'insert into student values(104,"KIM")'
update_query = "update student set sname='Mary' where sid=104;"
delete_query = "delete from student where sid=104"

try:
    con = mysql.connector.connect(host="localhost",port=3306,users="root",passwd="root",database="mydb")
    curs = con.cursor()   ### Creating the cursor
    curs.execute(insert_query)   ## execute query through cursor
    curs.execute(update_query)   ## execute query through cursor
    curs.execute(delete_query)   ## execute query through cursor
    con.commit()  ## commit transaction
    
    con.close()   ### Close connection
except:
    print("Connection unsuccessful")

print("Finished....")
