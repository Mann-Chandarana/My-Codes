from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome()

######################################################################### Application commands

driver.get("https://opensource-demo.orangehrmlive.com/")
print(driver.title)
print(driver.current_url)
print(driver.page_source)

######################################################################### Conditional commands

# is_displayed() and is_enabled()
searchbox = driver.find_element(By.XPATH,"//input[@id='small-searchterms']") 
print("Display status:",searchbox.is_displayed())
print("Enabled status:",searchbox.is_enabled())

#is_selected()
rd_male = driver.find_element(By.XPATH,"//input[@id='gender-male']")
rd_female = driver.find_element(By.XPATH,"//input[@id='gender-female']")

print("Defaults radio buttons status")
print(rd_male.is_selected())
print(rd_female.is_selected())

rd_male.click()  # after selecting male radio button

print("After selecting male radio button")
print(rd_male.is_selected())
print(rd_female.is_selected())

######################################################################### Browser commands

driver.find_element(By.LINK_TEXT,"OrangeHRM, Inc").click()
driver.close()
driver.quit()


######################################################################### navigational commands

driver.get("https://www.snapdeal.com")
driver.get("https://www.amazon.com")

driver.back()  # Go to snapdeal page
driver.forward() # amazon

driver.refresh()



########################################### Find element() - return single webelement

# 1) Locator matching with single webelement
# 2) Locator matching with multiple webelement
# 3) Element not available then throw NoSuchElementException

########################################### Find elements() - return multiple webelements

# 1) Locator matching with single webelement
        # return always list collection
# 2) Locators matching with multiple webelement
# 3) Element not available - zero


########################################### text vs get_attribute()

# text will return only the inner text of the element

# <span> Mann </span> -- here Mann is inner text

emailbox = driver.find_element(By.XPATH,"//input[@id='Email']")

emailbox.clear()
emailbox.send_keys("abc@gmail.com")

print("Result of text " + emailbox.text)
print("Result of get_attribute "+ emailbox.get_attribute('value'))

time.sleep(10)