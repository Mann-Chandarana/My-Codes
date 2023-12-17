# Mouse Hover

import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://opensource-demo.orangehrmlive.com")
driver.maximize_window()

# Login

driver.find_element(By.XPATH,"//input[@placeholder='Username']").send_keys("Admin")
driver.find_element(By.XPATH,"//input[@placeholder='Password']").send_keys("admin123")
driver.find_element(By.XPATH,"//button[normalize-space()='Login']").click()

# Admin-->user management-->users

admin = driver.find_element(By.XPATH,"")
usermgmt = driver.find_element(By.XPATH,"")
users = driver.find_element(By.XPATH,"")

############################################### Mouse Hover

act = ActionChains(driver)

act.move_to_element(admin).move_to_element(usermgmt).move_to_element(users).click().perform()



time.sleep(5)