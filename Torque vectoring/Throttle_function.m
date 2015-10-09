function [ output_args ] = Throttle_function( TS )
%Regen_on_throttle
%   Function for calculating the difference between two measurements of the
%   throttle sensor and then comparing that value with a preset value for
%   when the braking/regen should start.
 
%Declaration of the variables used in the function.
TS1 = 0;      %Current throttle measurement
TS2 = 0;      %Previous throttel measurement
THR_R = 50;   %Threshold value
 
%Infinite loop where the current measurement is compared with the previous
%one and then (only if its lower than the previous one) compared with the
%preset threshold value for when regen should activate
while(1)
    TS1= TS;
    if TS1 > TS2
        then accelerate
    else
        if TS1 < THR_R
            then brake/activate regen
        else
            Do nothing
        end
    end
 
end
 

