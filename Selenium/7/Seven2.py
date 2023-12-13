##### Internal and External link

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time

ser_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=ser_obj)

driver.get("https://demo.nopcommerce.com/")
driver.maximize_window()

# Click on link

driver.find_element(By.LINK_TEXT,"Digital downloads").click()
# driver.find_element(By.PARTIAL_LINK_TEXT,"Digital").click()

################# Total number of link

links = driver.find_elements(By.TAG_NAME,'a')
links = driver.find_elements(By.XPATH,'//a')
print("Total Number of links "+len(links))

################# Printing all the links

for link in links:
    print(link.text)


time.sleep(10)
