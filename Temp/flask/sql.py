#!/usr/bin/python
import sqlite3
import hashlib
import os
# 登陆 - 获取md5码
def md5(string):
    m = hashlib.md5()   
    m.update(string.encode("utf-8"))   
    return m.hexdigest()
# 登陆 - 学生登陆
def login(username,password):
    conn = connect_database()
    c = conn.cursor()
    c.execute("select password from user where id='%s';" %(username))
    passwordmd5 = c.fetchone()[0]
    if md5(password) == passwordmd5:
        print("login successful.")
        conn.close()
        return True
    else:
        print("wrong password.")
        conn.close()
        return False

# 学生管理 - 注册
def reg(Id,password,realname,sex,sushelou,qinshihao):
    conn = connect_database()
    c = conn.cursor()
    
    c.execute("select * from user where id == '%s';"%(Id))
    if len(c.fetchall()) != 0:
        print("id has been used.")
        conn.close()
        return False

    # uid = getLastID(conn);
    # uid = str(int(uid)+1)
    password = md5(password)

    string = "insert into USER(id,password,realname,sex,sushelou,qinshihao) values('%s','%s','%s','%s','%s','%s');"
    c.execute( string % (Id,password,realname,sex,sushelou,qinshihao))

    conn.commit()
    print("register successful.")
    conn.close()
    return True
# 学生管理 - 删除
def delete(Id):
    conn = connect_database()
    c = conn.cursor()

    c.execute("delete from user where id == '%s';"%(Id))

    conn.commit()
    conn.close()
# 学生管理 - 获取所有学生信息
def getStudents():
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from user order by id DESC;") #  limit 1
    t = c.fetchall()
    conn.close()
    return t
def getStudentName(Id):
    print("id:",Id)

    conn = connect_database()
    c = conn.cursor()
    c.execute("select realname from user where id == '%s';"%Id) #  limit 1
    t = c.fetchall()
    conn.close()
    if len(t)==0:
        return ""
    return t[0][0]

# 公告部分
# 公告管理 - 获取所有公告
def get_bulletin():
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from bulletin order by id DESC;")
    t = c.fetchall()
    conn.close()
    return t
# 公告管理 - 删除公告
def del_bulletin(Id):
    conn = connect_database()
    c = conn.cursor()

    c.execute("delete from bulletin where id == '%s';"%(Id))

    conn.commit()
    conn.close()
# 公告管理 - 增加公告
def add_bulletin(title,content):
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from bulletin order by id DESC limit 1;")
    res = c.fetchall()
    if len(res)==0:
        Id = 0
    else:
        Id = int(res[0][0])
    Id += 1

    string = "insert into bulletin(id,title,content) values('%s','%s','%s');"
    c.execute( string % (str(Id),title,content))

    conn.commit()
    conn.close()


# 外来人员
# 外来人员管理 - 获取所有外来人员
def get_visitor():
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from visitor order by id DESC;")
    t = c.fetchall()
    conn.close()
    return t
# 外来人员管理 - 新建记录
def add_visitor(Id,name,begintime,endtime,student):
    conn = connect_database()
    c = conn.cursor()
    string = "insert into visitor(id,name,begintime,endtime,student) values('%s','%s','%s','%s','%s');"
    c.execute( string % (str(Id),name,begintime,endtime,student))

    conn.commit()
    conn.close()
# 外来人员管理 - 更新记录
def del_visitor(Id):
    conn = connect_database()
    c = conn.cursor()

    c.execute("delete from visitor where id == '%s';"%(Id))

    conn.commit()
    conn.close()
# 外来人员管理 - 获取最后一条记录的Id
def getLastIDofVisitor():
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from visitor order by id DESC limit 1;")
    res = c.fetchall()
    if len(res)==0:
        Id = 0
    else:
        Id = int(res[0][0])

    conn.close()
    return Id





def create_table(conn):
    c = conn.cursor()
    c.execute('''create table user
        (   id          text    not null,
            password    text    not null,
            realname    text    not null,
            sex         text,
            sushelou    text,
            qinshihao   text,
            PRIMARY KEY(id))''')
    c.execute('''create table bulletin
        (   id          text    not null,
            title      text     not null,
            content    text,
            PRIMARY KEY(id))''')
    c.execute('''create table visitor
        (   id            text    not null,
            name          text    not null,
            begintime     text,
            endtime       text,
            student       text,
            PRIMARY KEY(id))''')
    print ("Table created successfully")
    

def test():
    conn = connect_database()
    c = conn.cursor()
    c.execute('''create table visitor
        (   id            text    not null,
            name          text    not null,
            begintime     text,
            endtime       text,
            student       text,
            PRIMARY KEY(id))''')
    conn.close()

def connect_database():
    need_init = not os.path.exists('sql.db')
    conn = sqlite3.connect('sql.db')
    if need_init:
        create_table(conn)
    return conn
        


