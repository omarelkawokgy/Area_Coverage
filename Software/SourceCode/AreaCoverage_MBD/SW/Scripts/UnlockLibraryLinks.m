%% in order to use this m file, select the main subsystem first, so its reflected as path within the model in pathName

%Unlock Library links to do PTR requirments modifications  
function blocks = UnlockLibraryLinks(componentPath)

pathName = componentPath;
blocks = find_system(pathName,'SearchDepth',3,'FollowLinks','on','LookUnderMasks','on','LinkStatus','resolved');
for i=1:length(blocks)
    set_param(blocks{i},'LinkStatus','inactive');
end


ModelName=split(gcs,'/');
ModelName=ModelName{1};

Time = {char(datetime('now'))};
DateHour=char(datetime('now'));
DateHourSplit=split(DateHour,' ');
DateHourSplitdash=split(DateHourSplit{1},'-');
DateDay=[DateHourSplitdash{1} DateHourSplitdash{2} DateHourSplitdash{3}];
ExcelSheetLocation = [pwd '\UnlockLibraryLinks_' ModelName '_' DateDay '.xlsx'];


DataTitles = {'Unlocked Libraries','Time'};
Description = {'Automatically Unlock Modules Library links within a SWC to do PTR requirments modifications'};


info = Simulink.MDLInfo(ModelName);
BlockDiagramName=info.BlockDiagramName;
ModelVersion=info.ModelVersion;
Info_Out={['Model Name: ' BlockDiagramName] [ '> Version: ' ModelVersion]};
xlswrite(ExcelSheetLocation,Info_Out,'LogSheet','A2');

xlswrite(ExcelSheetLocation,Description,'LogSheet','A1');
xlswrite(ExcelSheetLocation,DataTitles,'LogSheet','A3');
if ~isempty(blocks)
xlswrite(ExcelSheetLocation,blocks,'LogSheet','A5');
end
xlswrite(ExcelSheetLocation,Time,'LogSheet','B5');
hExcel = actxserver('Excel.Application');
hWorkbook = hExcel.Workbooks.Open(ExcelSheetLocation);
hWorksheet = hWorkbook.Sheets.Item(2);
hWorksheet.Columns.Item(1).columnWidth = 170; %first column
hWorksheet.Columns.Item(2).columnWidth = 20; %second column
hWorkbook.Save
hWorkbook.Close
hExcel.Quit