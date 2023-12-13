from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException,ElementNotVisibleException
import time

driver = webdriver.Chrome()

########################## Implicit wait
 
driver.implicitly_wait(10)  # Seconds it will be applicable for all the statement below this line

########################## Explicit wait

# mywait = WebDriverWait(driver,10)
mywait = WebDriverWait(driver,10,poll_frequency=2,ignored_exceptions=[NoSuchElementException,ElementNotVisibleException,Exception])


driver.get("https://www.google.com/")
driver.maximize_window()

searchbox = driver.find_element(By.NAME,'q')

searchbox.send_keys("Selenium")
searchbox.submit()

# time.sleep(5)

searchlink = mywait.until(EC.presence_of_all_elements_located((By.XPATH,'//h3[text()="selenium"]')))

searchlink.click()