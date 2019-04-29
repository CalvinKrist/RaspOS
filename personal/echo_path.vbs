' Get a docker compatable file path in the format of /c/Users/RaspOS/personal
' Load in current file path in Windows formatting
Dim curPath 
curPath = CreateObject("Scripting.FileSystemObject").GetAbsolutePathName(".") 

' Use the Repalce functionality to convert to a Docker file path
curPath = Replace(curPath,"\","/")
curPath = Replace(curPath,"C:","/c")
curPath = Replace(curPath,"D:","/d")

' Echo file path to a temp file
Set shell = CreateObject ("WScript.Shell") 
shell.run "cmd.exe /c echo " + curPath + ":/app > path.tmp"
