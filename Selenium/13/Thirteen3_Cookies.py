### Capturing cookies

import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver import Keys
import os

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

location = os.getcwd()
driver.get("https://demo.nopcommerce.com/")
driver.maximize_window()

driver.get_cookies()
cookies = driver.get_cookies()
print("Size of the cookies ",len(cookies))

########## Print details of all the cookies created by the browser

for c in cookies:
    print(c)

for c in cookies:
    print(c.get('name'),":",c.get('value'))

########## Add new cookie to the browser
     
driver.add_cookie({"name":"Mycookie","value":"123456"})
cookies = driver.get_cookies()
print("Size of the cookies after adding new one ",len(cookies))

########## Delete a specific cookie from the browser

driver.delete_cookie("Mycookie")
cookies = driver.get_cookies()
print("Size of the cookies after deleting one cookie ",len(cookies))

########## Delete all the cookies

driver.delete_all_cookies()
cookies = driver.get_cookies()
print("Size of the cookies after deleting all cookies ",len(cookies))

time.sleep(5)