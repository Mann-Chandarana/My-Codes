# Uploading the file

import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://www.monsterindia.com/")
driver.maximize_window()

driver.find_element(By.XPATH,"/html[1]/body[1]/div[4]/section[1]/div[1]/div[3]/div[2]/div[2]").click()
driver.find_element(By.XPATH,"//*[@id='file-upload']").send_keys("C:\Users\Admin\Desktop\Notes\DataScience.pdf")

time.sleep(5)
