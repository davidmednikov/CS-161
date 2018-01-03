#
# version 2016.03.09
#
# .cshrc -- initialization for each csh invoked.
# nothing here should output anything to the screen.
# if it does, things like sftp (secure ftp) will fail with some weird errors
#

if ( -f /etc/csh.cshrc ) then
    source /etc/csh.cshrc
endif

############################################################
# First we set a pretty basic path that should work on all
# OS's.  We will be pre and post-pending to it below, with
# OS-specific paths.
############################################################
set path=( /bin /sbin /usr/local/bin /usr/bin /usr/local/apps/bin )


############################################################
# some basic settings 
############################################################
set ignoreeof noclobber notify shell=$SHELL
unset autologout
umask 007
setenv LESS "QMcde"
setenv MORE "-c"
# note that OS-specific man paths are added below
setenv MANPATH /usr/local/man:/usr/man:/usr/share/man
setenv PAGER less

############################################################
# Now we add a personal bin directory and '.', which is the 
# current directory.  This would be a good place to add
# any other special directories to your path or MANPATH
############################################################
set path = ($path ~/bin .)
#setenv MANPATH {$MANPATH}:

#
if ($?prompt) then		# This is an interactive shell.
    /usr/bin/mesg n
    set filec
    set history=150
    set savehist=150
    if (! $?USER) setenv USER $LOGNAME

    limit coredumpsize 0
    setenv hostname `/bin/uname -n | /bin/awk -F. '{print $1}'`
    set prompt="$hostname \!% "
    #
    alias Make 'nice +3 make \!* >&! Make.log &'
    alias cp cp -i
    alias rm rm -i
    alias h history 20
    alias j jobs
    alias mv mv -i
    alias z suspend
    # change 'setpv' in the following line to 'setpt' for terse prompt
    # tp stands for terse prompt, vp stands for verbose prompt
    alias   setp    'setpv'
    alias   tp      'alias setp "setpt" ; setpt'
    alias   vp      'alias setp "setpv" ; setpv'
    # tcsh
    if ($?version) then 
        alias   setpt   'set prompt="%m %h%% "'
	alias   setpv   'set prompt="%m %~ %h%% "'
	setp
	# bindkey -v sets tcsh's command history to vi
	# bindkey -v
    # csh
    else
        alias   cd      'cd \!* ; setp'
	alias   popd    'popd \!* ; setp'
	alias   pushd   'pushd \!* ; setp'
	alias   setpt   'set prompt="${hostname} \\!% "'
	alias   setpv   'set prompt="${hostname} $cwd \\!% "'
	setp
    endif  # end tcsh/csh
else
    unset history
    unset savehist
endif
#
alias la ls -aF
alias lf ls -F
alias lfa ls -AF
alias ll ls -gl
alias lla ls -agl

# If you uncomment the following, you can use 'sett' to 
# add the host name to the title bar of a window.  short for 'set title'
#alias   sett 'echo -n "]1;$hostname]2;$hostname" '
