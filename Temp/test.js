var test2 = require("./test2");
test2.print();


var http = require('http');
var url = require("url");
var port = 8124;

http.createServer(function (request, response) {
    var pathname = url.parse(request.url).pathname;
    response.writeHead(200, { 'Content-Type': 'text/plain' });
    response.write("url" + pathname + "\n");
    response.end('Hello World\n');
}).listen(port);

console.log(`Server running at http://127.0.0.1:${port}/`);
console.log('Server running at http://127.0.0.1:' + port + '/');