# 1) Count number of rows and column in the table
# 2) Read specific row and column data
# 3) Real all the rows and columns data
# 4) Read data based on condition (List books name whose author is Mukesh)

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")

driver = webdriver.Chrome(service=serv_obj)

driver.get("https://testautomationpractice.blogspot.com/")
driver.maximize_window()

# 1) Count number of rows and column

noOfRows = len(driver.find_elements(By.XPATH,"//table[@name='BookTable']//tr"))
noOfColumns = len(driver.find_elements(By.XPATH,"//table[@name='BookTable']/tbody/tr[1]/th"))

print(noOfRows)
print(noOfColumns)

# 2) Read specific row and column data

driver.find_element(By.XPATH,"//table[@name='BookTable']/tbody/tr[5]/td[1]")

# 3) Read all the column and all the row data

print("Printing all the row and column data")

for r in range(2,noOfRows+1):
    for c in range(1,noOfColumns+1):
        data = driver.find_element(By.XPATH,"//table[@name='BookTable']/tbody/tr["+str(r)+"]/td["+str(c)+"]").text
        print(data,end="")
    print()

# 4) Read data based on condition (List books name whose author is Mukesh)

for r in range(2,noOfRows+1):
        author = driver.find_element(By.XPATH,"//table[@name='BookTable']/tbody/tr["+str(r)+"]/td[2]").text
        if author=="Mukesh":
            bookName = driver.find_element(By.XPATH,"//table[@name='BookTable']/tbody/tr["+str(r)+"]/td[1]").text
            price = driver.find_element(By.XPATH,"//table[@name='BookTable']/tbody/tr["+str(r)+"]/td[4]").text
            print(bookName+"    "+author+"    "+price)
            