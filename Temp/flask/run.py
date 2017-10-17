from flask import Flask,render_template,session,redirect,url_for,request
from config import get_config
from admin import isAdmin
import sql
import time

app = Flask(__name__)
app.secret_key='\xf1\x92Y\xdf\x8ejY\x04\x96\xb4V\x88\xfb\xfc\xb5\x18F\xa3\xee\xb9\xb9t\x01\xf0\x96'

def gettime():
    return time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))

@app.route('/test')
def t():
    return render_template('test.html',isAdmin=isAdmin(session))

@app.route('/')
def index():
    if 'id' in session:
        if session['id'] == 'admin':
            return redirect(url_for('admin'))
        else:
            return redirect(url_for('student'))
    return render_template('index.html', error=False)

@app.route('/#')
def index_error():
    if 'id' in session:
        if session['id'] == 'admin':
            return redirect(url_for('admin'))
        else:
            return redirect(url_for('student'))
    return render_template('index.html', error=True)

@app.route('/login',methods=["POST","GET"])
def login():
    if request.method == 'POST':
        username = request.form['username']
        passwd = request.form['password']
        if username == 'admin' and passwd == 'admin':
            # 管理员
            session['id'] = username
        else:
            if sql.login(username,passwd):
                session['id'] = username
    return redirect(url_for('index_error'))


@app.route('/logout')
def logout():
    session.pop('id',None)
    return redirect(url_for('index'))


@app.route('/admin')
def admin():
    return render_template('admin/admin.html',isAdmin=isAdmin(session))

@app.route('/admin/student')
def admin_student():
    return render_template('admin/student.html',isAdmin=isAdmin(session),students=sql.getStudents())

@app.route('/admin/reg',methods=["POST","GET"])
def reg():
    if request.method == 'POST':
        status = sql.reg(request.form['id'],request.form['id'],request.form['realname'],request.form['sex'],request.form['sushelou'],request.form['qinshihao'])
        print(status)
    return redirect(url_for('admin_student'))

@app.route('/admin/delete',methods=["POST","GET"])
def delete():
    if request.method == 'POST':
        sql.delete(request.form['id'])
    return redirect(url_for('admin_student'))

@app.route('/admin/change',methods=["POST","GET"])
def change():
    if request.method == 'POST':
        sql.student_update(request.form['oldid'],request.form['id'],request.form['password'],request.form['realname'],request.form['sex'],request.form['sushelou'],request.form['qinshihao'])
    return redirect(url_for('admin_student'))





@app.route('/admin/visitor')
def visitor():
    vis = sql.get_visitor()
    length = len(vis)
    newvis = []
    for i in range(0,length):
        temp = [vis[i][j] for j in range(0,5)]
        temp.append(sql.getStudentName(temp[4]))
        newvis.append(temp)
    return render_template('admin/visitor.html',isAdmin=isAdmin(session),visitors=newvis)

@app.route('/admin/visitor_add',methods=["POST","GET"])
def visitor_add():
    if request.method == 'POST':
        sql.add_visitor(sql.getLastIDofVisitor()+1,request.form['name'],request.form['begintime'],request.form['endtime'],request.form['student'])
    return redirect(url_for('visitor'))

@app.route('/admin/visitor_update',methods=["POST","GET"])
def visitor_update():
    if request.method == 'POST':
        sql.del_visitor(request.form["id"])
        sql.add_visitor(request.form["id"],request.form['name'],request.form['begintime'],request.form['endtime'],request.form['student'])
    return redirect(url_for('visitor'))

@app.route('/admin/visitor_delete',methods=["POST","GET"])
def visitor_delete():
    if request.method == 'POST':
        sql.del_visitor(request.form["id"])
    return redirect(url_for('visitor'))




@app.route('/admin/valuables')
def valuables():
    val = sql.get_valuables()
    length = len(val)
    newval = []
    for i in range(0,length):
        temp = [val[i][j] for j in range(0,4)]
        temp.append(sql.getStudentName(temp[2]))
        newval.append(temp)
    return render_template('admin/valuables.html',isAdmin=isAdmin(session),valuabless=newval)

@app.route('/admin/valuables_add',methods=["POST","GET"])
def valuables_add():
    if request.method == 'POST':
        sql.add_valuables(sql.getLastIDofValuables()+1,request.form['name'],request.form['student'],request.form['time'])
    return redirect(url_for('valuables'))

@app.route('/admin/valuables_update',methods=["POST","GET"])
def valuables_update():
    if request.method == 'POST':
        sql.del_valuables(request.form["id"])
        sql.add_valuables(request.form["id"],request.form['name'],request.form['student'],request.form['time'])
    return redirect(url_for('valuables'))

