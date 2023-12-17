### Capture screen shot

import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver import Keys
import os

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

location = os.getcwd()
driver.get("https://demo.nopcommerce.com/")
driver.maximize_window()

########## To take a screenshot
driver.save_screenshot(location+"\\homepage.png")
driver.get_screenshot_as_file(location+"\\homepage.png")

driver.get_screenshot_as_png()
driver.get_screenshot_as_base64()


########## Able to open the link in the new tab

# driver.find_element(By.LINK_TEXT,"Register").click()

reglink = Keys.CONTROL+Keys.ENTER
driver.find_element(By.LINK_TEXT,"Register").send_keys(reglink)


######### Open a new tab and switches to the new tab
driver.get("https://www.opencart.com/")
driver.switch_to.new_window('tab')
driver.get("https://www.orangehrm.com/")

######### Open a website and then opening the new website in new browser
driver.get("https://www.opencart.com/")
driver.switch_to.new_window('window')
driver.get("https://www.orangehrm.com/")






time.sleep(5)