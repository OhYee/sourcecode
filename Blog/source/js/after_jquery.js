//确保 jauery 加载完成
$(document).ready(function(){

    $(document).on('click', '.fold_hider', function(){
        $('>.fold', this.parentNode).slideToggle();
        $('>:first', this).toggleClass('open');
    });

    //默认情况下折叠
    $("div.fold").css("display","none");
    //备案信息
    $("div.copyright").before("<div class='beian'><span>豫ICP备17000379号</span></div>");
});



    //$("div.oj").before("<div class='oj_hider'><div class='close hider_title'>点击显/隐题目</div></div>");
    //$("figure table").before("<div class='code_hider'><div class='close hider_title'>点击显/隐代码块</div></div>");
    //$("div.foldcode").before("<div class='code_hider'><div class='close hider_title'>点击显/隐代码块</div></div>");
    //$(document).on('click.menu', 'div.oj_hider', function(){
    //            $('>.oj', this.parentNode).slideToggle();
    //            $('>:first', this).toggleClass('open');
    //    });