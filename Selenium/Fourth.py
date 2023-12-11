from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()

driver.get("https://money.rediff.com/gainers/bse/daily/groups")
driver.maximize_window()

# Self
# This will capture the text message 
text_msg = driver.find_element(By.XPATH,"//a[contains(text(),'India Tourism De')]/self::a").text
print(text_msg)

# Parent 
text_msg = driver.find_element(By.XPATH,"//a[contains(text(),'India Tourism De')]/parent::td").text
print(text_msg)

# Child
text_msg = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr/child::td")
print(len(text_msg))

# Ancestor
text_msg = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr").text
print(text_msg)

# Descendent
descendents = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr/descendant::*")
print(len(descendents))

# Following
followings = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr/following::*")
print(len(followings))

# Following Sibling
followingsSiblings = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr/following-sibling::*")
print(len(followingsSiblings))

# Preceding
precedings = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr/preceding::*")
print(len(precedings))

# Preceding-sibling

precedingSiblings = driver.find_elements(By.XPATH,"//a[contains(text(),'India Tourism De')]/ancestor::tr/preceding-sibling::*")
print(len(precedingSiblings))

driver.close()