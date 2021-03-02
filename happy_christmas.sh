RED='\033[0;31m'
GRE='\033[0;32m'
BLU='\033[1;34m'
LGR='\033[1;92m'
YEL='\033[1;93m'
PUR='\033[1;95m'
WHI='\033[1;37m'
BWHI='\033[0;47m'
BLK='\033[0;90m'
BL_BACK='\033[0;33m'
NC='\033[0m' # No Color

declare -i GP=4
declare -i LGP=7
declare -i RP=8
declare -i YP=10
//printf "     ${PUR}To. ${BLU}$LOGNAME${NC}\n"
printf "     ${PUR}To. ${BLU}5MiDong${NC}\n"
printf "\n"
printf "              ${YEL}MERRY 42 CHRISTMAS\n"

for ((y=0;y<=21;y++));
do
	for ((x=0;x<=42;x++));
	do
		declare -i l=21-$y
		declare -i r=21+$y
		if [ $x -ge $l ]&&[ $x -le $r ]
		then
			declare -i rand=RANDOM%10
			if [ $y -eq 0 ]&&[ $x -eq 21 ]
			then
				printf "${PUR}◆"
			elif [ $rand -le $GP ]
			then
				printf "${GRE}<"
			elif [ $rand -le $LGP ]
			then
				printf "${LGR}>"
			elif [ $rand -le $RP ]
			then
				printf "${RED}o"
			elif [ $rand -le $YP ]
			then
				printf "${YEL}*"
			fi
		else
			declare -i rand=RANDOM%10
			if [ $rand -le 1 ]
			then
				printf "${WHI}˚"
			else
				printf " "
			fi
		fi
	done
	echo ""
done
printf "${BL_BACK}                 |       |\n"
printf "${BL_BACK}                 |       |\n"
printf "${BL_BACK}                 |       |\n"
printf "${BL_BACK}-  ---  -  --- - |       |   -  --    -    -\n"
