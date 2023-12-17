# Slider

import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)

driver.get("https://www.jqueryscript.net/demo/Price-Range-Slider-jQuery-UI/")
driver.maximize_window()

min_slider = driver.find_element(By.XPATH,"/html[1]/body[1]/div[2]/div[2]/span[1]")
max_slider = driver.find_element(By.XPATH,"/html[1]/body[1]/div[2]/div[2]/span[2]")

print("Locations of sliders Before moving .........")

print(min_slider.location)
print(max_slider.location)

act = ActionChains(driver)
act.drag_and_drop_by_offset(min_slider,100,0).perform()
act.drag_and_drop_by_offset(max_slider,-39,0).perform()

print("Locations of sliders After moving .........")
print(min_slider.location)
print(max_slider.location)