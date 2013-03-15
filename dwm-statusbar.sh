#!/bin/zsh


volume(){
	echo `amixer get Master | tail -1 | awk '{print $4}' | sed -e 's/\[//g' | sed -e 's/\]//g'`
    }
mpd()
{
        a=`mpc status`
        nowplaying=`echo $a | sed -n 1p | cut -c1-14`
        play=`echo $a | sed -n 2p | awk '{print $1}'`
        if [ -n "$a" ]
        then
                echo " $play $nowplaying"
        else
                echo ""
        fi
}

bat(){
        ac=`acpi -V | awk 'NR==1 {print +$4}'`
        onl=`acpi -V | grep "on-line" `
        if [ -z "$onl" ] && [ "$ac" -gt "15" ]; then
                echo -e "BAT $ac%"
        elif [ -z "$onl" ] && [ "$ac" -le "15" ]; then
                echo -e "BAT $ac%"
        else
                echo -e "AC $ac%"
        fi
}
mem(){
        #mem="$(awk '/^-/ {print $3}' <(free -m))"
	mem=`free -m | awk '/-\/+/ {print $3}'`
        echo -e "$mem MB"
}
hdd(){
        #hd="$(df -P | sort -d | awk '/^\/dev\/ma|sdc/{s=s (s?" ":"") $5} END {printf "%s", s}')"
	hd=`df -P | awk '/Used/ {getline;print $5}'`

        echo -e "$hd"
}

dte(){
	dte=`date '+%m/%d/%y %H:%M'`
        #dte="$(date "+%I:%M")"
        echo -e "$dte"
}
coretemp()
{

	temp=`sensors | awk '/Physical/ {print $4}' | sed -e 's/[\+|°|C]//g' | sed -e 's/\..//g' `
	echo -e "\u00DF $temp"
}
netstats_down()
{
	echo -e `ifconfig wlan0 | awk '/RX packets/{print $6 $7}' | sed -e 's/[(|)]//g'`
}
netstats_up()
{
	echo -e `ifconfig wlan0 | awk '/TX packets/{print $6 $7}' | sed -e 's/[(|)]//g'`
}
separator(){
	echo -e "\x13<"
}	
combine(){
	echo -e "\x03\u00C7 `uname -r` `separator`\x06 \u00C3 `bat` `separator` \x0B\u00D0 `netstats_down` \u00d1 `netstats_up` `separator` \x07\u00DE `mem` `separator` \x0E\u00C5 `hdd` `separator` \x11\u00D4 `volume``mpd` `separator` \x09`coretemp` `separator` \x12`dte`"
}
if [ ! -n "$1" ] #testing purposes
then
while true; do
xsetroot -name "`combine`"
wait
sleep 10
done
#xsetroot -name `echo -ne "\u00CF"`
else
echo "$(combine)"
fi
