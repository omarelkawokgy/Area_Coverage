import os
path = os.getcwd()

#-----------creating output file if doesnt exist------#
if os.path.exists(path + "\\Main_src"):
    outputFile = open(path + "\\Main_src\\Main_src.ino", "w")
else:
    os.makedirs(path + "\\Main_src")
    outputFile = open(path + "\\Main_src\\Main_src.ino", "w")

#scan for .c and .h files#
headerFiles = []
sourceFiles = []
inoFiles = []
for root, dirs, files in os.walk(path):
    for name in files:
        if name.endswith(".h"):
            headerFiles.append(root +"\\" + name)
        elif name.endswith(".c"):
            sourceFiles.append(root + "\\" + name)
        elif name.endswith(".ino"):
            inoFiles.append(root + "\\" + name)

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

outputFile.close()




