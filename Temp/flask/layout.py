from config import get_config
from flask import render_template

@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('hello.html', name=name)

if __name__ == '__main__':
    Json = get_config()
    menus = Json["menu"]
    for menuItem in menus:
        print(menuItem)
        Items = menus[menuItem]

        if "icon" in Items:
            print("has icon")
        else:
            print("don't has icon")

        for item in Items:
            print("\t%s: %s" % (item, Items[item]))