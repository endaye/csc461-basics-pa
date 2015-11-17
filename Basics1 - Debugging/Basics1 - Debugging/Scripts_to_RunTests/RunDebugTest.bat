cd ..\Debug

echo Debug Tests > foo.txt
Test_1.exe >> foo.txt
Test_2.exe >> foo.txt
Test_3.exe >> foo.txt
Test_4.exe >> foo.txt
Test_5.exe >> foo.txt
Test_6.exe >> foo.txt
Test_7.exe >> foo.txt
Test_8.exe >> foo.txt
Test_9.exe >> foo.txt
Test_10.exe >> foo.txt
copy foo.txt DebugResults.txt
del foo.txt