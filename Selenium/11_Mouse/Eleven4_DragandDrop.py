# Drag and drop

import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("http://www.dhtmlgoodies.com/scripts/drag-drop-custom/demo-drag-drop-3.html")
driver.maximize_window()

source_element = driver.find_element(By.ID,"box6")
target_element = driver.find_element(By.ID,"box106")

act = ActionChains(driver)
act.drag_and_drop(source_element,target_element).perform()  # performs drag and drop operations

time.sleep(10)