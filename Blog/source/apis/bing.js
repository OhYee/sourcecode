function getBingImg(){
    var url="NULL"
    fetch('http://cn.bing.com/HPImageArchive.aspx?format=js&idx=0&n=1').then(res=>res.blob()).then(body=>{
        let loader=new FileReader;
        loader.readAsText(body);
        loader.addEventListener('loadend', function(){
            url = getURL(JSON.parse(loader.result).images[0].url);
            url = "http://cn.bing.com"+url;
        })
    });
    console.log(url);
    return 1;
}
console.log(getBingImg());