#### Frames and Iframes

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://www.selenium.dev/selenium/docs/api/java/index.html?overview-summary.html")
driver.maximize_window()

### Selecting elements from different frames

driver.switch_to.frame("packageListFrame")
driver.find_element(By.LINK_TEXT,"org.openga.selenium").click()
driver.switch_to.default_content()  ## Go back to main page

driver.switch_to.frame("packageFrame")
driver.find_element(By.LINK_TEXT,"WebDriver").click()
driver.switch_to.default_content()  ## Go back to main page

driver.switch_to.frame("classFrame")
driver.find_element(By.XPATH,"/html/body/header/nav/div[1]/div[1]/ul/li[8]").click()
driver.switch_to.default_content()  ## Go back to main page