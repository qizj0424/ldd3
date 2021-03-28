#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
运行环境：linux+python2.7
运行环境：用于打开某浏览器，并打开指定的网址
'''
print "hello world"
'''
#引入selenium库中的 webdriver 模块
from selenium import webdriver

#打开谷歌浏览器
driver = webdriver.Firefox()
#打开百度搜索主页
driver.get('https://www.baidu.com')
'''
#from pyvirtualdisplay import Display
from selenium import webdriver


#display = Display(visible=0, size=(1920, 1080))
#display.start()
driver = webdriver.Firefox()
#driver.get("https://www.baidu.com")
driver.get("https://uland.taobao.com/sem/tbsearch?refpid=mm_26632258_3504122_32538762&keyword=%E5%A5%B3%E8%A3%85&clk1=19b2add9b6ced3feb5c3e7650b666834&upsId=19b2add9b6ced3feb5c3e7650b666834")
