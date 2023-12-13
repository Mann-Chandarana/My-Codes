## Checkboxes

from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()

driver.get("https://itera-qa.azurewebsites.net/home/automation")
driver.maximize_window()


##################################################################### Checkboxes

############################# 1) Selecting specific checkbox

driver.find_element(By.XPATH,"//input[@id='monday']").click()

############################# 2) Selecting all the checkbox

checkboxes = driver.find_elements(By.XPATH,"//input[@type='checkbox' and contains(@id,'day')]")
print(checkboxes)

# Approach-1)
for i in range(len(checkboxes)):
    checkboxes[i].click()

# Approach-2)
for checkbox in checkboxes:
    checkbox.click()

############################# 3) Selecting multiple checkboxes

for checkbox in checkboxes:
    weekname = checkbox.get_attribute('id')
    if weekname=='monday' or weekname=='sunday':
        checkbox.click()
    
############################# 4) Selecting last two checkboxes
# range(5,7) --> 6,7

for i in range(len(checkboxes)-2,len(checkboxes)):
    checkboxes[i].click()

############################# 5) Selecting first two checkboxes

for i in range(len(checkboxes)):
    if(i<2):
      checkboxes[i].click()

############################# 6) Clearning all the checkbox

for checkbox in checkboxes:
    if checkbox.is_selected():
        checkbox.click()

driver.quit()
