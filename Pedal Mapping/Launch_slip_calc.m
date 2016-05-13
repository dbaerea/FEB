function [slip_ratio, vehicle_speed]=Launch_slip_calc(speedfl,speedfr,speedrl,speedrr)
%Calculates the wheel slip ratio
rwheel=0.254; %m

Rotspeed_front=(speedfl+speedfr)/2;
Rotspeed_rear = max(speedrl,speedrr);

vehicle_speed=Rotspeed_front*rwheel;

slip_ratio=(1-vehicle_speed/(rwheel*Rotspeed_rear));

if slip_ratio<0
    slip_ratio=0;
end

end

  
