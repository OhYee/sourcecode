//生成一个 Work 对象
function Work(title,url,img,introduction,tag){
    this.title = title;
    this.url = url;
    this.img = img;
    this.introduction = introduction;
    this.tag = tag;
}


function ShowWork(){
    var Works = new Array(
        new Work("Blessing",
                "http://www.bilibili.com/video/av9039463/?from=search&seid=17531274562672468351",
                "http://i0.hdslb.com/bfs/archive/8ac8097a5c15d65f06614666b95191b36b46779b.png_320x200.png",
                "AE",
                "video"),
        new Work("Blessing",
                "http://www.bilibili.com/video/av9039463/?from=search&seid=17531274562672468351",
                "http://i0.hdslb.com/bfs/archive/8ac8097a5c15d65f06614666b95191b36b46779b.png_320x200.png",
                "AE",
                "video"));

    for(i in Works){
        var work = Works[i];
        document.write("<a href='" + work.url + "'><img src='" + work.img + "' />" + work.title + "</a>");
    }
}

ShowWork();
