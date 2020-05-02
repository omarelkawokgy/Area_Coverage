if isa(logsout, 'Simulink.SimulationData.Dataset')
    
for i = 1:logsout.numElements
    if isa(logsout.getElement(i).Values.Data, 'logical')
        data = double(logsout.getElement(i).Values.Data);
    else
        data = logsout.getElement(i).Values.Data;
    end
signalbuilder('COMH_Test/Signal_Builder','appendsignal'...
    ,logsout.getElement(i).Values.Time,...
    data,...
    logsout.get(i).PropagatedName);
end
else
    error('wrong logsout object type');
end

