from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://the-internet.herokuapp.com/javascript_alerts")
driver.maximize_window()

## Absolute XPath
driver.find_element(By.XPATH,"/html[1]/body[1]/div[2]/div[1]/div[1]/ul[1]/li[3]/button[1]").click()

## Relative XPath
driver.find_element(By.XPATH,"//button[normalize-space()='Click for JS Prompt']").click()


######### Alert box where we can write the text
alert_window = driver.switch_to.alert  ## Will switch to alert window
print (alert_window.text)
alert_window.send_keys("welcome")
alert_window.accept()  ## close window using accept
alert_window.dismiss()  ## close window using cancel



time.sleep(10)