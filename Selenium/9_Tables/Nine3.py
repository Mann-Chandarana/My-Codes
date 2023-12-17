# Webtable dynamic

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")

driver = webdriver.Chrome(service=serv_obj)

driver.get("https://opensource-demo.orangehrmlive.com")
driver.maximize_window()

# Admin-->user management --> users
driver.find_element(By.XPATH,'//*[@id="app"]/div[1]/div[1]/aside/nav/div[2]/ul/li[1]/a').click()
driver.find_element(By.XPATH,'//*[@id="app"]/div[1]/div[1]/header/div[2]/nav/ul/li[1]]').click()
driver.find_element(By.XPATH,'//*[@id="app"]/div[1]/div[1]/header/div[2]/nav/ul/li[1]/ul/li/a').click()

rows = len(driver.find_elements(By.XPATH,''))
print("Total number of rows in a table")

count = 0
for r in range(1,rows):
    status = driver.find_element(By.XPATH,"//table[@id='resultTable']/tbody/tr["+str[r]+"]/td[5]").text
    if status=="Enabled":
        count=count+1

print("Number of users in a table :",rows)
print("Number of enabled users in a table :",count)
print("Number of disabled users in a table :",count-rows)

