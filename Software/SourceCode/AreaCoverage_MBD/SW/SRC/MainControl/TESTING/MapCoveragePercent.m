function MapCoveragePercent(room)
counterCov = 0;
counterBusy = 0;
counterAll = length(room(1,:)) * length(room(:,1));
for row = 1:length(room(1,:))
    for col = 1:length(room(:,1))
        if(room(row, col) == 1)
            counterCov = counterCov + 1;
        elseif (room(row, col) == 0)
            counterBusy = counterBusy + 1;
        end
    end
end
disp(['Cleaned Area Percent: ' num2str((counterCov / (counterAll - counterBusy)) * 100)]);
disp(['Busy Area Percent: ' num2str((counterBusy / counterAll) * 100)]);
end