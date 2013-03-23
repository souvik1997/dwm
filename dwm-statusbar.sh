#!/bin/zsh

# Colors

SeaBlueOnBlack="\x1"
WhiteOnBlack="\x2"
GrayOnSeaBlue="\x3"
GrayOnSoftGreen="\x4"
GrayOnSoftOrange="\x5"
GrayOnSoftRed="\x6"
MagentaOnGray="\x7"
MagentaOnMagenta="\x8"
MagentaOnSeaBlue="\x9"
MagentaOnSoftGreen="\xb"
MagentaOnSoftOrange="\xc"
MagentaOnSoftRed="\xd"
SeaBlueOnGray="\xe"
SeaBlueOnMagenta="\xf"
SeaBlueOnSeaBlue="\x10"
SeaBlueOnSoftGreen="\x11"
SeaBlueOnSoftOrange="\x12"
SeaBlueOnSoftRed="\x13"
SoftGreenOnGray="\x14"
SoftGreenOnMagenta="\x15"
SoftGreenOnSeaBlue="\x16"
SoftGreenOnSoftGreen="\x17"
SoftGreenOnSoftOrange="\x18"
SoftGreenOnSoftRed="\x19"
SoftOrangeOnGray="\x1a"
SoftOrangeOnMagenta="\x1b"
SoftOrangeOnSeaBlue="\x1c"
SoftOrangeOnSoftGreen="\x1d"
SoftOrangeOnSoftOrange="\x1e"
SoftOrangeOnSoftRed="\x1f"
SoftRedOnGray="\x21"
SoftRedOnMagenta="\x22"
SoftRedOnSeaBlue="\x23"
SoftRedOnSoftGreen="\x24"
SoftRedOnSoftOrange="\x25"
SoftRedOnSoftRed="\x26"
BlackOnSeaBlue="\x27"
combine(){
	echo -e "$SeaBlueOnBlack`separator`$GrayOnSeaBlue \u00C7 `uname -r` $GrayOnSeaBlue`separator`$MagentaOnGray \u00C3 `bat` $SeaBlueOnGray`separator`$GrayOnSeaBlue \u00D0 `netstats_down` \u00d1 `netstats_up` $GrayOnMagenta`separator`$MagentaOnGray \u00DE `mem` $SeaBlueOnGray`separator`$GrayOnSeaBlue \u00C5 `hdd` $GrayOnSeaBlue`separator`$MagentaOnGray \u00D4 `volume` $SoftGreenOnGray`separator`$GrayOnSoftGreen`mpd`$SeaBlueOnSoftGreen`separator`$GrayOnSeaBlue `coretemp` $GrayOnSeaBlue`separator`$MagentaOnGray `dte`"
}
volume(){
	echo `amixer get Master | tail -1 | awk '{print $4}' | sed -e 's/\[//g' | sed -e 's/\]//g'`
    }
mpd()
{
        a=`mpc status`
        nowplaying=`echo $a | sed -n 1p | cut -c1-29`
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
	echo -e "\u00DC"
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
