#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import io
import time
import random
from selenium import webdriver
from selenium.webdriver.support.ui import Select
import winsound

CONFIG_FILE = './config_toefl.json'
BROWSER_WAIT_TIME = 5

HOST = 'toefl.neea.cn'
FRONT_PAGE_URL = 'https://' + HOST
BASE_LOGIN_URL = 'https://' + HOST + '/login'
# BASE_QUERY_URL = 'https://' + HOST + '/testSites'


class UserInfo(object):

    def __init__(self, config_file):
        with open(config_file, 'r') as fp:
            obj = json.load(fp)
            self.neea_id = obj['neea_id']
            self.password = obj['password']
            self.ymd = obj['ymd']
            # self.cities = obj['cities']
            # self.cities_names = obj['cities_names']
            # self.full_result = obj['full_result']
            self.query_interval = obj['query_interval']
            self.query_interval_error = obj['query_interval_error']


def login(browser, user_info):
    # dcap = dict(DesiredCapabilities.PHANTOMJS)
    # dcap['phantomjs.page.settings.userAgent'] = (
    #     'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36'
    # )

    browser.get(BASE_LOGIN_URL)
    browser.implicitly_wait(BROWSER_WAIT_TIME)
    
    neea_id_input = browser.find_element_by_id('userName')
    neea_id_input.clear()
    neea_id_input.send_keys(user_info.neea_id)
    password_input = browser.find_element_by_id('textPassword')
    password_input.clear()
    password_input.send_keys(user_info.password)
    input('Go to order page, select city and then press the <ENTER> key to continue...')


def order(browser, ymd):
    ym_combo_box = Select(browser.find_element_by_id('testDays'))
    ym_combo_box.select_by_value(ymd)
    query_button = browser.find_element_by_id('btnQuerySeat')
    query_button.click()
    browser.implicitly_wait(BROWSER_WAIT_TIME)

    table = browser.find_element_by_xpath('//*[@id="qrySeatResult"]/div/table/tbody')
    tr_list = table.find_elements_by_css_selector("tr")
    for row in tr_list:
        td_list = row.find_elements_by_tag_name('td')
        if td_list[1].text[10::] in ['上海交通大学', '上海海事大学']:
            if td_list[3].text != '名额暂满':
                print(ymd)
            continue
        if td_list[3].text != '名额暂满':
            td_list[3].click()
            winsound.PlaySound('D:\\huahai.wav', flags=1)
            input()  # pause


def main():
    browser = webdriver.Firefox()
    user_info = UserInfo(CONFIG_FILE)
    login(browser, user_info)
    while True:
        try:
            for eachdate in user_info.ymd:
                order(browser, eachdate)
        except Exception as e:
            print(e)
            login(browser, user_info)
            continue
        # print('Query again after %d second(s)' % user_info.query_interval)
        # time.sleep(user_info.query_interval + random.randint(
            # -user_info.query_interval_error, user_info.query_interval_error))


if __name__ == '__main__':
    main()

