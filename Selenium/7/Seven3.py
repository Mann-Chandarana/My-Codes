##### Broken links

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time
import requests as requests

ser_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=ser_obj)

driver.get("https://www.deadlinkcity.com/")
driver.maximize_window()

alllinks = driver.find_elements(By.TAG_NAME,'a')
count = 0

for link in alllinks:
    url = link.get_attribute('href')
    
    try:
        res = requests.head(url)
    except:
        None
    
    if res.status_code>=400:
        print(url," is broken link")
        count+=1
    else:
        print(url," is a valid link")

print("Total number of broken links: ",count)

time.sleep(10)
