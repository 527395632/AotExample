# 这是一个.NET AOT编译的BUG示例。复现步骤如下：

环境:
  Ubuntu24.04 (ARM64)

第一步：进入到AotExample目录 (cd AotExample)
第二部: 使用AOT发布
        dotnet publish DynamicLibrary1 -p:NativeLib=Shared -r linux-arm64 -c Release -p:PublishAot=true
        dotnet publish DynamicLibrary2 -p:NativeLib=Shared -r linux-arm64 -c Release -p:PublishAot=true

第三步: 拷贝编译动态库文件 (cp *.so)
        cp ./DynamicLibrary1/bin/Release/net8.0/publish/*.so ./bin
        cp ./DynamicLibrary2/bin/Release/net8.0/publish/*.so ./bin


第四步: 编译main.c
        cd CFiles
        gcc -o ../bin/a.out main.c -ldl

第五步: 运行测试程序
        cd ../bin
        ./a.out

![image](https://github.com/user-attachments/assets/86d4cab1-198f-4b81-b5c0-15872253fda7)
