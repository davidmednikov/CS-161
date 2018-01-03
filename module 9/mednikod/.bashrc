# bashrc

# version 2016.03.09

# .bashrc -- initialization for each bash shell invoked.
# nothing here should output anything to the screen.
# if it does, things like sftp (secure ftp) will fail with some weird errors

# this is a pretty bare-bones .bashrc.  We don't really support bash;
# we mainly want to make sure the shell is halfway functional.  You can
# make it spiffy and pretty. :-)  If you have suggestions for some fundamental
# settings here, mail support@engr.orst.edu.   thx

if [ -f /etc/bashrc ]; then
    . /etc/bashrc
fi

############################################################
# First we set a pretty basic path that should work on all
# OS's.  We will be pre and post-pending to it below, with
# OS-specific paths.
############################################################
export PATH=/bin:/sbin:/usr/local/bin:/usr/bin:/usr/local/apps/bin
export MANPATH=/usr/local/man:/usr/man:/usr/share/man
export LESS="QMcde"
export MORE="-c"
export PAGER=less
umask 007

############################################################
# Now we add a personal bin directory and '.', which is the
# current directory.  This would be a good place to add
# any other special directories to your path or MANPATH
############################################################
export PATH=$PATH:~/bin:.
#export MANPATH=$MANPATH:

alias cp="cp -i"
alias rm="rm -i"
alias mv="mv -i"
alias z="suspend"
alias la="ls -aF"
alias lf="ls -F"
alias lfa="ls -AF"
alias ll="ls -gl"
alias lla="ls -agl"

# Interactive shell
if [ "$PS1" ]; then
    # Set prompt to be more familiar
    PS1="\h \w \!$ "
fi
