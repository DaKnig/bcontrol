# bcontrol
controls the brightness on linux machines with xrandr

it will **not** save your battery on laptops. 

compiled with gcc version 5.4.0 20160609 

# usage
just type "bcontrol _percent_" or "bcontrol +_percent_" or "bcontrol -_percent_"

for example- 

bcontrol 50
will make the screen brightness half the max brightness


_percent_ is capped at 100 and 5 because lower then 5% you cant see anything...
