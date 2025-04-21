# 安装git
## Windows
### 检查是否安装git
```shell
    git --version
```
如果未安装，以管理员身份运行PowerShell并依次执行
```shell
    winget install --id Git.Git -e --source winget
    $env:Path
    [Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\Program Files\Git\bin;C:\Program Files\Git\cmd", [EnvironmentVariableTarget]::Machine)
```
关闭重新运行终端

# 仓库创建并连接
```shell
    git init
    git remote add origin https://github.com/yo-wow/big-talk-data-structure.git
    git push -u origin main
```