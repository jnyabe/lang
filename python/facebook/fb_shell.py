#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import readline
from facebook import FacebookAPI

def main():
    fb = FacebookAPI()
    readline.write_history_file(".history")
    readline.parse_and_bind( 'tab: complete' )
    while True:
        line = raw_input('fbshell>')
        if line == 'quit':
            break
        ret = fb.call(line)
    
if __name__ == "__main__":
    main()
