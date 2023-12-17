# Scrolling

import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://www.countries-ofthe-world.com/flags-of-the-world.html")
driver.maximize_window()

###### 1) Scroll down by pixel

driver.execute_script("window.scrollBy(0,3000)","")
value = driver.execute_script("return  window.pageYOffset;")
print("Number of pixel moves",value)

###### 2) Scroll down till the element is visible

flag = driver.find_element(By.XPATH,"//img[@alt='Flag of India']")
driver.execute_script("arguments[0].scrollIntoView();",flag)
value = driver.execute_script("return  window.pageYOffset;")
print("Number of pixel moves",value)

###### 3) Scroll down page till end

driver.execute_script("window.scrollBy(0,document.body.scrollHeight)")
value = driver.execute_script("return  window.pageYOffset;")
print("Number of pixel moves",value)

###### 4) Scroll Up to Starting position

driver.execute_script("window.scrollBy(0,-document.body.scrollHeight)")
value = driver.execute_script("return  window.pageYOffset;")
print("Number of pixel moves",value)

time.sleep(5)