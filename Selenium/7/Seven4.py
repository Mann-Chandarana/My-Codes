from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.select import Select
import time

ser_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=ser_obj)

driver.get("https://www.opencart.com/index.php?route=account/register")
driver.maximize_window()

dropcountry_ele = driver.find_element(By.XPATH,"//select[@id='input-country']")
drpcountry = Select(dropcountry_ele)

# select option from the dropdown

drpcountry.select_by_visible_text("India")
# drpcountry.select_by_value("10") # Argentina 
# drpcountry.select_by_index(13) # index

####### Capture all the options and print them

alloptions = drpcountry.options
print("Total number of options: ",len(alloptions))

for opt in alloptions:
    print(opt.text)

####### Select option from dropdown without using built-in method

for opt in alloptions:
    if opt.text=="India":
        opt.click()
        break



time.sleep(10)