# ImageProcessing


### To run application
1. Go to build-ImgProc-Desktop_Qt_6_4_1_MSVC2019_64bit-Release\release
2. Run ImgProc.exe
3. use images/ for loading and saving images

### Or directly from Qt Creator IDE
1. Go to ImgProc and open ImgProc.pro in Qt Creator.
2. Enable MSVC 2019 64 bit build.
3. Ensure you've installed the OpenCV library and set DLLs as user path as so below. If your paths are different, verify with your install folder. 
	
	C:\Qt\6.4.1\msvc2019_64\bin
	
	C:\Program Files (x86)\opencv\build\x64\vc15\bin
	
	C:\Program Files (x86)\opencv\build\x64\vc14\bin
	
4. Click Build icon on the bottom left.

### To use application
1. Browse to load image file
2. Click Load
3. Click View Original Image, which opens the image in a new window
4. Select operations by clicking the checkable box and adding custom values for the operations. If your input is not the correct format, you will see an error.
5. Click View New Image to see the operations and Save Image to save image to /images folder.
6. If you want to apply new set of operations, click Clear to remove all the previous processes. Otherwise, processes will stack on the previous run.
