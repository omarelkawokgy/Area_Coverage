
TESTNUMBER = 16;
Time(1) = 0;
i = 2;
value = 1;
while(i < TESTNUMBER*2)
   Time(i) = value;
   Time(i+1) = value;
   i=i+2;
   value = value + 1;
end
Time(TESTNUMBER*2) = (TESTNUMBER);

Data(1) = 0;
i = 1;
checkCounter = 0;
Value = 0;
while(i < TESTNUMBER*2)
    if checkCounter >= 2
        if Value == 0
            Value = 1;
        else
            Value = 0;
        end
        checkCounter = 0;
    end
        Data(i) = Value;
    
    checkCounter = checkCounter + 1;
    i = i + 1;
end
Data(TESTNUMBER*2) = 1;
signalbuilder('AreaCoverageTestHarness/Signal Builder', 'set', 'RightNegPin', 1, Time, Data);   