#!/usr/bin/python3

import threading
import time

class myThread (threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
    def run(self):
        print ("开启线程： ")
        threadLock.acquire()
        print("")
        threadLock.release()
        print_time()
        

def print_time(threadName, delay, counter):
    while counter:
        time.sleep(delay)
        print ("%s: %s" % (threadName, time.ctime(time.time())))
        counter -= 1

threadLock = threading.Lock()
threads = []

# 创建新线程
thread1 = myThread(1, "Thread-1", 1)
thread2 = myThread(2, "Thread-2", 2)

# 开启新线程
thread1.start()
thread2.start()

# 添加线程到线程列表
threads.append(thread2)
threads.append(thread1)


# 等待所有线程完成
for t in threads:
    print("1")
    t.join()
print ("退出主线程")