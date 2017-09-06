import json

def get_config():
    '获取配置文件内容'
    content = ''
    f = open('config.json', 'r', encoding='UTF-8')
    while True:
        line = f.readline()
        if len(line) == 0:
            break
        content += line
    f.close()
    return json.loads(content)


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