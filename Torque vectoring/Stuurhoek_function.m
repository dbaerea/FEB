function [ SAC ] = Stuurhoek_function( SAS )
%Stuurhoek_function: omrekening van de lineaire verplaatsing naar de
%stuurhoeken.

while 1
if SAS <= 42 
    SAC = Links;
end
if (SAS > 42) && (SAS < 58)
    SAC = Rechtdoor;
end
if SAS >= 58
    SAC = Rechts;
end
end


end

