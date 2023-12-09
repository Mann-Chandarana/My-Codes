from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://automationpractice.com/index.php")

# Absolute xpath
driver.find_element(By.XPATH,"/html[1]/body[1]/center[1]/font[1]").send_keys("T-Shirts")

# Relative xpath
driver.find_element(By.XPATH,"//body/center/font[1]").send_keys("T-Shirt")

# or  and
driver.find_element(By.XPATH,"" or "").send_keys("Tshirt")
driver.find_element(By.XPATH,"" and "").send_keys("Tshirt")

# contains() and start-with()
driver.find_element(By.XPATH,"//input[contains(@id,'search')]").send_keys("Shirt")
driver.find_element(By.XPATH,"//button[start-with(@name,'submit_)]").click()

######## We can use 
# and 
# or 
# contains 
# starts-with
# text

time.sleep(10)
