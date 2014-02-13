#!/usr/bin/sh

pics=(wallpaper/*)
x=$(( ( RANDOM % ${#pics[*]} ) + 1 ))
feh --bg-scale ${pics[$x-1]}
