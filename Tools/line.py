# _*_coding:utf-8_*_
import sys

if __name__ == '__main__':
    file_name = sys.argv[1]
    log = open(file_name)
    lines = log.readlines()
    log.close()
    for line in lines:
        print(line.replace('\n', ''))