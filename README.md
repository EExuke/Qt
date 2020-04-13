# Qt & Qt/Embedded devolop

# 源码下载地址: http://download.qt-project.org/archive/
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

