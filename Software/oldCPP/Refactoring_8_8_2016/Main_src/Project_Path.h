#ifndef PROJECT_PATH_H
#define PROJECT_PATH_H

#define PROJECT_ROOT C:\Users\oelkawok\Downloads\Area_Coverage-master\OMO_ADUINO_IDE\Headers
#define TO_STRING(s) #s
#define ABSOLUTE_PATH(root, relative_path) TO_STRING(root\relative_path)
#define RELATIVE_PATH(library) ABSOLUTE_PATH(PROJECT_ROOT, library)

#endif