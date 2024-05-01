@echo off

@REM windows下的打包脚本,请不要删除空行,可能导致无法运行

chcp 65001

echo 请确保windeployqt在系统环境变量中(即mingw的bin目录在环境变量中),再执行脚本。

set /p exePath=请输入release模式下构建的exe文件路径(支持拖入),输入完后并按Enter键:

@REM echo %exePath%

windeployqt %exePath%

pause