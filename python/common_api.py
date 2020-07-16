# -*- coding: utf-8 -*-
import os
import time
import xlrd
import datetime
import openpyxl
import configparser
from openpyxl import Workbook,load_workbook

#获取当前目录下的指定格式文件
def getFiles(suffix):
    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
    res = []
    for root,directory,files in os.walk(BASE_DIR):
        for filename in files:
            suf = os.path.splitext(filename)
            if str(suf).find(suffix) >=0:
                res.append(os.path.join(root,filename))
    return(res)

#读取配置文件中的指定段的值
def readConfigContent(fileNane,sectionName,key)
    absFileName = os.path.abspath(os.path.join(os.getcwd(),fileNane))
    conn = configparser.ConfigParser()
    conn.read(absFileName,encoding='utf-8')
    return conn.get(sectionName,key)

#打印当前系统时间
def printTime(preStr):
    print()
    print(preStr+time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))

#打开一个excel文件
def open_xls(file):
    fh=xlrd.open_workbook(file)
    return fh
 
#获取excel中所有的sheet表
def getsheet(fh):
    return fh.sheets()
 
#获取sheet表的行数
def getnrows(fh,sheet):
    table=fh.sheets()[sheet]
    return table.nrows
 
#读取文件内容并返回行内容
def getFilect(file,shnum):
    fh=open_xls(file)
    table=fh.sheets()[shnum]
    num=table.nrows
    for row in range(num):
        rdata=table.row_values(row)
        datavalue.append(rdata)
    return datavalue
 
#获取sheet表的个数
def getshnum(fh):
    x=0
    sh=getsheet(fh)
    for sheet in sh:
        x+=1
    return x