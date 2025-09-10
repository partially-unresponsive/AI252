#!/bin/bash

OLDVER="$(cat LASTVER.txt)"

rm index.html
wget https://fcim.utm.md/procesul-de-studii/orar/#toggle-id-1 > /dev/null

CURRVER="$(cat index.html | grep "pdf" | grep "Anul_I_S" | grep -oP "(\d{2})\.pdf" | grep -oP "(\d{2})")"
echo $CURRVER > LASTVER.txt

if [[ "$CURRVER" == "$OLDVER" ]]; then
	echo "Nothing new." 
else
	echo "[WARNING]: CLASS SCHEDULE CHANGED TO VERSION $CURRVER"
fi
