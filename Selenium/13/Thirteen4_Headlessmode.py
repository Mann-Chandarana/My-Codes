#### Headless mode

import time
from selenium import webdriver
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
import os

location = os.getcwd()

def headless_chrome():
    from selenium.webdriver.chrome.service import Service
    serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
    ops = webdriver.ChromeOptions()
    ops.headless = True
    driver = webdriver.Chrome(service=serv_obj,options=ops)
    return driver

driver = headless_chrome()
driver.get("https://demo.nopcommerce.com/")
print(driver.title)
print(driver.current_url)
driver.close()