@app.route('/admin/valuables_delete',methods=["POST","GET"])
def valuables_delete():
    if request.method == 'POST':
        sql.del_valuables(request.form["id"])
    return redirect(url_for('valuables'))



@app.route('/admin/cost')
def cost():
    return render_template('admin/cost.html',isAdmin=isAdmin(session),costs=sql.get_cost())

@app.route('/admin/cost_add',methods=["POST","GET"])
def cost_add():
    if request.method == 'POST':
        sql.add_cost(sql.getLastIDofcost()+1,request.form['sushelou'],request.form['qinshihao'],request.form['water'],request.form['electric'],request.form['time'])
    return redirect(url_for('cost'))

@app.route('/admin/cost_update',methods=["POST","GET"])
def cost_update():
    if request.method == 'POST':
        sql.del_cost(request.form["id"])
        sql.add_cost(request.form["id"],request.form['sushelou'],request.form['qinshihao'],request.form['water'],request.form['electric'],request.form['time'])
    return redirect(url_for('cost'))

@app.route('/admin/cost_delete',methods=["POST","GET"])
def cost_delete():
    if request.method == 'POST':
        sql.del_cost(request.form["id"])
    return redirect(url_for('cost'))


@app.route('/admin/bulletin')
def bulletin():
    return render_template('admin/bulletin.html',isAdmin=isAdmin(session),bulletins=sql.get_bulletin())

@app.route('/admin/bulletin_add',methods=["POST","GET"])
def bulletin_add():
    if request.method == 'POST':
        content = request.form['content']
        content = content.replace('\n','<br>')
        sql.add_bulletin(request.form['title'],request.form['time'],content)
    return redirect(url_for('bulletin'))

@app.route('/admin/bulletin_del',methods=["POST","GET"])
def bulletin_del():
    if request.method == 'POST':
        sql.del_bulletin(request.form['id'])
    return redirect(url_for('bulletin'))





@app.route('/student')
def student():
    if("id" in session and session["id"]!=admin):
        student = sql.getStudent(session["id"])
        costs = sql.get_costOfStudent(student[4],student[5])
        print(costs)
        return render_template('student/student.html',bulletins=sql.get_bulletin(),student=student,costs=costs)
    return redirect(url_for('index'))

@app.route('/student/password')
def student_password():
    if("id" in session and session["id"]!=admin):
        student = sql.getStudent(session["id"])
        return render_template('student/password.html',student=student,ok=False)
    return redirect(url_for('index'))

@app.route('/student/password#')
def student_password_ok():
    if("id" in session and session["id"]!=admin):
        student = sql.getStudent(session["id"])
        return render_template('student/password.html',student=student,ok=True)
    return redirect(url_for('index'))

@app.route('/student/change',methods=["POST","GET"])
def student_change():
    if request.method == 'POST':
        sql.student_update(request.form['oldid'],request.form['id'],request.form['password'],request.form['realname'],request.form['sex'],request.form['sushelou'],request.form['qinshihao'])
    return redirect(url_for('student_password_ok'))

@app.route('/student/repair',methods=["POST","GET"])
def student_repair():
    if("id" in session and session["id"]!=admin):
        student = sql.getStudent(session["id"])
        repairs = sql.get_repair(student[0])
        return render_template('student/repair.html',student=student,repairs=repairs)
    return redirect(url_for('index'))

@app.route('/student/repair_add',methods=["POST","GET"])
def repair_add():
    if request.method == 'POST':
        sql.add_repair(sql.getLastIDofrepair()+1,request.form['student'],request.form['sushelou'],request.form['qinshihao'],request.form['time'],request.form['content'])
    return redirect(url_for('student_repair'))

@app.route('/student/disscuss',methods=["POST","GET"])
def student_disscuss():
    if("id" in session and session["id"]!=admin):
        student = sql.getStudent(session["id"])
        disscusss=sql.get_disscuss()
        return render_template('student/disscuss.html',student=student,disscusss=disscusss)
    return redirect(url_for('index'))

@app.route('/student/disscuss_add',methods=["POST","GET"])
def student_disscuss_add():
    if request.method == 'POST':
        nowtime = gettime()
        sql.add_disscuss(sql.getLastIDofdisscuss()+1,session["id"],request.form['content'],nowtime)
    return redirect(url_for('student_disscuss'))

@app.route('/init')
def init():
    sql.test()
    return redirect(url_for('index'))

# @app.errorhandler(404)
# def page_not_found(error):
#     print("404",error)
#     return render_template('404.html', config=get_config(), error=error), 404

if __name__ == '__main__':
    config = get_config()
    app.run(debug=True)
    