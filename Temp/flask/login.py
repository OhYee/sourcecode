import sqlite3
import hashlib

def md5(string):
    m = hashlib.md5()   
    m.update(string.encode("utf-8"))   
    return m.hexdigest()

def getLastID(c):
    c.execute("select id from user order by id DESC limit 1;")
    return c.fetchone()[0]
    

def reg(c,username,password):
    c.execute("select * from user where username == '%s';"%(username))
    if len(c.fetchall()) != 0:
        print("username has been used.")
        return False

    uid = getLastID()
    uid = str(int(uid)+1)
    password = md5(password)

    c.execute("insert into USER(id,username,password) values('%s','%s','%s');" % (uid,username,password))
    conn.commit()
    print("register successful.")
    return True

def login(c,username,password):
    c.execute("select password from user where username='%s';" %(username))
    passwordmd5 = c.fetchone()[0]
    if md5(password) == passwordmd5:
        print(username,"login successful.")
        return True
    else:
        print(username,"wrong password.")
        return False
