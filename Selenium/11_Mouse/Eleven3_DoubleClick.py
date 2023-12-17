# Double click

import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://www.w3schools.com/tags/tryit.asp?filename=tryhtml5_ev_ondblclicks3")
driver.maximize_window()

driver.switch_to.frame("iframeResult")  # switch to frame

field1 = driver.find_element(By.XPATH,"")
field1.clear()
field1.send_keys("welcome")

button = driver.find_element(By.XPATH,"")

act = ActionChains(driver)
act.double_click(button).perform()  # double click action 