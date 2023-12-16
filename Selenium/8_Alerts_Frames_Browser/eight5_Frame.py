#### Inner Frame

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import time

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("http://demo.automationtesting.in/Frames.html")
driver.maximize_window()

driver.find_element(By.XPATH,"//a[normalize-space()='Iframe with in an Iframe']").click()


outer_frame = driver.find_element(By.XPATH,"//iframe[@src='MultipleFrames.html']")
driver.switch_to.frame(outer_frame)

inner_frame = driver.find_element(By.XPATH,"//iframe[normalize-space()='<p>Your browser does not support iframes.</p>']")
driver.switch_to.frame(inner_frame)

driver.find_element(By.XPATH,"/html[1]/body[1]/section[1]/div[1]/div[1]/div[1]/input[1]").send_keys("Welcome")

driver.switch_to.parent_frame()   ## directly switch to parent frame(outerframe)

time.sleep(10)
