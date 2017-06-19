---
title: Git使用方法详解
date: 2017-06-18 14:13:09
categories: 笔记
tags:
  - Git
keywords:
  - 教程
---
> Git是一款免费、开源的分布式版本控制系统，用于敏捷高效地处理任何或小或大的项目。

如果想正式一点做一个项目,还是需要系统学习一下 Git 
<!--more-->

# Git简介
Git是一个版本管理工具,自然最重要的就是版本管理.在Git中,每一版本存为一个`commit`,以单向链表的形式存储,每一个结点都存储了一个版本,父结点存储的是它的前一个版本.
显然,最前面的头指针指向的就是最新的版本结点.  


而每个版本又存在不同的区域：
- working tree
- index(staged file)
- HEAD
 
working tree就是我们正常在文件浏览器里能够看到的文件
index是缓存区,标记了本版本和上一版本之间的差异
HEAD则相当于在整个Git里的位置指针,记录了当前的位置  


而文件则存在如下几种状态
- Untracked files
  新建的文件
- Changes not staged for commit(Changed but not updated)
  更改的文件
  - modified 
    修改的文件
  - deleted
    删除文件
- Changes to be committed(staged)
  已被add的文件(暂存状态)

文件的改动无非删除,修改,新建三种  
而这三种外还有暂存区(staged)
这个就是当前版本记录下的改动

# git 命令
## git init

`<path>` 默认为当前目录

### 初始化git库(本地库)
这个是本地库,能够在文件管理器里方便地操作文件
```bash
git init <path>
```

### 初始化git库(服务器端)
这个是远程库(remote),不能直接操作文件
```bash
git init --bare <path>
```
 
## git clone

这个指令可以将别人的库直接 `clone` 下来
如果只需要最新版本,可以增加 `--depth=1`
```
git clone <url> <path>
```


## git add
将文件提交到暂存区

相应, `git add` 有如下用法  

```bash
git add <filename   //提交指定文件
git add .             //提交untracked files和changes not staged for commit
git add -u <filename//提交changes not staged for commit (tracked file)
git add -A <filename//提交所有的变化
```

其中,在Git version 1.x中, `git add .` 不包括删除的文件  
在Git version 2.x中, `git add .` 包括删除的文件,另加了 `git add --ignore-removal .` 替代原用法
  
<br>

另外可以使用 `git status` 查看当前三种状态的文件  
或者 `git add -i` 分类查看各个状态的文件


## 本地库操作
### git commit
git commit 是极为重要的一部分  
这里记录了你每次更改文件的意义
因此保持一个比较好的格式非常重要


```
git commit                  //调用文本编辑器输入commit信息
git commit -m "<message>"   //直接输入信息
git commit -a               //自动add tracked files 然后调用编辑器输入commit
```

