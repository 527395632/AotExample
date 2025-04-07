# 这是一个.NET AOT编译的BUG示例: https://github.com/dotnet/runtime/issues/114193
# 复现步骤如下：

# 环境: Ubuntu24.04 (ARM64)

# 第一步：进入到AotExample目录
        cd AotExample
        
# 第二部: 使用AOT发布
        dotnet publish DynamicLibrary1 -p:NativeLib=Shared -r linux-arm64 -c Release -p:PublishAot=true
        dotnet publish DynamicLibrary2 -p:NativeLib=Shared -r linux-arm64 -c Release -p:PublishAot=true

# 第三步: 编译main.c
        cd CFiles
        gcc -o a.out main.c -ldl

# 第四步: 运行测试程序
        cd ../bin
        cp ../DynamicLibrary1/bin/Release/net8.0/linux-arm64/publish/*.so ./
        cp ../DynamicLibrary2/bin/Release/net8.0/linux-arm64/publish/*.so ./
        cp ../CFiles/a.out ./
        ./a.out

![image](https://github.com/user-attachments/assets/2b33e87c-e288-45c6-8db9-70365bf734aa)
