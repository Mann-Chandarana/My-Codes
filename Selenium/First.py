# importing webdriver module from selenium package
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

# Here driver is the object and chrome is the class
# This will launch our brower
driver = webdriver.Chrome()

# This will open this site in my browser
driver.get("https://opensource-demo.orangehrmlive.com/")
time.sleep(5)

driver.find_element(By.NAME,"username").send_keys("Admin")
driver.find_element(By.NAME,"password").send_keys("admin123")
driver.find_element(By.CLASS_NAME,"oxd-button").click()

time.sleep(10)