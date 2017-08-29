function route(response, pathname) {
    response.write(`url:${pathname}`);
    console.log("About to route a request for " + pathname);
}

exports.route = route;