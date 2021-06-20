# China GRE & TOEFL Query

This is a Python script to query all available seats of ETS' GRE Test and TOEFL Test in China. Modified from: https://github.com/chengzeyi/china_gre_query

## Usage

1. Run `install.sh` or manually install all the dependencies.
    - Manual installation is recommended, since the environment of the systems varies.
    - Prerequisites include Python3, Selenium, Firefox and a driver (geckodriver).
2. Modify `config.json` and `config_toefl.json` to set your NEEA ID, password, etc.
    - Filter out the cities you choose (just add or remove items in that list; see original repo for a full list).
    - Choose the month you desire.
    - Choose what kind of result you require: full (with sites of no seat) or not (without sites of no seat).
    - Choose the interval of each query (or too short may result into being blocked).
    - Choose the error of the interval (to disguise as a human).
3. Execute `gre.py`  or `toefl.py` and follow the information it prints.

## Warning

When the script prompts you to enter the check code in the web browser, you are only allowed to
enter the check code in the input text area. Do not press your `ENTER` key on that web page.
Instead, go back to the CLI and press `ENTER` there and everything will be just fine.

The geckodriver might not work well with a newer version of Firefox.

## Epilogue & Acknowledgement

In April 2020, many TOEFL and GRE tests are cancelled due to the Covid-19 pandemic, and it was hard to appoint a test seat. Fortunately, I found https://github.com/chengzeyi/china_gre_query. Such an automatic query script really played a role because GRE available seats were released randomly at that time.

However, the original repo above used specific APIs of the NEEA website to query seats and was easily blocked. So I modified the program to fully simulate human behavior and click "query" and "back" buttons on the web page instead of requesting specific APIs. In this way the program works well and is never blocked.

In September 2020, the GRE website began to release available seats regularly, so this program is no longer useful. Here I only upload it for an archive. However, I still acknowledge the original author's idea, and his work is appreciated. https://github.com/chengzeyi/china_gre_query

