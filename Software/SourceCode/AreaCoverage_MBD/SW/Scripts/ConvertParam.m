all_WS = who;
for i = 1:length(all_WS)
    if ~isa(evalin('base', all_WS{i}),'Simulink.Signal')...
            && ~strcmp(all_WS{i}, 'answer')
        
    varName = all_WS{i};
    varValue = evalin('base', all_WS{i});
    varClass = evalin('base', ['class(' all_WS{i} ')']);
    if strcmp(varClass, 'logical')
        varClass = 'boolean';
    end
    evalin('base', [varName '= Simulink.Parameter']);
    evalin('base', [varName '.Value = ' num2str(varValue)]);
    evalin('base', [varName '.DataType = ''' varClass '''']);
    
    evalin('base', [varName '.CoderInfo.StorageClass = ''custom''']);
    evalin('base', [varName '.CoderInfo.CustomStorageClass = ''Define''']);
    
    
    if (length(varName) > 2 ) && strcmp(varName(1:3), 'CAL')
        evalin('base', [varName '.CoderInfo.CustomAttributes.HeaderFile = ''Params.h''']);
    elseif (length(varName) > 4 ) && strcmp(varName(1:5), 'CONST')
        evalin('base', [varName '.CoderInfo.CustomAttributes.HeaderFile = ''Constant.h''']);
    elseif (length(varName) > 2 ) && strcmp(varName(1:3), 'ENU')
        evalin('base', [varName '.CoderInfo.CustomAttributes.HeaderFile = ''Enums.h''']);
    else
        evalin('base', [varName '.CoderInfo.CustomAttributes.HeaderFile = ''MISC.h''']);
    end
    
    end
end
%     isa( 