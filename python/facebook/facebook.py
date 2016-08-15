#!/usr/bin/env python
# -*- coding:utf-8 -*-

import urllib2

"""
Facebook API
"""
class FacebookAPI:
    m_access_token = ''
    m_cmd = {}
    
    def __init__(self):
        self.m_access_token = ''
        self.m_cmd['get']  = self.get
        self.m_cmd['help'] = self.help
        
    def get(self, argv):
        connection = urllib2.urlopen(argv[0])
        response = connection.read()
        print response
        return 0

    def help(self, argv):
        if(argv
        for cmd　in self.m_cmd:
            self.m_cmd[cmd]('-help')
        return 0

    def call(self, line):
        (argv) = line.split()
        if self.m_cmd.has_key(argv[0]):
            ret = self.m_cmd[argv[0]](argv[1:])
        else:
            print 'Unknown command: "%s"' % argv[0]
            ret = -1
        return ret