> [Commit message 的格式](http://www.oschina.net/news/69705/git-commit-message-and-changelog-guide)
> {% fold %}
每次提交，Commit message 都包括三个部分：Header，Body 和 Footer。
```
<type>(<scope>): <subject>

<body>

<footer>
```
其中，Header 是必需的，Body 和 Footer 可以省略。
不管是哪一个部分，任何一行都不得超过72个字符（或100个字符）。这是为了避免自动换行影响美观。
**Header**
Header部分只有一行，包括三个字段：type（必需）、scope（可选）和subject（必需）。
（1）type
type用于说明 commit 的类别，只允许使用下面7个标识。
- feat：新功能（feature）
- fix：修补bug
- docs：文档（documentation）
- style： 格式（不影响代码运行的变动）
- refactor：重构（即不是新增功能，也不是修改bug的代码变动）
- test：增加测试
- chore：构建过程或辅助工具的变动
如果type为feat和fix，则该 commit 将肯定出现在 Change log 之中。其他情况（docs、chore、style、refactor、test）由你决定，要不要放入 Change log，建议是不要。

（2）scope
scope用于说明 commit 影响的范围，比如数据层、控制层、视图层等等，视项目不同而不同。

（3）subject
subject是 commit 目的的简短描述，不超过50个字符。
以动词开头，使用第一人称现在时，比如change，而不是changed或changes
第一个字母小写
结尾不加句号（.）

<br>
**Body**
Body 部分是对本次 commit 的详细描述，可以分成多行。下面是一个范例。

More detailed explanatory text, if necessary.  Wrap it to about 72 characters or so. Further paragraphs come after blank lines.- Bullet points are okay, too- Use a hanging indent
有两个注意点。
（1）使用第一人称现在时，比如使用change而不是changed或changes。
（2）应该说明代码变动的动机，以及与以前行为的对比。
  
<br>
**Footer**

Footer 部分只用于两种情况。
（1）不兼容变动
如果当前代码与上一个版本不兼容，则 Footer 部分以BREAKING CHANGE开头，后面是对变动的描述、以及变动理由和迁移方法。
```
BREAKING CHANGE: isolate scope bindings definition has changed.
    To migrate the code follow the example below:
    Before:
    scope: {
      myAttr: 'attribute',
    }
    After:
    scope: {
      myAttr: '@',
    }
    The removed `inject` wasn't generaly useful for directives so there should be no code using it.
```
（2）关闭 Issue
如果当前 commit 针对某个issue，那么可以在 Footer 部分关闭这个 issue 。

`Closes #234`
也可以一次关闭多个 issue 。

`Closes #123, #245, #992`
 **revert**
还有一种特殊情况，如果当前 commit 用于撤销以前的 commit，则必须以revert:开头，后面跟着被撤销 Commit 的 Header。
```
revert: feat(pencil): add 'graphiteWidth' option
This reverts commit 667ecc1654a317a13331b17617d973392f415f02.
```
Body部分的格式是固定的，必须写成This reverts commit <hash>.，其中的hash是被撤销 commit 的 SHA 标识符。
如果当前 commit 与被撤销的 commit，在同一个发布（release）里面，那么它们都不会出现在 Change log 里面。如果两者在不同的发布，那么当前 commit，会出现在 Change log 的Reverts小标题下面。
{% endfold %}

### git branch
分支就类似平行宇宙,在这一刻你可以选择用python来解决一个问题,也可以选择用java解决这个问题  
于是开了两个分支,python和java,你可以随便更改任意一个分支的内容而不影响另一个分支的内容  
当你发现python能更好解决问题时,就可以删掉java那个分支,让python与主分支合并  

#### 查看分支
当前分支前有`*`标记  
```
git branch      //列出本地分支
git branch -r   //列出远程分支
git branch -a   //列出本地和远程分支
```

#### 创建分支及切换分支
默认情况下,我们是在主分支 `master` 里  
如果需要切换分支,需要 `git checkout` 指令

```
git branch <branchName>       //创建分支(不切换)
git checkout <branchName>     //切换到已有分支
git checkout -b <branchName>  //创建分支并且切换到新分支
```

新建分支都是在**当前所在的分支**基础上**克隆**一份,commit只会影响当前分支的内容  


并且分支是共用暂存区的,也就是说如果在分支1上仅 `add` 而不 `commit`，实际暂存区中已经记录该次修改  
哪怕后续切换到分支2上再进行 `commit` 也是有效的操作

<span style="color:#cc4444">**因此,切换分支前一定要确保``commit``**</span>


#### 重命名分支
```
git branch -m <OldName> <NewName> //重命名分支
git branch -M <OldName> <NewName> //强制重命名分支(忽略重名)
```

#### 删除分支
需要注意不能删除当前所在的分支(不能删除当前所在的世界)

```
git branch -d <branchName>      //删除分支
git branch -D <branchName>      //强制删除分支(忽略分支未merge部分)
git branch -d -r <branchName>   //删除远程branchname分支
```

#### 通过分支进行多人协作
`master` 分支作为最终发布的版本,只有在更新到最终版时,将各分支 `merge` 到该分支  
`dev` 作为大家个人分支的合并分支,用于代码合并
而个人分支就是自己维护自己的部分即可

### git checkout
对于整个Git而言,他是一个有向链表,由于存在 `branch` 和 `merge` 操作,因此局部会存在有向无环图(DAG)  
链表的每一个结点都是一个 `commit`   
而 `HEAD` 指向的就是当前所在的 `commit` 
那么 `HEAD^` 是上一个提交,`HEAD^^` 是上上一次
前十次提交可以用 `HEAD^^^^^^^^^^` 也可以用 `HEAD~10`  

`checkout` 的功能就是切换到任意一个 `commit` 去
```
git checkout <commit_HASH>
```
当切换到某个分支时,默认时切换到该分支的最新状态  

而对于想把某个文件恢复到上个 `commit` 后的状态,可以使用
```bash
git checkout -- <filename>
```
这样可以清除该文件在工作区的修改

### git merge
#### 合并两个分支
合并分支是Git的一个重要功能
可以直接使用改命令将一个分支合并当前分支

```
git merge <branchName>
```

其中有选项
- `--no-ff` 三方合并并提交修改(默认)
- `--ff-only` 判断当前分支可否根据目标分支快速合并 

#### 冲突处理

但是对于将<span class="label label-sky">待合并分支</span>合并到<span class="label label-orange">当前分支</span>的情况,需要注意有冲突的情况存在  
如果<span class="label label-sky">待合并分支</span>是在<span class="label label-orange">当前分支</span>的基础上修改而来的,那么显然直接将<span class="label label-orange">当前分支</span>更新到<span class="label label-sky">待合并分支</span>状态即可  
如果<span class="label label-sky">待合并分支</span>和<span class="label label-orange">当前分支</span>在某个时间点分开后各自有了更新,就会产生冲突  
这时使用 `git merge` 会提醒你存在冲突,需要手动解决  

使用 `git status` 查看冲突的文件,然后手动进去修改  
需要注意的是,这时冲突文件是两个版本文件的综合体  
```
<<<<<<< HEAD
aaaaa
=======
bbbbb
>>>>>>> feature1
```
使用这样的方式来标记不同  
合并后就可以删除掉分支了

#### 取消合并
如果merge一半不想merge了,就用下面的代码来**回滚merge**操作
```
git merge --abort
```

### git rebase
`git rebase` 也是将两个分支合并到一起的操作  
由名字可以看出来,rebase会将待合并分支记录加到当前分支前面,当作初始状态,然后再按照当前分支的提交进行合并(会丢失原本的commit) 

`git merge` 和 `git rebase` 和区别有以下几点  
- merge 是一个合并操作,会将两个分支的修改合并在一起,默认操作的情况下会提交合并中修改的内容
- merge 的提交历史忠实地记录了实际发生过什么,关注点在真实的提交历史上面
- rebase 并没有进行合并操作,只是提取了当前分支的修改,将其复制在了目标分支的最新提交后面   
- rebase 的提交历史反映了项目过程中发生了什么,关注点在开发过程上面

### git revert
该命令是指新建一个commit,内容**撤销**某个commit(中间的错误路线保留)
```bash
git revert <commit_HASH>
```

如果log如下
> commit 3 add c
> commit 2 add b
> commit 1 add a

现在我在3这个状态,当我 `git revert 2` 后  
记录变为

> commit 4 revert b
> commit 3 add c
> commit 2 add b
> commit 1 add a

同时文件变为 a c (撤销了生成 b 的操作)

### git reset
该命令是直接回到指定commit,之前的错误commit全部舍弃(假装自己没有错过)
```bash
git reset [--mixed] <cimmit_HASH> //只更改HEAD和index
git reset --soft <commit_HASH>    //只把HEAD回退回去,index和working tree都不变
git reset --hard <commit_HASH>    //修改index和working tree,忽略所有改动文件
```

看上去可能比较难以理解,举个例子  
如果使用 `--mixed` 那么还原后,会以目标commit为基础分析文件,这样你看到的就是一群改动等待被commit,可以把需要恢复的挑出来  
如果使用 `--hard` 那么就是原汁原味的目标commit的样子,文件全部都是当时的状态  
如果使用 `--soft` 那么目录内的文件没有被修改,也没有文件在暂存区
但是这三种都有一个问题:HEAD回到了过去,并且之后的commit都扔掉了  
那么就有一个尴尬的问题了,`--soft`会导致有的文件在git里并没有生成的记录,但是它就是存在了  


并且 `git checkout` 和 `git reset --hard` 可以看成是差不多的,唯一的区别就是后面的log是否还保留(事实上尽管`reset`后看上去记录没了,但是git还是会保留下来的,除非去运行清理指令)  
但是,如果你checkout回到之前的状态,但是当前分支仍然指向原来的commit,如果你在之前的状态又提交了commit,是不能算在该分支的,这个commit就游离在了git链表之外(因为每个commit只能指向它的前一个commit)

<span style="">所以干什么的命令就是干什么的,虽然看上去可能能做一些自己职责之外的事情,但是还是不要作死乱用


### git reflog
#### 使用reflog找到丢失的commit
如果已经已经被删掉(合并)的 `commit` 有用怎么办？？？
存在游离的 `commit` 怎么办？？？
手贱 hard rebase 到了错误的地方把有用的记录删掉了怎么办？？？

`git reflog` 来救你！
git非常机智地留了一个回收站,你所有删掉的 `commit` 都在这里！

可以使用任意的方法重新拿到需要的数据(`branch`,`checkout`,`rebase`)  

#### 清除reflog
那么如何清空这个“回收站”呢？
运行下面的代码,你所有游离的`commit`都被释放掉了(这次再手误就真的没救了)
```bash
git filter-branch --index-filter "git rm -r --cached --ignore-unmatch path/to/your/file" HEAD  
git push origin master --force  
rm -rf .git/refs/original/  
git reflog expire --expire=now --all  
git gc --prune=now  
git gc --aggressive --prune=now  
```

### git tag
标签可以代替commit id,方便查找特殊的记录   
```bash
git tag                           //列出所有标签
git tag [-a] <tagName> [-m "<Message>"] [<commit_HASH>]   //给指定的commit(默认为当前状态)打标签,并附加说明
```

## 远程库操作
### git remote
remote是git的远程分支
可以看做是把本地部分在网上的一个备份
除了使用命令行外，也可以在 '.git/config' 修改


remote对于每个远程库可以添加多个url(相当于多端备份)

```
git remote                                                  //查看所有的remote
git remote -v                                               //查看所有的remote详细信息
git remote add <remoteName> <url>                           //增加新的remote
git remote rm <name>                                        //删除指定的remot
git remote set-url --add [remoteName] [newUrl]              //为指定remote增加链接
git remote set-url --push <remoteName> <newUrl> [<oldUrl>]  //修改远程分支的url
git remote set-url --delete <remoteName> <Url>              //删除远程分支的指定url
```


### git push

将本地分支推送到远程分支

如果省略本地分支，就是把一个空的分支push到远程分支（也即删除远程分支）

另外如果使用 `-u` 参数，相当于同时把当前的设置记录为默认，下次如果省略相应参数的话，会优先按照本地的进行提交

```
git push [-u] <remoteName> <localBranch>:<remoteBranch>  //将本地分支推送到远程分支
```

git push有两种模式
- simple模式
  存在默认配置的情况下，按照默认配置提交
  `git config --global push.default simple`
- matching模式
  将远程分支对应的本地分支推送上去(以远程分支为主，不会新建远程分支)
  `git config --global push.default matching`
  
然后很自然就会想到能不能把本地所有分支都推送到远程主机
自然是可以的
`git push --all <remoteName>`


如果远程分支比本地分支还要新，就会产生冲突，需要先合并差异
当然也可以用 `--force` 或者 `-f` 强制提交


默认情况下，`push`不会推送`tag`，需要增加`--tags`选项

### git pull

`pull` 是和 `push` 完全相反的操作(对应的指令也恰好对应相反)

会将远程分支合并到本地分支
也即，`pull`是一个合并操作，那么自然就就存在`merge`和`rebase的`区别
在`pull`里，默认是`merge`，可以使用`--rebase`使用`rebase`的形式合并

```
git pull [--rebase] <remoteName> <remoteBranch>:<localBranch>
```


### git fetch
`git fetch` 是拉取远程分支的更新

将远程分支拉取到本地的 `<remoteName>/<remoteBranch>` 分支
然后就可以进行合并等操作了

其中如果指定远程分支名,则只会拉取指定的远程分支
```
git fetch <remoteName> [<remoteBranch>]
```

对比`fetch`和`pull`
可以发现 `fetch` + `merge` = `pull`


## git modoule
当你的项目里需要用到别人的项目时,可能就会出项 git 嵌套 git 的情况  
这时就需要使用子模块来管理 git 

### 自己项目的子模块
```
git submodule add <url> <path> //新建子模块
```
新建后,目录下会生成一个 `.gitmodules` 记录该项目的所有子模块信息  
当子模块有更改时,只会有一个标记记录了模块有更改(没有具体更改内容)  
对于主项目来说,子项目只是一个 `HEAD` 标记子项目对应的时哪个 `commit` 状态  

### 别人项目的子模块
而对于 `clone` 别人的项目时,如果存在子模块,需要单独初始化子模块部分  
```
git submodule init    //初始化子模块
git submodule update  //更新到该项目中记录的 `commit`
```
如果项目在远程分支有更新,除了要使用 `pull` 或者 `fetch` 更新项目外,还要单独使用 `git submodule update` 更新子模块  

### 删除子项目
```
git ls-files --stage | grep 160000
git rm --cached <path>
```


# .gitignore
这个是存在于项目根目录的文件,用于记录需要忽略的文件(编译生成的中间文件,有敏感信息的文件)  
一行一条需要忽略的文件路径信息  

# 参考链接
- [git add -A 和 git add . 的区别](http://www.cnblogs.com/skura23/p/5859243.html)
- [Git 提交的正确姿势：Commit message 编写指南](http://www.oschina.net/news/69705/git-commit-message-and-changelog-guide)
- [Git教程-廖雪峰的官方网站](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)
- [git branch用法总结](http://blog.csdn.net/xiruanliuwei/article/details/6919319)
- [git branch -D 大写的D 删除分支](http://blog.csdn.net/isaisai/article/details/44935653)
- [git checkout 命令详解](http://www.tuicool.com/articles/A3Mn6f)
- [git reset soft,hard,mixed之区别深解](http://www.cnblogs.com/kidsitcn/p/4513297.html)
- [git的reset和checkout的区别](http://www.tuicool.com/articles/6NJrayJ)
- [彻底删除GIT中的文件，节省空间](http://blog.csdn.net/happyteafriends/article/details/12424593)
- [Git怎样撤销一次分支的合并Merge](https://segmentfault.com/q/1010000000140446)
- [Git代码合并Merge还是Rebase](http://www.tuicool.com/articles/7BfM7f2)
- [闲谈 git merge 与 git rebase 的区别](http://www.jianshu.com/p/c17472d704a0)
- [Git --everything-is-local](https://git-scm.com/book/zh/v2)