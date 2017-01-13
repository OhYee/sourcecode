//确保 jauery 加载完成
$(document).ready(function(){
    $("div.oj").before("<div class='oj_hider'><div class='close hider_title'>点击显/隐题目</div></div>");
    $("figure table").before("<div class='code_hider'><div class='close hider_title'>点击显/隐代码块</div></div>");
    $(document).on('click.menu', 'div.oj_hider', function(){
                $('>.oj', this.parentNode).slideToggle();
                $('>:first', this).toggleClass('open');
        });
    $(document).on('click.menu', 'figure .code_hider', function(){
                $('>table', this.parentNode).slideToggle();
                $('>:first', this).toggleClass('open');
        });

    $("div.copyright").before("<div class='beian'><span>豫ICP备17000379号</span></div>");
});

