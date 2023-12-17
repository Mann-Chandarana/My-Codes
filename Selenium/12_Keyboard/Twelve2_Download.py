#### Download the file

import time
from selenium import webdriver
from selenium.webdriver.common.by import By

from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
import os

location = os.getcwd()

def chrome_setup():
    from selenium.webdriver.chrome.service import Service
    serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")

    preferences = {"download.default_directory":location}
    ops=webdriver.ChromeOptions()
    ops.add_experimental_option("prefs",preferences)

    driver = webdriver.Chrome(service=serv_obj,options=ops)
    return driver

def Edge_setup():
    from selenium.webdriver.chrome.service import Service
    serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")

    preferences = {"download.default_directory":location}
    ops=webdriver.EdgeOptions()
    ops.add_experimental_option("prefs",preferences)

    driver = webdriver.Edge(service=serv_obj,options=ops)
    return driver


def firefox_setup():
    from selenium.webdriver.chrome.service import Service
    serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
    ## Settings
    ops = webdriver.FirefoxOptions()
    ops.set_preference("browser.helperApps.neverAsk.saveToDisk","application/msword")  ## Mine type
    ops.set_preference("browser.download.manager.showWhenStarting",False)
    ops.set_preference("browser.download.folderList",2)   ## 0-> File in the downloaded in desktop  # 1 Downloaded in downloads folder  # 2 Downloaded to Desired Location
    ops.set_preference("browser.download.dir",location)

    driver = webdriver.Firefox(service=serv_obj,options=ops)
    return driver



# Automation code for downloading the file
driver = chrome_setup()
driver.get("https://file-examples.com/index.php/sample-documents-download/sample-doc-download/")
driver.maximize_window()
driver.find_element(By.XPATH,"//tbody/tr[1]/td[5]/a[1]").click()

time.sleep(10)
