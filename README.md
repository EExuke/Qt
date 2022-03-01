# Qt & Qt/Embedded devolop

# 1.安装包安装:
## 安装包下载地址: http://iso.mirrors.ustc.edu.cn/qtproject/archive/qt/5.9/5.9.9/qt-opensource-linux-x64-5.9.9.run
1. chmod +x qt-opensource-linux-x64-5.9.0.run
2. 然后可以直接点击运行该run文件，开始安装

# 2.源码包安装:
## 源码下载地址: http://download.qt-project.org/archive/
1. 解压: tar -xvzf qt-x11-opensource-src-4.5.3.tar.gz
2. 移动目录: mv qt-x11-opensource-src-4.5.3.tar.gz /usr/local/Trolltech/
3. 进入 /usr/local/Trolltech/qt-x11-opensource-src-4.5.3/
4. 配置: sudo ./configure -prefix /usr/local/Trolltech/Qt-x11-4.5.3
5. 安装: sudo make install
6. 配置环境变量:
	.bashrc 中底部加入: export QMAKESPEC=/usr/local/Trolltech/qt-x11-opensource-src-4.5.3/mkspecs/linux-g++
	并且在$PATH中添加路径: /usr/local/Trolltech/Qt-x11-4.5.3/bin
7. 修改默认编译器:
	sudo vim /usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf
	在第一行加入: /usr/local/Trolltech//qt-x11-opensource-src-4.5.3/bin


# 3.程序打包(发布):
- http://c.biancheng.net/view/9432.html
