echo Compiling Shaders
D:\Softwares\Vulkan\Bin\glslc.exe Shaders\simple_shader.vert -o .\Shaders\simple_shader.vert.spv
D:\Softwares\Vulkan\Bin\glslc.exe Shaders\simple_shader.frag -o .\Shaders\simple_shader.frag.spv

if errorlevel 1 goto ERROR
   
echo Successfully compiled shaders
exit code: 0

:ERROR
echo Failed to compile shaders
exit /b 1