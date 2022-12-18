gcc -Wall -o release/hello.exe hello.c -lallegro -lallegro_font

cp /c/msys64/ucrt64/bin/allegro-5.2.dll release/
cp /c/msys64/ucrt64/bin/allegro_font-5.2.dll release/
cp /c/msys64/ucrt64/bin/libgcc_s_seh-1.dll release/
cp /c/msys64/ucrt64/bin/libstdc++-6.dll release/
cp /c/msys64/ucrt64/bin/libwinpthread-1.dll release/
