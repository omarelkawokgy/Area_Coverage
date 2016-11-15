import os
path = os.getcwd()

#-----------creating output file if doesnt exist------#
if os.path.exists(path + "\\Main_IN_1"):
    outputFile = open(path + "\\Main_IN_1\\Main_IN_1.ino", "w")
else:
    os.makedirs(path + "\\Main_IN_1")
    outputFile = open(path + "\\Main_IN_1\\Main_IN_1.ino", "w")

#scan for .c and .h files#
headerFiles = []
sourceFiles = []
inoFiles = []
for root, dirs, files in os.walk(path):
    for name in files:
        if name.endswith(".h"):
            headerFiles.append(root +"\\" + name)
        elif name.endswith(".cpp"):
            sourceFiles.append(root + "\\" + name)
        elif name.endswith(".ino"):
            inoFiles.append(root + "\\" + name)

#--------------sorting all Header files---------------#
headerCounter = 0
tempHeaderFiles = []
for j in range(len(headerFiles)):
    tempHeaderFiles.insert(j, "")
    
for i in range(len(headerFiles)):
    if "Project_Path.h" in headerFiles[i]:
        headerCounter = 0
    elif "types.h" in headerFiles[i]:
        headerCounter = 1
    elif "CONF.h" in headerFiles[i]:
        headerCounter = 2
    elif "motor.h" in headerFiles[i]:
        headerCounter = 3
    elif "OBJD.h" in headerFiles[i]:
        headerCounter = 4
    elif "COMH.h" in headerFiles[i]:
        headerCounter = 5
    elif "ENCOD.h"  in headerFiles[i]:
        headerCounter = 6
    elif "ERRH.h"  in headerFiles[i]:
        headerCounter = 7
    elif "Main_Func_1.h" in headerFiles[i]:
        headerCounter = 8
    elif "ULSH.h" in headerFiles[i]:
        headerCounter = 9
    elif "positionHandler.h" in headerFiles[i]:
        headerCounter = 10
    elif "MOVH.h" in headerFiles[i]:
        headerCounter = 11
    elif "MapHandler.h" in headerFiles[i]:
        headerCounter = 12
    elif "RobotDevice.h" in headerFiles[i]:
        headerCounter = 13
    elif "GTSP.h" in headerFiles[i]:
        headerCounter = 14
    elif "ZGZG.h" in headerFiles[i]:
        headerCounter = 15
    elif "Scan.h" in headerFiles[i]:
        headerCounter = 16
    elif "Bluetooth.h" in headerFiles[i]:
        headerCounter = 17
    elif "SIMU.h" in headerFiles[i]:
        headerCounter = 18
    elif "Main.h" in headerFiles[i]:
        headerCounter = 19
    tempHeaderFiles[headerCounter] = headerFiles[i]

headerFiles = tempHeaderFiles

#-------------writing libraries Ino files----------------#
inoFile = open(inoFiles[1],"r")
inoLines = inoFile.readlines()

for line in inoLines:
    outputFile.write(line)
    
outputFile.write("\n")
inoFile.close()
        
#-------------writing all header files----------------#
for i in range(len(headerFiles)):
    if os.path.exists(headerFiles[i]):
        headerFile = open(headerFiles[i],"r")
        headerLines = headerFile.readlines()
        for line in headerLines:
            if "#include" in line:
                outputFile.write("")
            else:
                outputFile.write(line)
        outputFile.write("\n")
        headerFile.close()
    else:
        print(headerFiles[i] + " does not exist!")

#-----------reading all source files----------------#
for i in range(len(sourceFiles)):
    if os.path.exists(sourceFiles[i]):
        sourceFile = open(sourceFiles[i],"r")
        sourceLines = sourceFile.readlines()
        for line in sourceLines:
            if "#include" in line:
                outputFile.write("")
            else:
                outputFile.write(line)
        outputFile.write("\n")
        sourceFile.close()
    else:
        print(sourceFiles[i] + " does not exist!")

#-------------writing Main Ino files----------------#
inoFile = open(inoFiles[2],"r")
inoLines = inoFile.readlines()
for line in inoLines:
    if "#include" in line:
        outputFile.write("")
    else:
        outputFile.write(line)
outputFile.write("\n")
inoFile.close()
        
outputFile.close()




