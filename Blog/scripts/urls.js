hexo.extend.generator.register('urls', function(locals){
    return {
        path: 'urls.txt',
        data: function(){
            var posts = locals.posts.sort('-date');
            var d = "";
            posts.forEach(function(post){
                d += hexo.config.url + post.path + '\n';
            });
            return d;
        }
    };
});