# .login -- csh initializations which only need to be done once.
#
# Set up the terminal
#
stty erase 
stty susp 
stty intr 
stty kill 
#stty ixoff
#
set noglob
eval `tset -s -Q -m ":?$TERM"`
unset noglob

#
# Print out some info
#
w
