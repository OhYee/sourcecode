#!/usr/bin/python
import sqlite3
import hashlib

def create_table():
    c.execute('''CREATE TABLE USER
        (ID          TEXT    NOT NULL,
            USERNAME    TEXT    NOT NULL,
            PASSWORD    TEXT    NOT NULL
            PRIMARY KEY(ID))''')
    print ("Table created successfully")

def md5(string):
    m = hashlib.md5()   
    m.update(string.encode("utf-8"))   
    return m.hexdigest()

def getLastID():
    c.execute("select id from user order by id DESC limit 1;")
    return c.fetchone()[0]
    

def reg(username,password):
    c.execute("select * from user where username == '%s';"%(username))
    if len(c.fetchall()) != 0:
        print("username has been used.")
        return

    uid = getLastID();
    uid = str(int(uid)+1)
    password = md5(password)

    c.execute("insert into USER(id,username,password) values('%s','%s','%s');" % (uid,username,password))
    conn.commit()
    print("register successful.")

def login(username,password):
    c.execute("select password from user where username='%s';" %(username))
    passwordmd5 = c.fetchone()[0]
    if md5(password) == passwordmd5:
        print("login successful.")
    else:
        print("wrong password.")

if __name__ == '__main__':
    conn = sqlite3.connect('test.db')
    c = conn.cursor()

    while 1:
        username = input("username:")
        password = input("password:")
        com = input()
        if com == '1':
            reg(username,password)
        elif com == '2':
            login(username,password)
        else:
            break

    conn.close()

