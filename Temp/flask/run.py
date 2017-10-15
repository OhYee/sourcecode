from flask import Flask,render_template,session,redirect,url_for,request
from config import get_config
from admin import isAdmin
import sql

app = Flask(__name__)
app.secret_key='\xf1\x92Y\xdf\x8ejY\x04\x96\xb4V\x88\xfb\xfc\xb5\x18F\xa3\xee\xb9\xb9t\x01\xf0\x96'

@app.route('/')
def index():
    if 'id' in session and session['id'] == 'admin':
        return redirect(url_for('admin'))
    return render_template('index.html', config=get_config())

@app.route('/login',methods=["POST","GET"])
def login():
    if request.method == 'POST':
        username = request.form['username']
        passwd = request.form['password']
        if username == 'admin' and passwd == 'admin':
            # 管理员
            session['id'] = username
        else:
            pass
        return redirect(url_for('index'))


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
        sql.delete(request.form['oldid'])
        sql.reg(request.form['id'],request.form['password'],request.form['realname'],request.form['sex'],request.form['sushelou'],request.form['qinshihao'])
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



@app.route('/admin/bulletin')
def bulletin():
    return render_template('admin/bulletin.html',isAdmin=isAdmin(session),bulletins=sql.get_bulletin())

@app.route('/admin/bulletin_add',methods=["POST","GET"])
def bulletin_add():
    if request.method == 'POST':
        sql.add_bulletin(request.form['title'],request.form['content'])
    return redirect(url_for('bulletin'))

@app.route('/admin/bulletin_del',methods=["POST","GET"])
def bulletin_del():
    if request.method == 'POST':
        sql.del_bulletin(request.form['id'])
    return redirect(url_for('bulletin'))

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
    