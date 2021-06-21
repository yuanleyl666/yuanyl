# 期末项目——自走棋
## 可执行程序打开方式
编译说明
### 下载本项目repo：
git clone https://github.com/yuanleyl666/yuanyl

cd yuanyl
### 	下载cocos2d-x-4.0，把cocos2d-x-4.0的文件解压并放到cocos2d文件夹中（coco2d中应有cmake, cocos, external等文件夹）；
### 	进入yuanyl后使用下列指令编译（需要vs2019和cmake）：
mkdir win32-build

cd win32-build

cmake .. -G "Visual Studio 16 2019" -A win32

cmake --build . --config Release

cd ..
###  运行，程序位于win32-build/bin/yuanyl/Release，可进入文件夹后手动打开yuanyl.exe，也可继续在命令行中使用指令：
 win32-build/bin/yuanyl/Release/yuanyl.exe

## 游戏玩法
玩家使用鼠标左键进行点击来选择需要购买的棋子，可以选择刷新来刷新显示的棋子，然后可以将仓库中的棋子拖到自己的棋盘上，再用鼠标拖拽实现棋子选择上场，一轮战斗结束后玩家可以选择进行下一轮战斗或者退出；
* 由于Cocos内置的坐标系统与读取鼠标位置的坐标系统，会造成点击位置向下偏移，所以测试游戏的时候请在“Start”，"ready"，“YOU WIN”，“YOU LOSE”等字体下方一段距离处点击，对您测试游戏时造成的困扰真的很抱歉 *
