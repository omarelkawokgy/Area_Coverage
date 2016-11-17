REM Delete first line in file and saves to new file
more +1 "Main_src\Project_Path.h" > "Main_src\Project_Path_new.h"

REM delete file 
del Main_src\Project_Path.h

REM for replacing first line of file we do it using temp .h file
echo.#define PROJECT_ROOT %cd%\Headers >> "Main_src\one_line_file.h"
type Main_src\Project_Path_new.h >> Main_src\one_line_file.h
type Main_src\one_line_file.h > Main_src\Project_Path_new.h

REM rename the file to the original name
ren Main_src\Project_Path_new.h Project_Path.h

REM delete the file
del Main_src\one_line_file.h

REM PAUSE