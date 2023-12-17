import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import Select
import Fourteen3_Pattern as obj

serv_obj = Service("C:\Mann\Selenium\chromedriver.exe")
driver = webdriver.Chrome(service=serv_obj)
driver.get("https://www.moneycontrol.com/fixed-income/calculator/state-bank-of-india-sbi/fixed-deposit-calculator-SBI-BSB001.html?classic=true")
driver.maximize_window()

file = "C:\Users\Admin\Desktop\College\Mann.xlsx"
rows = obj.getRowCount(file)

for r in range(2,rows+1):
    pric = obj.readData(file,"Sheet1",r,1)
    rateofInterest = obj.readData(file,"Sheet1",r,2)
    per1 = obj.readData(file,"Sheet1",r,3)
    per2 = obj.readData(file,"Sheet1",r,4)
    fre = obj.readData(file,"Sheet1",r,5)
    exp_mvalue = obj.readData(file,"Sheet1",r,6)

    #### Passing data to the 
    
    driver.find_element(By.XPATH,"//input[@id='principal']").send_keys(pric)
    driver.find_element(By.XPATH,"//input[@id='interest']").send_keys(rateofInterest)
    driver.find_element(By.XPATH,"//input[@id='tenure']").send_keys(per1)
    
    perioddrp = Select(driver.find_element(By.XPATH,"//select[@id='tenurePeriod']"))
    perioddrp.select_by_visible_text(per2)
    
    frequencydrp = Select(driver.find_element(By.XPATH,"//select[@id='frequency']"))
    frequencydrp.select_by_visible_text(fre)

    driver.find_element(By.XPATH,"//body[1]/div[7]/div[2]/div[1]/div[5]/div[1]/div[1]/div[3]/form[1]/div[2]/a[1]").click()
    
    act_mval = driver.find_element(By.XPATH,"//span[@id='resp_matval']/strong").text
    
    ### Validation start

    if float(exp_mvalue)==float(act_mval):
        print("Test passed")
        obj.writeData(file,"Sheet1",r,8,"Passed")
        obj.fillGreenColor(file,"Sheet1",r,8)
    else:
        print("Test Failed")
        obj.writeData(file,"Sheet1",r,8,"Failed")
        obj.fillRedColor(file,"Sheet1",r,8)   
    
    driver.find_element(By.XPATH,"//img[@class='PL5']").click()

driver.close()