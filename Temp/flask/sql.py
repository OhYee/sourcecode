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
    res = c.fetchall()
    if len(res)==0:
        print("no user")
        return False
    passwordmd5 = res[0][0]
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

def student_update(oldid,Id,password,realname,sex,sushelou,qinshihao):
    conn = connect_database()
    c = conn.cursor()

    c.execute( "select password from user where id = '%s'"%(Id))
    if password != c.fetchall()[0][0]:
        password=md5(password)

    string = "update user set id='%s',password='%s',realname='%s',sex='%s',sushelou='%s',qinshihao='%s' where id=='%s';"
    c.execute( string % (Id,password,realname,sex,sushelou,qinshihao,oldid))

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

def getStudent(Id):
    print("id:",Id)

    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from user where id == '%s';"%Id) #  limit 1
    t = c.fetchall()
    conn.close()
    if len(t)==0:
        return ""
    return t[0]

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
def add_bulletin(title,time,content):
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from bulletin order by id DESC limit 1;")
    res = c.fetchall()
    if len(res)==0:
        Id = 0
    else:
        Id = int(res[0][0])
    Id += 1

    string = "insert into bulletin(id,title,time,content) values('%s','%s','%s','%s');"
    c.execute( string % (str(Id),title,time,content))

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
# 外来人员管理 - 删除记录
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



# 贵重物品登记
# 贵重物品 - 获取
def get_valuables():
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from valuables order by id DESC;")
    t = c.fetchall()
    conn.close()
    return t
# 贵重物品 - 新建
def add_valuables(Id,name,student,time):
    conn = connect_database()
    c = conn.cursor()
    string = "insert into valuables(id,name,student,time) values('%s','%s','%s','%s');"
    c.execute( string % (str(Id),name,student,time))

    conn.commit()
    conn.close()
# 贵重物品 - 删除
def del_valuables(Id):
    conn = connect_database()
    c = conn.cursor()

    c.execute("delete from valuables where id == '%s';"%(Id))

    conn.commit()
    conn.close()
# 贵重物品 - 获取最后一条记录
def getLastIDofValuables():
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from valuables order by id DESC limit 1;")
    res = c.fetchall()
    if len(res)==0:
        Id = 0
    else:
        Id = int(res[0][0])

    conn.close()
    return Id





# 水电费
# 水电费 - 获取
def get_cost():
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from cost order by id DESC;")
    t = c.fetchall()
    conn.close()
    return t
# 水电费 - 新建
def add_cost(Id,sushelou,qinshihao,water,electric,time):
    conn = connect_database()
    c = conn.cursor()
    string = "insert into cost(id,sushelou,qinshihao,water,electric,time) values('%s','%s','%s','%s','%s','%s');"
    c.execute( string % (str(Id),sushelou,qinshihao,water,electric,time))

    conn.commit()
    conn.close()
# 水电费 - 删除
def del_cost(Id):
    conn = connect_database()
    c = conn.cursor()

    c.execute("delete from cost where id == '%s';"%(Id))

    conn.commit()
    conn.close()
# 水电费 - 获取最后一条记录
def getLastIDofcost():
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from cost order by id DESC limit 1;")
    res = c.fetchall()
    if len(res)==0:
        Id = 0
    else:
        Id = int(res[0][0])

    conn.close()
    return Id
# 水电费 - 获取指定宿舍水电费
def get_costOfStudent(sushelou,qinshihao):
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from cost  where sushelou=='%s' and qinshihao=='%s' order by Id DESC;"%(sushelou,qinshihao))
    res = c.fetchall()
    conn.close()
    return res


# 报修 - 获取
def get_repair(student):
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from repair where student='%s' order by id DESC;"%(student))
    t = c.fetchall()
    conn.close()
    return t
# 报修 - 新建
def add_repair(Id,student,sushelou,qinshihao,time,content):
    conn = connect_database()
    c = conn.cursor()
    string = "insert into repair(id,student,sushelou,qinshihao,time,content) values('%s','%s','%s','%s','%s','%s');"
    c.execute( string % (str(Id),student,sushelou,qinshihao,time,content))

    conn.commit()
    conn.close()
# 报修 - 获取当前学生的最后一个id
def getLastIDofrepair():
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from repair order by id DESC limit 1;")
    res = c.fetchall()
    if len(res)==0:
        Id = 0
    else:
        Id = int(res[0][0])

    conn.close()
    return Id




# 留言板 - 获取所有帖子
def get_disscuss():
    conn = connect_database()
    c = conn.cursor()
    c.execute("select * from talk order by id DESC;")
    t = c.fetchall()
    conn.close()
    return t

# 留言板 - 发布
def add_disscuss(Id,student,content,time):
    conn = connect_database()
    c = conn.cursor()
    string = "insert into talk(id,student,content,time) values('%s','%s','%s','%s');"
    c.execute( string % (str(Id),student,content,time))

    conn.commit()
    conn.close()
# 留言板 - 获取最新帖子id
def getLastIDofdisscuss():
    conn = connect_database()
    c = conn.cursor()

    c.execute("select * from talk order by id DESC limit 1;")
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
        (   id          text        not null,
            password    text        not null,
            realname    text        not null,
            sex         text,
            sushelou    text,
            qinshihao   text,
            PRIMARY KEY(id))''')
    c.execute('''create table bulletin
        (   id          text        not null,
            title       text        not null,
            time        text,
            content     text,
            PRIMARY KEY(id))''')
    c.execute('''create table visitor
        (   id          text        not null,
            name        text        not null,
            begintime   text,
            endtime     text,
            student     text,
            PRIMARY KEY(id))''')
    c.execute('''create table valuables
        (   id          text    not null,
            name        text    not null,
            student    text    not null,
            time         text,
            PRIMARY KEY(id))''')
    c.execute('''create table cost
        (   id          text        not null,
            sushelou    text        not null,
            qinshihao   text        not null,
            water       REAL        not null,
            electric    REAL        not null,
            time        text,
            PRIMARY KEY(id))''')
    c.execute('''create table talk
        (   id          text        not null,
            student     text        not null,
            content     text        not null,
            time        text        not null,
            PRIMARY KEY(id))''')
    c.execute('''create table repair
        (   id          text    not null,
            student     text    not null,
            sushelou    text    not null,
            qinshihao   text    not null,
            content     text,
            time        text,
            PRIMARY KEY(id))''')
    print ("Table created successfully")
    

def test():
    conn = connect_database()
    c = conn.cursor()



    conn.close()

def connect_database():
    need_init = not os.path.exists('sql.db')
    conn = sqlite3.connect('sql.db')
    if need_init:
        create_table(conn)
    return conn
        


