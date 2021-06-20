#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import io
import time
import random
from selenium import webdriver
from selenium.webdriver.support.ui import Select
import winsound

CONFIG_FILE = './config.json'
BROWSER_WAIT_TIME = 5

HOST = 'gre.neea.cn'
FRONT_PAGE_URL = 'https://' + HOST
BASE_LOGIN_URL = 'https://' + HOST + '/login.do'
BASE_QUERY_URL = 'https://' + HOST + '/testSites.do'


class UserInfo(object):

    def __init__(self, config_file):
        with open(config_file, 'r') as fp:
            obj = json.load(fp)
            self.neea_id = obj['neea_id']
            self.password = obj['password']
            self.ym = obj['ym']
            self.cities = obj['cities']
            self.cities_names = obj['cities_names']
            self.full_result = obj['full_result']
            self.query_interval = obj['query_interval']
            self.query_interval_error = obj['query_interval_error']


def login(browser, user_info):
    # dcap = dict(DesiredCapabilities.PHANTOMJS)
    # dcap['phantomjs.page.settings.userAgent'] = (
    #     'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36'
    # )

    browser.get(FRONT_PAGE_URL)
    browser.implicitly_wait(BROWSER_WAIT_TIME)
    
    neea_id_input = browser.find_element_by_id('neeaId')
    neea_id_input.clear()
    neea_id_input.send_keys(user_info.neea_id)
    password_input = browser.find_element_by_id('password')
    password_input.clear()
    password_input.send_keys(user_info.password)
    input('Go to month selection page then press the <ENTER> key to continue...')

    '''
    check_image_code_input = browser.find_element_by_id('checkImageCode')
    check_image_code_input.click()
    check_image_code_input.clear()
    input('Enter check code then press the <ENTER> key to continue...')
    browser.execute_script('login();')
    time.sleep(BROWSER_WAIT_TIME)
    '''


def query(browser, user_info):
    '''
    req_url = BASE_QUERY_URL
    req_url += '?p=testSites'
    req_url += '&m=ajax'
    req_url += '&ym=%s' % user_info.ym
    req_url += '&neeaID=%s' % user_info.neea_id
    req_url += '&cities=%s' % '%3B'.join(user_info.cities)
    req_url += '&citiesNames=%s' % '%3B'.join(user_info.cities_names)
    req_url += '&whichFirst=AS'
    req_url += '&isFilter=0'
    req_url += '&isSearch=1'
    browser.get(req_url)
    raw_json = browser.find_element_by_id('json').text
    obj = json.loads(raw_json)

    has_seat_list = []
    no_seat_list = []
    for item in obj:
        for date in item['dates']:
            for site in date['sites']:
                if not user_info.full_result and site['realSeats'] == 0:
                    continue
                bjtime = site['bjtime']
                province = site['province']
                city = item['city']
                site_name = site['siteName']
                if site['realSeats'] == 0:
                    no_seat_list.append('[%s|%s|%s|%s]' % (bjtime, province, city, site_name))
                else:
                    has_seat_list.append('[%s|%s|%s|%s]' % (bjtime, province, city, site_name))
    '''
    ym_combo_box = Select(browser.find_element_by_id('yearMonthSearch'))
    ym_combo_box.select_by_value(user_info.ym)
    query_button = browser.find_element_by_id('yearMonth_Next')
    query_button.click()
    browser.implicitly_wait(BROWSER_WAIT_TIME)
    # time.sleep(0.1)

    table = browser.find_element_by_id('sitesTable0')
    tr_list = table.find_elements_by_css_selector("tr[bgcolor='#cccccc']")
    for row in tr_list:
        try:
            # td_list = row.find_elements_by_tag_name('td')
            # for each in td_list:
            #     print(each.text, end = ' ')
            # print()
            td_list = row.find_elements_by_xpath('.//td[4]')
            # print(td_list[0].text, end = ' ')
            if td_list[0].text == '有':
                winsound.PlaySound('D:\\huahai.wav', flags=1)
                input()  # pause
        except Exception as e:
            print(e)
            break
    '''
    tbody = (table.find_elements_by_xpath('.//tbody'))[0]
    tr_list = tbody.find_elements_by_tag_name('tr')
    for row in tr_list:
        try:
            print(row.value_of_css_property('bgcolor'))
            # if row.value_of_css_property('bgcolor') == '#cccccc':
                # td_list = row.find_elements_by_tag_name('td')
                # for each in td_list:
                #     print(each.text, end = ' ')
                # print()
        except Exception as e:
            print(e)
            break
    '''

    time.sleep(0.2 + random.random())
    try:
        back_button = browser.find_element_by_id('search_BackSites')
        back_button.click()
    except Exception as e:
        time.sleep(BROWSER_WAIT_TIME)
        back_button = browser.find_element_by_id('search_BackSites')
        back_button.click()

    '''
    has_seat_list = []
    no_seat_list = []
    for item in obj:
        for date in item['dates']:
            for site in date['sites']:
                if not user_info.full_result and site['realSeats'] == 0:
                    continue
                bjtime = site['bjtime']
                province = site['province']
                city = item['city']
                site_name = site['siteName']
                if site['realSeats'] == 0:
                    no_seat_list.append('[%s|%s|%s|%s]' % (bjtime, province, city, site_name))
                else:
                    has_seat_list.append('[%s|%s|%s|%s]' % (bjtime, province, city, site_name))

    print(user_info.ym)
    if user_info.full_result:
        if len(no_seat_list) == 0:
            print('<The query result of sites without available seats is empty>')
        else:
            print('<No Seat>:')
            print('\n'.join(no_seat_list))
    if len(has_seat_list) == 0:
        print('<The query result of sites with available seats is empty>')
    else:
        print('<Has Seat>:')
        print('\n'.join(has_seat_list))
        winsound.PlaySound('D:\\huahai.wav', flags=1)
    '''


def main():
    browser = webdriver.Firefox()
    user_info = UserInfo(CONFIG_FILE)
    login(browser, user_info)
    while True:
        print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))
        try:  # modified
            user_info.ym = '2020-08'
            query(browser, user_info)
            time.sleep(1 + random.random())
            user_info.ym = '2020-09'
            query(browser, user_info)
        except Exception as e:
            print(e)
            login(browser, user_info)
            continue
        print('Query again after %d second(s)' % user_info.query_interval)
        time.sleep(user_info.query_interval + random.randint(
            -user_info.query_interval_error, user_info.query_interval_error))


if __name__ == '__main__':
    main()

