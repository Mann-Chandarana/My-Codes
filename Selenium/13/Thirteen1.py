### Bootstrap dropdown

import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")

driver = webdriver.Chrome(service=serv_obj)

driver.get("https://www.dummyticket.com/dummy-ticket-for-visa-application/")
driver.maximize_window()

driver.find_element(By.XPATH,"//span[@id='select2-billing_country-container']").click()
courtrieslist = driver.find_elements(By.XPATH,"//ul[@id='select2-billing_country-results']/li")
print(len(courtrieslist))

for country in courtrieslist:
    if country.text=="India":
        country.click()
        break

time.sleep(5)

