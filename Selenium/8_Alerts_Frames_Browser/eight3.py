### Authentication popup

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://admin:admin@the-internet.herokuapp.com/basic_auth")
driver.maximize_window()

time.sleep(10)