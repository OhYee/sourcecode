var http = require("http");
var url = require("url");
var fs = require("fs");
var router = require("./router");


function onRequest(request, response) {
    var pathname = url.parse(request.url).pathname;

    console.log("Page url" + pathname);

    fs.readFile(pathname.substr(1), function (err, data) {
        if (err) {
            console.log(err);
            // HTTP 状态码: 404 : NOT FOUND
            // Content Type: text/plain
            response.writeHead(404, { 'Content-Type': 'text/html' });
            response.write("404 error at " + pathname);
        } else {
            // HTTP 状态码: 200 : OK
            // Content Type: text/plain
            response.writeHead(200, { 'Content-Type': 'text/html' });

            // 响应文件内容
            response.write(data.toString());
        }
        // response.write("filename:" + __filename + "\n");
        // router.route(response, pathname);
        response.end();
    });


    console.log("Page finish");
}

function start(port) {
    http.createServer(onRequest).listen(port);
    console.log(`Service running at http://127.0.0.1:${port}`);
}

exports.start = start;