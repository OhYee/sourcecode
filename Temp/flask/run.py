from flask import Flask
from flask import render_template
from config import get_config

app = Flask(__name__)


@app.route('/')
def index():
    print("index")
    return render_template('layout.html', config=get_config())

@app.route('/test')
def test():
    return render_template('test.html', config=get_config())

@app.route('/test2')
def test2():
    return render_template('test2.html', config=get_config())

@app.route('/login')
def login():
    return render_template('login.html', config=get_config())

@app.errorhandler(404)
def page_not_found(error):
    print("404",error)
    return render_template('404.html', config=get_config(), error=error), 404

if __name__ == '__main__':
    config = get_config()
    app.run(debug=True)
