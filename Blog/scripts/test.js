/*
hexo.extend.generator.register('test', function(locals){
    return {
        path: 'test.txt',
        data: function(){
            var posts = locals.posts.sort('-date');
            var d = "";
            posts.forEach(function(post){
                var dd = "";

                post.categories.forEach(function(category){
                    dd +=  category.name + '|';
                });

                post.tags.forEach(function(tag){
                    dd +=  tag.name + '|';
                });

                d += post.title + dd + '\n';
            });
            return d;
        }
    };
});
*/