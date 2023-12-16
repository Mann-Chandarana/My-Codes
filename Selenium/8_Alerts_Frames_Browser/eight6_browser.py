#### Browser

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://opensource-demo.orangehrmlive.com/")
driver.maximize_window()

windowID = driver.current_window_handle
print(windowID)

driver.find_element(By.LINK_TEXT,"OrangeHRM, Inc").click()
windowID = driver.window_handles
print(windowID)

### Approach -1)
# parent_window_id = windowID[0]
# child_window_id = windowID[1]

# driver.switch_to.window(child_window_id)
# print("Title of the child window ",driver.title)

# driver.switch_to.window(parent_window_id)
# print("Title of the parent window ",driver.title)

### Approach -2)

time.sleep(3)

for winid in windowID:
    driver.switch_to(winid)
    print(driver.title)
    if driver.title=="OrangeHRM":
        driver.close()

time.sleep(10)