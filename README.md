### github基本配置

##### <font color="red">1.设备认证</font>

​	*创建一个本地仓库：  <font color="blue">git init</font>

当前位置有（master）表示仓库所在的位置，后续操作在这里

<font color="blue">git config --list 	#查看git配置文件信息</font>

在配置文件中加两条配置：user.email和user.name

<font color="blue">git config --global user.email "(邮箱)"</font>

<font color="blue">git config --global user.name "( 用户名)"</font>

查看是否配置成功：

<font color="blue">ssh -T git@github.com</font>

<font color="red">*密钥生成，创建本机密钥，RSA加密，传给账户进行加工，后续使用此密钥完成传输</font>

<font color="blue">ssh -keygen -t rsa -C "(邮箱)"</font>

记录位置，去所在路径复制密钥

粘贴位置，如图所示

![image-20260913194518750](C:\Users\lry61\AppData\Roaming\Typora\typora-user-images\image-20260913194518750.png)





![image-20260918133831017](C:\Users\lry61\AppData\Roaming\Typora\typora-user-images\image-20260918133831017.png)

##### <font color="red">2.仓库起别名</font>

<font color="blue">git remote add origin "ssh地址"</font>

*为云端仓库ssh地址创建别名，叫origin

<font color="blue">git remote remove origin</font>

*删除origin地址别名

###### 关于项目管理（内容的上传下载）

<font color="blue">*使用 git bash 进行本地内容的上传 ， 通过命令方式。 数据更新/版本更新 </font>

资源上传图：（todo）

资源文件（或文件夹）添加到缓冲区：<font color="blue">git add source </font>

 清除缓冲区数据同时删除文件 ：<font color="blue">git rm source </font>

将缓冲区中资源还原到磁盘中：<font color="blue">git restore </font>

查看缓冲区状态：<font color="blue">git status </font>

提交说明：<font color="blue">git commit -m </font>将缓冲区数据提交到本地仓库，可以附加说明信息

将本地仓库主分支数据推到origin指向的云端仓库：<font color="blue">git push origin master</font>

###### <font color="red">后续开源项目下载，不是以仓库为单位，是以资源文件为单位操作的</font>

![image-20260918131500202](C:\Users\lry61\AppData\Roaming\Typora\typora-user-images\image-20260918131500202.png)

问题出现：修改了test.c但是还没进行：<font color="blue">git add  </font>操作所以拒绝执行

解决：用<font color="blue">git add  </font>或者加<font color="blue">-a </font>

注意：<font color="blue">-a </font>不能用于新加文件

##### github内下载

1.打包下载（前提：网络要好，不然就404了 TAT ）

![image-20260918132956211](C:\Users\lry61\AppData\Roaming\Typora\typora-user-images\image-20260918132956211.png)

2.命令下载：

<font color="blue">git clone （“地址”） </font>

如：<font color="blue">git clone https://github.com/MaaAssistantArknights/MaaAssistantArknights.git </font>			明日方舟长草小助手

网络问题会在终端显示：Time out（超时问题）

![image-20260918133732780](C:\Users\lry61\AppData\Roaming\Typora\typora-user-images\image-20260918133732780.png)

本地没有，云端有就是删除：删除文件，git rm删除缓冲区，git commit 提交删除，push同步即可删除

#### Markdown文本修饰语言

​		<font color="gray">使用修饰符对正文修饰 ，让正文内容附带各种效果</font>

使用修饰符，对正文进行修饰，让正文附带各种效果

1.标题修饰符，多级标题：

​		使用#表示修饰标题内容，例如：\# 标题,\#的数量取决于标题数量，修饰符与关键字用空格分隔，在本软件可以使用ctrl+1/2/3/4/5/6，进行1级标题到六级

2.正文及换行符：

​		正文编辑即可，但是如果需要换行可以用 \<br> 标签进行换行操作,某些编辑器不写br标签不换行

3.文本修饰符：

​		1.**粗体**：看<font color="blue">* </font>的数量 ：一对为斜体，两对为粗体，三对为粗斜体

​				*斜体*		**粗体**		***粗斜体***

​		2.**删除线**：使用两对~，包含文本

​				~~这段是测试文本，无内容~~

​		3.**关键字**：使用``包含文本，凸显效果

​				`关键字`被重点显示。

​		4.**分割线**：分割两端内容，使用五个*即可

*****

4.列表（无序，有序）：

使用\*空格＋文本，列表可以有多级，子级列表要加缩进

![image-20260918203155698](C:\Users\lry61\AppData\Roaming\Typora\typora-user-images\image-20260918203155698.png)

（自己打出来不好看）

  1.机箱

1. ​    1.主板
2.   2.显示器

5.引用修饰符：

​		使用> 空格文本，为一级引用，>越多，引用级别越高

> 一级
>
> > 二级
> >
> > > 三级

6.超链接，图片（本地/网络）：图床工具

​		**超链接**：\[连接标题](链接地址"悬停标题")

[点击访问百度](http://www.baidu.com "孙子点我")

​		**图片**：!\[图片标题](图片地址(磁盘地址)（网络图片地址） " 悬停标题”)

注：如果上传必须用网图地址，用图床工具转换

7.表格：

​		设置表头，设施在单元格在单元格对齐方式，编写内容

:--表示居左对齐；:--:表示剧中；--:表示居右对其，用|分割

英雄|技能|排行
:--|:--:|--:
 黄忠|烈弓|4
 徐盛|破军|2



8.插入代码片段：

使用头部关键字\`\`\` c/cpp/bash/java/...,		中间是代码内容尾部\`\`\`

```c
```

