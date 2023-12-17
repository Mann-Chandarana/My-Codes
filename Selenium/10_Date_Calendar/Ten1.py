from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)
 
driver.get("https://jqueryui.com/datepicker/")
driver.maximize_window()

driver.switch_to.frame(0)  # switch to frame
# driver.find_element(By.XPATH,"//input[@id='datepicker']").send_keys("05/30/2022")  # mm/dd/yyyy

year = "2024"
month = "March"
date = "30"

driver.find_element(By.XPATH,"//input[@id='datepicker']").click()

while True:
    mon = driver.find_element(By.XPATH,"//span[@class='ui-datepicker-month']").text
    yr = driver.find_element(By.XPATH,"//span[@class='ui-datepicker-year']").text
    if month==mon and year==yr:
        break
    else:
        driver.find_element(By.XPATH,"//span[@class='ui-icon ui-icon-circle-triangle-e']").click()  ## Next arrow

## Select date

dates = driver.find_elements(By.XPATH,"//table[@class='ui-datepicker-calendar']//tbody//tr/td/a")

for ele in dates:
    if ele.text==date:
        ele.click()
        break


time.sleep(5)