% Push Libraries and Lock Library Links 
% choose main component subsystem and run the script
function LockLinksLibraries(swcName)
pathName = swcName;
blocks = find_system(pathName,'FollowLinks','on','LookUnderMasks','on','LinkStatus','inactive');
for i=length(blocks):-1:1
    set_param(blocks{i},'LinkStatus','propagate');
    libraryBlockHandle = get_param(blocks{i}, 'Handle');
    block = get(libraryBlockHandle);
    libraryName = bdroot(block.ReferenceBlock);
    set_param(libraryName, 'LockLinksToLibrary', 'on')
    save_system(libraryName);
    close_system(libraryName);
end





ModelName=swcName;

Time = {char(datetime('now'))};
DateHour=char(datetime('now'));
DateHourSplit=split(DateHour,' ');
DateHourSplitdash=split(DateHourSplit{1},'-');
DateDay=[DateHourSplitdash{1} DateHourSplitdash{2} DateHourSplitdash{3}];
ExcelSheetLocation = [pwd '\lockLibraryLinks_' ModelName '_' DateDay '.xlsx'];
DataTitles = {'Locked Libraries','Time'};
Description = {'Push, Lock, Save, Close Modules Libraries within a component and Lock Library Links for PTR final package delivery'};
xlswrite(ExcelSheetLocation,Description,'LogSheet','A1');
xlswrite(ExcelSheetLocation,DataTitles,'LogSheet','A3');

if ~isempty(blocks)
    xlswrite(ExcelSheetLocation,blocks,'LogSheet','A5');
end
xlswrite(ExcelSheetLocation,Time,'LogSheet','B5');




info = Simulink.MDLInfo(ModelName);
BlockDiagramName=info.BlockDiagramName;
ModelVersion=info.ModelVersion;
Info_Out={['Model Name: ' BlockDiagramName] [ '> Version: ' ModelVersion]};
xlswrite(ExcelSheetLocation,Info_Out,'LogSheet','A2');

hExcel = actxserver('Excel.Application');
hWorkbook = hExcel.Workbooks.Open(ExcelSheetLocation);
hWorksheet = hWorkbook.Sheets.Item(2);
hWorksheet.Columns.Item(1).columnWidth = 170; %first column
hWorksheet.Columns.Item(2).columnWidth = 20; %second column
hWorkbook.Save
hWorkbook.Close
hExcel.Quit