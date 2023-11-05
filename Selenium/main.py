from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome()

driver.get('https://www.google.com')

inputarea = driver.find_element(By.XPATH, '//*[@id="APjFqb"]')
inputarea.send_keys('Mann kutro')
inputarea.send_keys(Keys.ENTER)
time.sleep(10)