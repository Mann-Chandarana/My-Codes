from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome()

# To open the brower
driver.get("https://demo.nopcommerce.com/")
driver.maximize_window()   # maximize the browser window

########### NAME and ID locators

# driver.find_element(By.ID,"small-searchterms").send_keys("Lenovo Thinkpad X1 Carbon Laptop")
driver.find_element(By.NAME,"q").send_keys("Lenovo Thinkpad X1 Carbon Laptop")

########### linktext and partial link text

driver.find_element(By.LINK_TEXT,"Register").click()
# driver.find_element(By.PARTIAL_LINK_TEXT,"Reg").click()

########### CLASSNAME and TAGNAME

sliders = driver.find_elements(By.CLASS_NAME,"home-slider-container")
print(len(sliders))
driver.find_elements(By.TAG_NAME,"a")

########### CLASSNAME and TAGNAME

# 1) Tag and id
driver.find_element(By.CSS_SELECTOR,"input#email").send_keys("abc")
driver.find_element(By.CSS_SELECTOR,"#email").send_keys("abc")

# 2) Tag and class
driver.find_element(By.CSS_SELECTOR,"input.inputtext").send_keys("abc@gmail.com")

# 3) Tag and attribute
driver.find_element(By.CSS_SELECTOR,"input[data-testid=royal_email]").send_keys("abc@gmail.com")




time.sleep(10)
