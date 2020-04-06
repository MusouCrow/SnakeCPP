## SnakeCPP

* 介绍: 采用C++重新复刻[Unity版Snake](https://github.com/MusouCrow/Snake)的练习项目
* 语言: C++11
* 图形库: [SDL](http://www.libsdl.org)
* 编辑器: VSCode
* 编译器: Clang
* 工程部署: CMake
* 分辨率: 1280 * 704

### 游戏介绍

* 游戏场景以32x32格子划分，佐以蓝色背景。
* 黑色格子为蛇头，白色格子为身体，红色格子为食物。
* 蛇头将朝着当前方向每隔一段时间移动一格，到达地图边界则从另一边出现。
* 用蛇头触碰食物即可食用，食用后身体将长出一个，并提高移动频率。
* 若蛇头触碰身体则游戏失败（屏幕变暗），无胜利条件，只会一直吃下去。

### 实现思路

* 模拟Unity实现GameObject-Component机制。
* 渲染与碰撞部分需重新实现。
* 将不使用图片素材，直接画矩形。
* 其余部分基本是翻译。
* 需自行搭建更新-渲染管线。

### 编译

* 前往[官网](http://www.libsdl.org)或利用包管理软件下载、编译SDL2。

```shell
sudo brew install sdl2 # macOS
sudo apt-get install libsdl2-2.0 && apt-get install libsdl2-dev # Ubuntu
```

* 修改目录下的`CMakeLists.txt`中的`SDL_DIR`项，设为自己的SDL路径（此路径应包括include与lib文件夹）。

```shell
set(SDL_DIR /usr/local/Cellar/sdl2/2.0.12_1) # SDL库所在路径
```

* 在目录下新建build文件夹，在其中使用cmake进行构建工程，最后编译并运行。

```shell
cd build
cmake ..

# *nix
make
./SnakeCPP
```
